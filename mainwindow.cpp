#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphgraphicsview.h"
#include "graphutils.h"
#include "inputdialog.h"
#include <QtGui>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include "qdebugstream.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->setStyleSheet("color: darkgrey");
    ui->console_text->setReadOnly(true);

    this->dataNeedSaving = false;
    this->setWindowTitle("Simple Graph Tool");
    QSignalMapper *m = new QSignalMapper(this);
    QShortcut *s1 = new QShortcut(QKeySequence("Alt+1"), this);
    QShortcut *s2 = new QShortcut(QKeySequence("Alt+2"), this);
    connect(s1, SIGNAL(activated()), m, SLOT(map()));
    connect(s2, SIGNAL(activated()), m, SLOT(map()));
    m->setMapping(s1, 0);
    m->setMapping(s2, 1);
    connect(m, SIGNAL(mapped(int)), ui->tabWidget, SLOT(setCurrentIndex(int)));
    QFont btnFont; btnFont.setPixelSize(18);
    ui->createGraphButton->setFont(btnFont);
    ui->openGraphButton->setFont(btnFont);

    ui->propertiesTable->setSizeAdjustPolicy(QTableWidget::AdjustToContents);
    ui->propertiesTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->propertiesTable->verticalHeader()->setDefaultSectionSize(24);

    this->graph = new Graph();
    this->scene = new GraphGraphicsScene(graph);
    this->view = new GraphGraphicsView();
    this->matrix = new GraphMatrixTable(graph);

    connect(matrix, SIGNAL(graphChanged()), scene, SLOT(reloadData()));
    connect(scene, SIGNAL(graphChanged()), matrix, SLOT(reloadData()));
    connect(this, SIGNAL(graphChanged()), scene, SLOT(reloadData()));
    connect(this, SIGNAL(graphChanged()), matrix, SLOT(reloadData()));
    connect(this, SIGNAL(graphChanged()), view, SLOT(redraw()));
    connect(this, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));
    connect(matrix, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));
    connect(scene, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));

    connect(view, &GraphGraphicsView::addNewNode, this, [this](QPointF pos){
        showNewNodeDialog(pos);
    });
    connect(view, &GraphGraphicsView::removeNode, this, [this](int id) {
        if (this->graph->removeNode(id))
            emit graphChanged();
    });
    connect(view, &GraphGraphicsView::isolateNode, this, [this](int id) {
        if(this->graph->isolateNode(id))
            emit graphChanged();
    });
    connect(view, &GraphGraphicsView::removeArc, this, [this](int u, int v) {
        if (graph->removeArc(u, v))
            emit graphChanged();
    });
    connect(view, &GraphGraphicsView::setArc, this, [this](int u, int v) {
        bool ok{};
        int defaultValue = graph->hasThisArc(u, v)? graph->getArcWeight(u, v) : 1;
        int w = QInputDialog::getInt(this, tr("Set weight for arc(")
                                              + QString::fromStdString(graph->getNodeName(u)) + ", "
                                              + QString::fromStdString(graph->getNodeName(v)) + tr(")"),
                                     "0 <= weight < " + QString::number(INT_MAX),
                                     defaultValue, 1, INT_MAX, 1, &ok);
        if (ok && this->graph->setArc(u, v, w))
            emit graphChanged();
    });
    connect(view, &GraphGraphicsView::startAlgorithm, this, [this](QString algo, int id) {
        GraphUtils graph_utils;
        QDebugStream qout(std::cout, ui->console_text);
        if (algo == "BFS") {
            this->ui->console_text->clear();
            std::list<std::pair<int, int>> res = graph_utils.BfsToDemo(*(this->graph), id);
            emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
        }
        else if (algo == "DFS") {
            this->ui->console_text->clear();
            std::list<std::pair<int, int>> res = graph_utils.DfsToDemo(*(this->graph), id);
            emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
        }
        else if (algo == "Find path") {
            bool ok;
            QString goal = QInputDialog::getText(this, "Find shortest path", "To node: ",QLineEdit::Normal, QString(), &ok);
            if (ok) {
                if (goal.isNull())
                    return;
                int toId = this->graph->findNodeIdByName(goal.toStdString());
                if (!this->graph->hasThisNode(toId)) {
                    QMessageBox::critical(this, "Error", tr(":waNo node named ") + goal);
                    return;
                }
                this->ui->console_text->clear();
                qDebug() << graph_utils.isConnectedFromUtoV(*graph, id, toId);
                std::list<int> res = graph_utils.Dijkstra(*(this->graph), id, toId);
                emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
            }
        }
    });
    connect(view, &GraphGraphicsView::editNode, this, [this](int id) {
        bool ok;
        QRegExp re("[a-zA-Z0-9]{1,3}");
        QString newNodeName = QInputDialog::getText(this, "Add new node", "Name: ", QLineEdit::Normal, QString(), &ok);
        if (ok) {
            if (!re.exactMatch(newNodeName)) {
                QMessageBox::critical(this, "Error", tr("Node's name contains only alphabetical or numeric characters\n")
                                      + tr("Length of the name mustn't be greater than 3 or smaller than 1"));
                return;
            }
            if (this->graph->hasThisNode(newNodeName.toStdString()))
                QMessageBox::critical(this, "Error", "This name has been used by another node");
            else {
                this->graph->getNode(id)->setName(newNodeName.toStdString());
                emit graphChanged();
            }
        }
    });
    connect(view, &GraphGraphicsView::unSelect, this, [this]() {
        QAbstractItemModel* const mdl = this->ui->propertiesTable->model();
        mdl->removeRows(0,mdl->rowCount());
        mdl->removeColumns(0,mdl->columnCount());
    });
    connect(view, &GraphGraphicsView::selectedNode, this, [this](int id) {
        QAbstractItemModel* const mdl = this->ui->propertiesTable->model();
        mdl->removeRows(0,mdl->rowCount());
        mdl->removeColumns(0,mdl->columnCount());
        QStringList tableHeader;
        tableHeader << tr("ID") << tr("Name") << tr("Positive degree") << tr("Negative degree");
        this->ui->propertiesTable->setRowCount(4);
        this->ui->propertiesTable->setColumnCount(1);
        this->ui->propertiesTable->setVerticalHeaderLabels(tableHeader);

        this->ui->propertiesTable->setItem(0, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(0, 0)->setText(QString::number(id));
        this->ui->propertiesTable->item(0,0)->setFlags(Qt::ItemIsEnabled);

        this->ui->propertiesTable->setItem(1, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(1, 0)->setText(QString::fromStdString(this->graph->getNodeName(id)));
        this->ui->propertiesTable->item(1,0)->setFlags(Qt::ItemIsEnabled);

        this->ui->propertiesTable->setItem(2, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(2, 0)->setText(QString::number(this->graph->getNode(id)->getPositiveDeg()));
        this->ui->propertiesTable->item(2, 0)->setFlags(Qt::ItemIsEnabled);

        this->ui->propertiesTable->setItem(3, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(3, 0)->setText(QString::number(this->graph->getNode(id)->getNegativeDeg()));
        this->ui->propertiesTable->item(3, 0)->setFlags(Qt::ItemIsEnabled);
    });

    connect(matrix, &GraphMatrixTable::selectedArc, this, [this](int u, int v) {
        QAbstractItemModel* const mdl = this->ui->propertiesTable->model();
        mdl->removeRows(0,mdl->rowCount());
        mdl->removeColumns(0,mdl->columnCount());
        QStringList tableHeader;
        tableHeader << tr("From node") << tr("To node") << tr("Weight");
        this->ui->propertiesTable->setRowCount(3);
        this->ui->propertiesTable->setColumnCount(1);
        this->ui->propertiesTable->setVerticalHeaderLabels(tableHeader);

        this->ui->propertiesTable->setItem(0, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(0, 0)->setText(QString::fromStdString(this->graph->getNodeName(u)));
        this->ui->propertiesTable->item(0,0)->setFlags(Qt::ItemIsEnabled);

        this->ui->propertiesTable->setItem(1, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(1, 0)->setText(QString::fromStdString(this->graph->getNodeName(v)));
        this->ui->propertiesTable->item(1, 0)->setFlags(Qt::ItemIsEnabled);

        this->ui->propertiesTable->setItem(2, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(2, 0)->setText((this->graph->getArcWeight(u, v) != INT_MAX)?
                                                               QString::number(this->graph->getArcWeight(u, v))
                                                             : "inf");
        this->ui->propertiesTable->item(2, 0)->setFlags(Qt::ItemIsEnabled);
    });

    connect(view, &GraphGraphicsView::selectedArc, this, [this](int u, int v) {
        QAbstractItemModel* const mdl = this->ui->propertiesTable->model();
        mdl->removeRows(0,mdl->rowCount());
        mdl->removeColumns(0,mdl->columnCount());
        QStringList tableHeader;
        tableHeader << tr("From node") << tr("To node") << tr("Weight");
        this->ui->propertiesTable->setRowCount(3);
        this->ui->propertiesTable->setColumnCount(1);
        this->ui->propertiesTable->setVerticalHeaderLabels(tableHeader);

        this->ui->propertiesTable->setItem(0, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(0, 0)->setText(QString::fromStdString(this->graph->getNodeName(u)));
        this->ui->propertiesTable->item(0,0)->setFlags(Qt::ItemIsEnabled);

        this->ui->propertiesTable->setItem(1, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(1, 0)->setText(QString::fromStdString(this->graph->getNodeName(v)));
        this->ui->propertiesTable->item(1, 0)->setFlags(Qt::ItemIsEnabled);

        this->ui->propertiesTable->setItem(2, 0, new QTableWidgetItem());
        this->ui->propertiesTable->item(2, 0)->setText((this->graph->getArcWeight(u, v) != INT_MAX)?
                                                               QString::number(this->graph->getArcWeight(u, v))
                                                             : "inf");
        this->ui->propertiesTable->item(2, 0)->setFlags(Qt::ItemIsEnabled);
    });

    connect(this, SIGNAL(startAlgorithm(std::list<std::list<int> >,GraphDemoFlag)), scene, SLOT(doAlgorithm(std::list<std::list<int> >,GraphDemoFlag)));
    connect(this, SIGNAL(startAlgorithm(std::list<int>,GraphDemoFlag)), scene, SLOT(doAlgorithm(std::list<int>,GraphDemoFlag)));
    connect(this, SIGNAL(startAlgorithm(std::list<std::pair<int,int> >,GraphDemoFlag)), scene, SLOT(doAlgorithm(std::list<std::pair<int,int> >,GraphDemoFlag)));

    ui->table_layout->addWidget(matrix, 1, Qt::AlignTop);
    view->setScene(scene);
    ui->draw_layout->addWidget(view);
    view->show();
    setWorkspaceEnabled(false);
}

void MainWindow::initWorkspace(QString filename, bool newfile) {

    try {
        if (!newfile) {
            graph->readFromFile(filename.toStdString());
            this->dataNeedSaving = false;
        }
        else {
            this->dataNeedSaving = true;
            bool okpressed = false;
            int n = QInputDialog::getInt(this, "Initialize graph with nodes",
                                         "Maximum 26 nodes that can be automatically generated",
                                         0, 0, 26, 1, &okpressed);
            if (!okpressed) return;
            graph->init(n);
        }
        emit graphChanged();
    }
    catch(...) {
        setWorkspaceEnabled(false);
        QMessageBox::critical(this, "Error",
                              "Something is wrong with this file",
                              QMessageBox::Cancel);
        if (workingFileName != "") setWorkspaceEnabled(true);
        return;
    }
    this->workingFileName = filename;
    int index = filename.toStdString().find_last_of("/\\");
    std::string input_trace_filename = filename.toStdString().substr(index+1);
    setWindowTitle(QString::fromStdString(input_trace_filename) + " - Simple Graph Tool");
    setWorkspaceEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete graph;
    delete scene;
    delete view;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (dataNeedSaving) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Save Graph?",
                              "Your changes will be lost if you don't save them!",
                              QMessageBox::No|QMessageBox::Yes|QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
            graph->writeToFile(workingFileName.toStdString());
        else if (reply == QMessageBox::Cancel)
            event->ignore();
    }
}

QString MainWindow::showOpenFileDialog() {
    return QFileDialog::getOpenFileName(
                this,
                tr("Open Document"),
                QDir::currentPath(),
                tr("Graph files (*.gph)"),
                0,
                QFileDialog::DontUseNativeDialog);
}

QString MainWindow::showSaveFileDialog()
{
     QString newfilename;
    for (int i = 1; true; i++) {
        std::ifstream is(QDir::currentPath().toStdString()
                         + "/graph" + std::to_string(i) + ".gph");
        if (!is.good()) {
            newfilename = QString::fromStdString(QDir::currentPath().toStdString()
                         + "/graph" + std::to_string(i) + ".gph");
            break;
        }
    }
    return QFileDialog::getSaveFileName(this, tr("New Graph"),
                                        newfilename,
                                        tr("Graph files (*.gph)"),
                                        0,
                                        QFileDialog::DontUseNativeDialog);
}

void MainWindow::showNewNodeDialog(QPointF pos)
{
    bool ok;
    QRegExp re("[a-zA-Z0-9]{1,3}");
    QString newNodeName = QInputDialog::getText(this, "Add new node", "Name: ", QLineEdit::Normal, QString(), &ok);
    if (ok) {
        if (!re.exactMatch(newNodeName)) {
            QMessageBox::critical(this, "Error", tr("Node's name contains only alphabetical or numeric characters\n")
                                  + tr("Length of the name mustn't be greater than 3 or smaller than 1"));
            return;
        }
        Node newNode(newNodeName.toStdString());
        newNode.setEuclidePos(pos);
        bool succeeded = graph->addNode(newNode);
        if (!succeeded)
            QMessageBox::critical(this, "Error", "This name has been used by another node");
        else
            emit graphChanged();
    }
}

void MainWindow::setWorkspaceEnabled(bool ready)
{
    if (ready) ui->entry_widget->setVisible(false);
    ui->working_widget->setVisible(ready);
    ui->menuGraph->setEnabled(ready);
    ui->menuAlgorithms->setEnabled(ready);
    foreach (QAction *action, ui->menuFile->actions())
        if (!action->menu() && !action->isSeparator()
                && action->text().contains("Save"))
            action->setEnabled(ready);
    if (ready)
       view->scale(1, 1);
}

void MainWindow::onGraphChanged()
{
    this->dataNeedSaving = true;
    ui->statusBar->clearMessage();
    ui->console_text->clear();
}

void MainWindow::on_createGraphButton_clicked()
{
    QString filename = showSaveFileDialog();
    if (!filename.isNull())
        initWorkspace(filename, true);
}

void MainWindow::on_openGraphButton_clicked()
{
   QString filename = showOpenFileDialog();
   if (!filename.isNull())
       initWorkspace(filename);
}

void MainWindow::on_actionSave_triggered()
{
    if (dataNeedSaving) {
        this->dataNeedSaving = false;
        graph->writeToFile(workingFileName.toStdString());
        ui->statusBar->showMessage("Saving succeeded");
        QTimer::singleShot(2000, this, [this]() {
            this->ui->statusBar->clearMessage();
        });
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    QString filename = showSaveFileDialog();
    if (!filename.isNull())
        graph->writeToFile(filename.toStdString());
}

void MainWindow::on_actionNew_Graph_triggered()
{
    QString filename = showSaveFileDialog();
    if (!filename.isNull())
        initWorkspace(filename, true);
}

void MainWindow::on_actionOpen_Graph_triggered()
{
    QString filename = showOpenFileDialog();
    if (!filename.isNull() && filename != workingFileName)
        initWorkspace(filename);
}

void MainWindow::on_actionCredits_triggered()
{
    QMessageBox::about(this, "Credit", "Author: Hao Phan Phu - KHTN2018 - UIT");
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit(0);
}

void MainWindow::on_actionAddNode_triggered()
{
    showNewNodeDialog();
}

void MainWindow::on_actionAddArc_triggered()
{
    bool ok{};
    QList<QString> labelText;
    labelText.push_back("From node: ");
    labelText.push_back("To node: ");
    labelText.push_back("Weight: ");
    QList<QString> list = InputDialog::getStrings(this, "Add new arc", labelText, &ok);
    QRegExp re("\\d*");
    if (ok && !list.empty() && re.exactMatch(list[2])) {
        bool succeeded = graph->setArc(list[0].toStdString(), list[1].toStdString(), list[2].toInt());
        if (succeeded)
            emit graphChanged();
        else
            QMessageBox::critical(this, "Error", "Cannot set this arc!");
    }
}

void MainWindow::on_actionEditArc_triggered()
{
    bool ok{};
    QList<QString> labelText;
    labelText.push_back("From node: ");
    labelText.push_back("To node: ");
    labelText.push_back("Weight: ");
    QList<QString> list = InputDialog::getStrings(this, "Edit arc", labelText, &ok);
    QRegExp re("\\d*");
    if (ok && !list.empty() && re.exactMatch(list[2])) {
        if (graph->hasThisArc(list[0].toStdString(), list[1].toStdString())) {
            bool succeeded = graph->setArc(list[0].toStdString(), list[1].toStdString(), list[2].toInt());
            if (succeeded) {
                emit graphChanged();
                return;
            }
        }
        QMessageBox::critical(this, "Error", "There's no arc like this!");
    }
}

void MainWindow::on_actionDelNode_triggered()
{
    bool ok;
    QString todelName = QInputDialog::getText(this, "Delete node", "Name: ",QLineEdit::Normal, QString(), &ok);
    if (ok) {
        bool succeeded = graph->removeNode(todelName.toStdString());
        if (!succeeded)
            QMessageBox::critical(this, "Error", "There's no node like this!");
        else
            emit graphChanged();
    }
}

void MainWindow::on_actionDelArc_triggered()
{
    bool ok{};
    QList<QString> labelText;
    labelText.push_back("From node: ");
    labelText.push_back("To node: ");
    QList<QString> list = InputDialog::getStrings(this, "Delete arc", labelText, &ok);
    if (ok && !list.empty()) {
        bool succeeded = graph->removeArc(list[0].toStdString(), list[1].toStdString());
        if (succeeded)
            emit graphChanged();
        else
            QMessageBox::critical(this, "Error", "There's no arc like this!");
    }
}

void MainWindow::on_articulationNodeBtn_clicked()
{
    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<int> res = graph_utils.displayArticulationNodes(*graph);
    emit startAlgorithm(res, GraphDemoFlag::OnlyNode);
}

void MainWindow::on_bridgesBtn_clicked()
{
    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<std::pair<int, int>> res = graph_utils.displayBridges(*graph);
    emit startAlgorithm(res, GraphDemoFlag::OnlyArc);
}

void MainWindow::on_coloringBtn_clicked()
{
    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<int> res = graph_utils.displayColoring(*graph);
    emit startAlgorithm(res, GraphDemoFlag::Coloring);
}
void MainWindow::on_weaklyConnectedBtn_clicked()
{
    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<std::list<int>> res = graph_utils.displayConnectedComponents(*graph, false);
    emit startAlgorithm(res, GraphDemoFlag::Component);

}
void MainWindow::on_connectedComponentsBtn_clicked()
{
    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<std::list<int>> res = graph_utils.displayConnectedComponents(*graph);
    emit startAlgorithm(res, GraphDemoFlag::Component);
}

void MainWindow::on_shortestPathBtn_clicked()
{
    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    bool ok{};
    QList<QString> labels; labels.append("From node: "); labels.append("To node: ");
    QList<QString> reply = InputDialog::getStrings(this, "Find shortest path", labels, &ok);
    if (ok) {
        if (reply[0].trimmed().isNull() || reply[1].trimmed().isNull())
            return;
        int fromId = graph->findNodeIdByName(reply[0].toStdString());
        int toId = graph->findNodeIdByName(reply[1].toStdString());
        if (!graph->hasThisNode(fromId)) {
            QMessageBox::critical(this, "Error", tr("No node named ") + reply[0]);
            return;
        }
        if (!graph->hasThisNode(toId)) {
            QMessageBox::critical(this,"Error", tr("No node named ") + reply[1]);
            return;
        }
        std::list<int> res = graph_utils.Dijkstra(*graph, fromId, toId);
        emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
    }
}

void MainWindow::on_topoSortBtn_clicked()
{

    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<int> res = graph_utils.displayTopoSort(*graph);
    emit startAlgorithm(res, GraphDemoFlag::OnlyNode);
}

void MainWindow::on_BFSbtn_clicked()
{
    ui->console_text->clear();
    bool ok {};
    QString source_str = QInputDialog::getText(this, "Source node", "Name: ", QLineEdit::Normal, QString(), &ok);
    int id = graph->findNodeIdByName(source_str.toStdString());
    if (ok) {
        if (source_str.isNull())
            return;
        if (graph->hasThisNode(id))
        {
            GraphUtils graph_utils;
            QDebugStream qout(std::cout, ui->console_text);
            std::list<std::pair<int, int>> res = graph_utils.BfsToDemo(*graph, id);
            emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
        }
        else {
            QMessageBox::critical(this, "Error", tr("No node named ") + source_str);
        }
    }
}

void MainWindow::on_DFSbtn_clicked()
{
    ui->console_text->clear();
    bool ok {};
    QString source_str = QInputDialog::getText(this, "Source node", "Name: ", QLineEdit::Normal, QString(), &ok);
    int id = graph->findNodeIdByName(source_str.toStdString());
    if (ok) {
        if (source_str.isNull())
            return;
        if (graph->hasThisNode(id))
        {
            GraphUtils graph_utils;
            QDebugStream qout(std::cout, ui->console_text);
            std::list<std::pair<int, int>> res = graph_utils.DfsToDemo(*graph, id);
            emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
        }
        else
            QMessageBox::critical(this, "Error", tr("No node named ") + source_str);
    }
}

void MainWindow::on_EulerBtn_clicked()
{

    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<int> res = graph_utils.displayEulerCycle(*graph);
    emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
}

void MainWindow::on_HamiltonBtn_clicked()
{
    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<int> res = graph_utils.displayHamiltonianCycle(*graph);
    emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
}

void MainWindow::on_spanningTreeBtn_clicked()
{
    ui->console_text->clear();
    GraphUtils graph_utils;
    QDebugStream qout(std::cout, ui->console_text);
    std::list<std::pair<int, int>> res = graph_utils.Prim(*graph);
    emit startAlgorithm(res, GraphDemoFlag::ArcAndNode);
}

void MainWindow::on_actionBFS_triggered()
{
   on_BFSbtn_clicked();
}

void MainWindow::on_actionDFS_triggered()
{
    on_DFSbtn_clicked();
}

void MainWindow::on_actionColoring_triggered()
{
    on_coloringBtn_clicked();
}

void MainWindow::on_actionTopo_Sorting_triggered()
{
    on_topoSortBtn_clicked();
}

void MainWindow::on_actionEuler_Cycle_triggered()
{
    on_EulerBtn_clicked();
}

void MainWindow::on_actionHamiltonian_Cycle_triggered()
{
    on_HamiltonBtn_clicked();
}

void MainWindow::on_actionFind_shortest_path_triggered()
{
    on_shortestPathBtn_clicked();
}

void MainWindow::on_actionFind_all_bridges_triggered()
{
    on_bridgesBtn_clicked();
}
void MainWindow::on_actionFind_all_Articulation_nodes_triggered()
{
    on_articulationNodeBtn_clicked();
}

void MainWindow::on_actionFind_connected_components_triggered()
{
    on_connectedComponentsBtn_clicked();
}

void MainWindow::on_actionFInd_minimum_spanning_tree_triggered()
{
    on_spanningTreeBtn_clicked();
}

void MainWindow::on_actionFind_weakly_connected_components_triggered()
{
    on_weaklyConnectedBtn_clicked();
}


