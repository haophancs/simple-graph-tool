#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/GraphGraphicsView.h"
#include "headers/GraphUtils.h"
#include "headers/InputDialog.h"
#include <QtGui>
#include <QMessageBox>
#include <QTimer>
#include "headers/qdebugstream.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->statusBar->setStyleSheet("color: darkgrey");
    ui->consoleText->setReadOnly(true);

    this->dataNeedSaving = false;
    this->setWindowTitle("Simple Graph Tool");
    auto *m = new QSignalMapper(this);
    auto *s1 = new QShortcut(QKeySequence("Alt+1"), this);
    auto *s2 = new QShortcut(QKeySequence("Alt+2"), this);
    connect(s1, SIGNAL(activated()), m, SLOT(map()));
    connect(s2, SIGNAL(activated()), m, SLOT(map()));
    m->setMapping(s1, 0);
    m->setMapping(s2, 1);
    connect(m, SIGNAL(mapped(int)), ui->tabWidget, SLOT(setCurrentIndex(int)));
    QFont btnFont;
    btnFont.setPixelSize(32);
    ui->createGraphButton->setFont(btnFont);
    ui->openGraphButton->setFont(btnFont);

    this->graph = new Graph();
    this->scene = new GraphGraphicsScene(graph);
    this->view = new GraphGraphicsView();
    this->matrix = new GraphMatrixTable(graph);
    this->propertiesTable = new ElementPropertiesTable(graph);

    connect(matrix, SIGNAL(graphChanged()), scene, SLOT(reloadData()));
    connect(scene, SIGNAL(graphChanged()), matrix, SLOT(reloadData()));
    connect(this, SIGNAL(graphChanged()), scene, SLOT(reloadData()));
    connect(this, SIGNAL(graphChanged()), matrix, SLOT(reloadData()));
    connect(this, SIGNAL(graphChanged()), view, SLOT(redraw()));
    connect(this, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));
    connect(matrix, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));
    connect(scene, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));

    connect(view, SIGNAL(unSelect()), propertiesTable, SLOT(onUnSelected()));
    connect(this, SIGNAL(graphChanged()), propertiesTable, SLOT(onGraphChanged()));
    connect(view, &GraphGraphicsView::selectedNode, propertiesTable, &ElementPropertiesTable::onNodeSelected);
    connect(view, &GraphGraphicsView::selectedArc, propertiesTable, &ElementPropertiesTable::onArcSelected);
    connect(matrix, &GraphMatrixTable::selectedArc, propertiesTable, &ElementPropertiesTable::onArcSelected);

    connect(this, SIGNAL(startDemoAlgorithm(std::list<std::list<int> >, GraphDemoFlag)), scene,
            SLOT(demoAlgorithm(std::list<std::list<int> >, GraphDemoFlag)));
    connect(this, SIGNAL(startDemoAlgorithm(std::list<int>, GraphDemoFlag)), scene,
            SLOT(demoAlgorithm(std::list<int>, GraphDemoFlag)));
    connect(this, SIGNAL(startDemoAlgorithm(std::list<std::pair<int, int> >, GraphDemoFlag)), scene,
            SLOT(demoAlgorithm(std::list<std::pair<int, int> >, GraphDemoFlag)));

    connect(view, &GraphGraphicsView::addNewNode, this, [this](QPointF pos) {
        showNewNodeDialog(pos);
    });
    connect(view, &GraphGraphicsView::removeNode, this, [this](int id) {
        if (this->graph->removeNode(id))
                emit graphChanged();
    });
    connect(view, &GraphGraphicsView::isolateNode, this, [this](int id) {
        if (this->graph->isolateNode(id))
                emit graphChanged();
    });
    connect(view, &GraphGraphicsView::removeArc, this, [this](int u, int v) {
        if (graph->removeArc(u, v))
                emit graphChanged();
    });
    connect(view, &GraphGraphicsView::setArc, this, [this](int u, int v) {
        bool ok{};
        int defaultValue = graph->hasThisArc(u, v) ? graph->getArcWeight(u, v) : 1;
        int w = QInputDialog::getInt(this, tr("Set weight for arc(")
                                           + QString::fromStdString(graph->getNodeName(u)) + ", "
                                           + QString::fromStdString(graph->getNodeName(v)) + tr(")"),
                                     "0 <= weight < " + QString::number(INT_MAX),
                                     defaultValue, 1, INT_MAX, 1, &ok);
        if (ok && this->graph->setArc(u, v, w))
                emit graphChanged();
    });
    connect(view, &GraphGraphicsView::startAlgorithm, this, [this](const QString &algo, int id) {
        QDebugStream qout(std::cout, ui->consoleText);
        if (algo == "BFS") {
            this->ui->consoleText->clear();
            std::list<std::pair<int, int>> res = GraphUtils::BfsToDemo(*(this->graph), id);
            emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
        } else if (algo == "DFS") {
            this->ui->consoleText->clear();
            std::list<std::pair<int, int>> res = GraphUtils::DfsToDemo(*(this->graph), id);
            emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
        } else if (algo == "Find path") {
            bool ok;
            QString goal = QInputDialog::getText(this, "Find shortest path", "To node: ", QLineEdit::Normal, QString(),
                                                 &ok);
            if (ok) {
                if (goal.isNull())
                    return;
                int toId = this->graph->findNodeIdByName(goal.toStdString());
                if (!this->graph->hasThisNode(toId)) {
                    QMessageBox::critical(this, "Error", tr(":waNo node named ") + goal);
                    return;
                }
                this->ui->consoleText->clear();
                qDebug() << GraphUtils::isConnectedFromUtoV(*graph, id, toId);
                std::list<int> res = GraphUtils::Dijkstra(*(this->graph), id, toId);
                emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
            }
        }
    });
    connect(view, &GraphGraphicsView::editNode, this, [this](int id) {
        bool ok;
        QRegExp re("[a-zA-Z0-9]{1,3}");
        QString newNodeName = QInputDialog::getText(this, "Add new node", "Name: ", QLineEdit::Normal, QString(), &ok);
        if (ok) {
            if (!re.exactMatch(newNodeName)) {
                QMessageBox::critical(this, "Error",
                                      tr("Node's name contains only alphabetical or numeric characters\n")
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

    ui->matrixLayout->addWidget(this->matrix, 0, Qt::AlignCenter);
    ui->propertiesLayout->addWidget(this->propertiesTable, 0, Qt::AlignTop);
    this->view->setScene(this->scene);
    ui->visualLayout->addWidget(this->view);
    this->view->show();
    setWorkspaceEnabled(false);
}

void MainWindow::initWorkspace(const QString &filename, bool newFile) {

    try {
        if (!newFile) {
            graph->readFromFile(filename.toStdString());
            this->dataNeedSaving = false;
        } else {
            this->dataNeedSaving = true;
            bool okIsPressed = false;
            int n = QInputDialog::getInt(this, "Initialize graph with nodes",
                                         "Maximum 26 nodes that can be automatically generated",
                                         0, 0, 26, 1, &okIsPressed);
            if (!okIsPressed) return;
            graph->init(n);
        }
        emit graphChanged();
    }
    catch (...) {
        setWorkspaceEnabled(false);
        QMessageBox::critical(this, "Error",
                              "Something is wrong with this file",
                              QMessageBox::Cancel);
        if (workingFileName != "") setWorkspaceEnabled(true);
        return;
    }
    this->workingFileName = filename;
    int index = filename.toStdString().find_last_of("/\\");
    std::string input_trace_filename = filename.toStdString().substr(index + 1);
    setWindowTitle(QString::fromStdString(input_trace_filename) + " - Simple Graph Tool");
    setWorkspaceEnabled(true);
}

MainWindow::~MainWindow() {
    delete ui;
    delete graph;
    delete scene;
    delete view;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (dataNeedSaving) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Save Graph?",
                                                                  "Your changes will be lost if you don't save them!",
                                                                  QMessageBox::No | QMessageBox::Yes |
                                                                  QMessageBox::Cancel);
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
            nullptr,
            QFileDialog::DontUseNativeDialog);
}

QString MainWindow::showSaveFileDialog() {
    QString newFilename;
    for (int i = 1; true; i++) {
        std::ifstream is(QDir::currentPath().toStdString()
                         + "/graph" + std::to_string(i) + ".gph");
        if (!is.good()) {
            newFilename = QString::fromStdString(QDir::currentPath().toStdString()
                                                 + "/graph" + std::to_string(i) + ".gph");
            break;
        }
    }
    return QFileDialog::getSaveFileName(this, tr("New Graph"),
                                        newFilename,
                                        tr("Graph files (*.gph)"),
                                        nullptr,
                                        QFileDialog::DontUseNativeDialog);
}

void MainWindow::showNewNodeDialog(QPointF pos) {
    bool ok;
    QRegExp re("[a-zA-Z0-9]{1,3}");
    QString newNodeName = QInputDialog::getText(this, "Add new node", "Name: ", QLineEdit::Normal, QString(), &ok);
    if (ok) {
        if (!re.exactMatch(newNodeName)) {
            QMessageBox::critical(this, "Error", tr("Node's name contains only alphabetical or numeric characters\n")
                                                 +
                                                 tr("Length of the name mustn't be greater than 3 or smaller than 1"));
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

void MainWindow::setWorkspaceEnabled(bool ready) {
    if (ready) ui->entryWidget->setVisible(false);
    ui->workingWidget->setVisible(ready);
    ui->menuGraph->setEnabled(ready);
    ui->menuAlgorithms->setEnabled(ready);
    for (auto action: ui->menuFile->actions())
        if (!action->menu() && !action->isSeparator()
            && action->text().contains("Save"))
            action->setEnabled(ready);
    if (ready)
        view->scale(1, 1);
}

void MainWindow::onGraphChanged() {
    this->dataNeedSaving = true;
    ui->statusBar->clearMessage();
    ui->consoleText->clear();
}

void MainWindow::on_createGraphButton_clicked() {
    QString filename = showSaveFileDialog();
    if (!filename.isNull())
        initWorkspace(filename, true);
}

void MainWindow::on_openGraphButton_clicked() {
    QString filename = showOpenFileDialog();
    if (!filename.isNull())
        initWorkspace(filename);
}

void MainWindow::on_actionSave_triggered() {
    if (dataNeedSaving) {
        this->dataNeedSaving = false;
        graph->writeToFile(workingFileName.toStdString());
        ui->statusBar->showMessage("Saved successfully");
        QTimer::singleShot(2000, this, [this]() {
            this->ui->statusBar->clearMessage();
        });
    }
}

void MainWindow::on_actionSave_As_triggered() {
    QString filename = showSaveFileDialog();
    if (!filename.isNull())
        graph->writeToFile(filename.toStdString());
}

void MainWindow::on_actionNew_Graph_triggered() {
    QString filename = showSaveFileDialog();
    if (!filename.isNull())
        initWorkspace(filename, true);
}

void MainWindow::on_actionOpen_Graph_triggered() {
    QString filename = showOpenFileDialog();
    if (!filename.isNull() && filename != workingFileName)
        initWorkspace(filename);
}

void MainWindow::on_actionCredits_triggered() {
    QMessageBox::about(this, "Credit", "Author: Hao Phan Phu - KHTN2018 - UIT");
}

void MainWindow::on_actionExit_triggered() {
    QApplication::exit(0);
}

void MainWindow::on_actionAddNode_triggered() {
    showNewNodeDialog();
}

void MainWindow::on_actionAddArc_triggered() {
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

void MainWindow::on_actionEditArc_triggered() {
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

void MainWindow::on_actionDelNode_triggered() {
    bool ok;
    QString nameToDel = QInputDialog::getText(this, "Delete node", "Name: ", QLineEdit::Normal, QString(), &ok);
    if (ok) {
        bool succeeded = graph->removeNode(nameToDel.toStdString());
        if (!succeeded)
            QMessageBox::critical(this, "Error", "There's no node like this!");
        else
                emit graphChanged();
    }
}

void MainWindow::on_actionDelArc_triggered() {
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

void MainWindow::on_articulationNodeBtn_clicked() {
    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<int> res = GraphUtils::displayArticulationNodes(*graph);
    emit startDemoAlgorithm(res, GraphDemoFlag::OnlyNode);
}

void MainWindow::on_bridgesBtn_clicked() {
    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<std::pair<int, int>> res = GraphUtils::displayBridges(*graph);
    emit startDemoAlgorithm(res, GraphDemoFlag::OnlyArc);
}

void MainWindow::on_coloringBtn_clicked() {
    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<int> res = GraphUtils::displayColoring(*graph);
    emit startDemoAlgorithm(res, GraphDemoFlag::Coloring);
}

void MainWindow::on_weaklyConnectedBtn_clicked() {
    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<std::list<int>> res = GraphUtils::displayConnectedComponents(*graph, false);
    emit startDemoAlgorithm(res, GraphDemoFlag::Component);

}

void MainWindow::on_connectedComponentsBtn_clicked() {
    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<std::list<int>> res = GraphUtils::displayConnectedComponents(*graph);
    emit startDemoAlgorithm(res, GraphDemoFlag::Component);
}

void MainWindow::on_shortestPathBtn_clicked() {
    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    bool ok{};
    QList<QString> labels;
    labels.append("From node: ");
    labels.append("To node: ");
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
            QMessageBox::critical(this, "Error", tr("No node named ") + reply[1]);
            return;
        }
        std::list<int> res = GraphUtils::Dijkstra(*graph, fromId, toId);
        emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
    }
}

void MainWindow::on_topoSortBtn_clicked() {

    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<int> res = GraphUtils::displayTopoSort(*graph);
    emit startDemoAlgorithm(res, GraphDemoFlag::OnlyNode);
}

void MainWindow::on_BFSbtn_clicked() {
    ui->consoleText->clear();
    bool ok{};
    QString source_str = QInputDialog::getText(this, "Source node", "Name: ", QLineEdit::Normal, QString(), &ok);
    int id = graph->findNodeIdByName(source_str.toStdString());
    if (ok) {
        if (source_str.isNull())
            return;
        if (graph->hasThisNode(id)) {
            QDebugStream qout(std::cout, ui->consoleText);
            std::list<std::pair<int, int>> res = GraphUtils::BfsToDemo(*graph, id);
            emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
        } else {
            QMessageBox::critical(this, "Error", tr("No node named ") + source_str);
        }
    }
}

void MainWindow::on_DFSbtn_clicked() {
    ui->consoleText->clear();
    bool ok{};
    QString source_str = QInputDialog::getText(this, "Source node", "Name: ", QLineEdit::Normal, QString(), &ok);
    int id = graph->findNodeIdByName(source_str.toStdString());
    if (ok) {
        if (source_str.isNull())
            return;
        if (graph->hasThisNode(id)) {
            QDebugStream qout(std::cout, ui->consoleText);
            std::list<std::pair<int, int>> res = GraphUtils::DfsToDemo(*graph, id);
            emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
        } else
            QMessageBox::critical(this, "Error", tr("No node named ") + source_str);
    }
}

void MainWindow::on_EulerBtn_clicked() {

    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<std::list<int>> res = GraphUtils::displayEulerianCircuit(*graph);
    emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
}

void MainWindow::on_HamiltonBtn_clicked() {
    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<std::list<int>> res = GraphUtils::displayHamiltonianCycle(*graph);
    emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
}

void MainWindow::on_spanningTreeBtn_clicked() {
    ui->consoleText->clear();
    QDebugStream qout(std::cout, ui->consoleText);
    std::list<std::pair<int, int>> res = GraphUtils::Prim(*graph);
    emit startDemoAlgorithm(res, GraphDemoFlag::ArcAndNode);
}

void MainWindow::on_actionBFS_triggered() {
    on_BFSbtn_clicked();
}

void MainWindow::on_actionDFS_triggered() {
    on_DFSbtn_clicked();
}

void MainWindow::on_actionColoring_triggered() {
    on_coloringBtn_clicked();
}

void MainWindow::on_actionTopo_Sorting_triggered() {
    on_topoSortBtn_clicked();
}

void MainWindow::on_actionEuler_Cycle_triggered() {
    on_EulerBtn_clicked();
}

void MainWindow::on_actionHamiltonian_Cycle_triggered() {
    on_HamiltonBtn_clicked();
}

void MainWindow::on_actionFind_shortest_path_triggered() {
    on_shortestPathBtn_clicked();
}

void MainWindow::on_actionFind_all_bridges_triggered() {
    on_bridgesBtn_clicked();
}

void MainWindow::on_actionFind_all_Articulation_nodes_triggered() {
    on_articulationNodeBtn_clicked();
}

void MainWindow::on_actionFind_connected_components_triggered() {
    on_connectedComponentsBtn_clicked();
}

void MainWindow::on_actionFInd_minimum_spanning_tree_triggered() {
    on_spanningTreeBtn_clicked();
}

void MainWindow::on_actionFind_weakly_connected_components_triggered() {
    on_weaklyConnectedBtn_clicked();
}
