#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphics/headers/GraphGraphicsView.h"
#include "basis/headers/GraphUtils.h"
#include "widgets/headers/InputDialog.h"
#include <QtGui>
#include <QMessageBox>
#include <QTimer>
#include <widgets/headers/GraphOptionDialog.h>
#include "utils/qdebugstream.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        _ui(new Ui::MainWindow) {
    _ui->setupUi(this);
    _ui->statusBar->setStyleSheet("color: darkgrey");
    _ui->consoleText->setReadOnly(true);
    _ui->verticalSplitter->setStretchFactor(0, 1);
    this->_dataNeedSaving = false;
    this->setWindowTitle("Simple Graph Tool");
    auto *m = new QSignalMapper(this);
    auto *s1 = new QShortcut(QKeySequence("Alt+1"), this);
    auto *s2 = new QShortcut(QKeySequence("Alt+2"), this);
    connect(s1, SIGNAL(activated()), m, SLOT(map()));
    connect(s2, SIGNAL(activated()), m, SLOT(map()));
    m->setMapping(s1, 0);
    m->setMapping(s2, 1);
    connect(m, SIGNAL(mapped(int)), _ui->tabWidget, SLOT(setCurrentIndex(int)));
    QFont btnFont;
    btnFont.setPixelSize(32);
    _ui->createGraphButton->setFont(btnFont);
    _ui->openGraphButton->setFont(btnFont);

    this->_graph = new Graph(false, false);
    this->_scene = new GraphGraphicsScene(_graph);
    this->_view = new GraphGraphicsView();
    this->_matrix = new GraphMatrixTable(_graph);
    this->_elementPropertiesTable = new ElementPropertiesTable(_graph);
    this->_graphPropertiesTable = new GraphPropertiesTable(_graph);

    connect(_matrix, SIGNAL(graphChanged()), _scene, SLOT(reload()));
    connect(_scene, SIGNAL(graphChanged()), _matrix, SLOT(reload()));
    connect(this, SIGNAL(graphChanged()), _scene, SLOT(reload()));
    connect(this, SIGNAL(graphChanged()), _matrix, SLOT(reload()));
    connect(this, SIGNAL(graphChanged()), _view, SLOT(redraw()));
    connect(this, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));
    connect(_matrix, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));
    connect(_scene, SIGNAL(graphChanged()), this, SLOT(onGraphChanged()));

    connect(_view, SIGNAL(unSelected()), _elementPropertiesTable, SLOT(onUnSelected()));
    connect(this, SIGNAL(graphChanged()), _elementPropertiesTable, SLOT(onGraphChanged()));
    connect(this, SIGNAL(graphChanged()), _graphPropertiesTable, SLOT(onGraphChanged()));
    connect(_matrix, SIGNAL(graphChanged()), _graphPropertiesTable, SLOT(onGraphChanged()));
    connect(_scene, SIGNAL(graphChanged()), _graphPropertiesTable, SLOT(onGraphChanged()));
    connect(_view, &GraphGraphicsView::nodeSelected, _elementPropertiesTable, &ElementPropertiesTable::onNodeSelected);
    connect(_view, &GraphGraphicsView::edgeSelected, _elementPropertiesTable, &ElementPropertiesTable::onEdgeSelected);
    connect(_matrix, &GraphMatrixTable::edgeSelected, _elementPropertiesTable, &ElementPropertiesTable::onEdgeSelected);

    connect(this, SIGNAL(startDemoAlgorithm(std::list<std::list<std::string> >, GraphDemoFlag)), _scene,
            SLOT(demoAlgorithm(std::list<std::list<std::string> >, GraphDemoFlag)));
    connect(this, SIGNAL(startDemoAlgorithm(std::list<std::string>, GraphDemoFlag)), _scene,
            SLOT(demoAlgorithm(std::list<std::string>, GraphDemoFlag)));
    connect(this, SIGNAL(startDemoAlgorithm(std::list<std::pair<std::string, std::string> >, GraphDemoFlag)), _scene,
            SLOT(demoAlgorithm(std::list<std::pair<std::string, std::string> >, GraphDemoFlag)));

    connect(_view, &GraphGraphicsView::nodeAdded, this, [this](QPointF pos, bool auto_naming) {
        if (!auto_naming) {
            showNewNodeDialog(pos);
            return;
        }
        this->_graph->addNode(Node(_graph->nextNodeName(), pos));
        emit graphChanged();
    });
    connect(_view, &GraphGraphicsView::nodeRemoved, this, [this](const std::string& node_name) {
        if (this->_graph->removeNode(node_name))
                emit graphChanged();
    });
    connect(_view, &GraphGraphicsView::nodeIsolated, this, [this](const std::string& node_name) {
        if (this->_graph->isolateNode(node_name))
                emit graphChanged();
    });
    connect(_view, &GraphGraphicsView::edgeRemoved, this, [this](const std::string& uname, const std::string& vname) {
        if (_graph->removeEdge(uname, vname))
                emit graphChanged();
    });
    connect(_view, &GraphGraphicsView::edgeSet, this, [this](const std::string& uname, const std::string& vname) {
        bool ok{};
        int defaultValue = _graph->hasEdge(uname, vname) ? _graph->weight(uname, vname) : 1;
        int w = _graph->isWeighted() ?
                (QInputDialog::getInt(this, tr("Set weight for edge(")
                    + QString::fromStdString(_graph->node(uname)->name()) + ", "
                    + QString::fromStdString(_graph->node(vname)->name()) + tr(")"),
                    "0 <= weight < " + QString::number(INT_MAX),
                    defaultValue, 1, INT_MAX, 1, &ok))
                : 1;
        qDebug() << w;
        if ((ok || _graph->isUnweighted()) && this->_graph->setEdge(uname, vname, w))
            emit graphChanged();
    });
    connect(_view, &GraphGraphicsView::startAlgorithm, this, [this](const QString &algo, const std::string& source_name) {
        QDebugStream qout(std::cout, _ui->consoleText);
        if (algo == "BFS") {
            this->_ui->consoleText->clear();
            auto result = GraphUtils::BFSToDemo(this->_graph, source_name);
            emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
        } else if (algo == "DFS") {
            this->_ui->consoleText->clear();
            auto result = GraphUtils::DFSToDemo(this->_graph, source_name);
            emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
        } else if (algo == "Find MST") {
            this->_ui->consoleText->clear();
            auto result = GraphUtils::Prim(this->_graph, source_name);
            emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);

        } else if (algo == "Find path") {
            bool ok;
            QString goal = QInputDialog::getText(this, "Find shortest path", "To node: ", QLineEdit::Normal, QString(),
                                                 &ok);
            if (ok) {
                if (goal.isNull())
                    return;
                auto target = this->_graph->node(goal.toStdString());
                if (!this->_graph->hasNode(target)) {
                    QMessageBox::critical(this, "Error", tr("No node named ") + goal);
                    return;
                }
                this->_ui->consoleText->clear();
                auto result = GraphUtils::Dijkstra(this->_graph, source_name, target->name());
                emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
            }
        }
    });
    connect(_view, &GraphGraphicsView::nodeEdited, this, [this](const std::string& node_name) {
        bool ok;
        QRegExp re("[a-zA-Z0-9]{1,30}");
        auto new_name = QInputDialog::getText(this, "Rename node", "Name: ", QLineEdit::Normal, QString::fromStdString(_graph->nextNodeName()), &ok);
        if (ok) {
            if (!re.exactMatch(new_name)) {
                QMessageBox::critical(this, "Error",
                                      tr("Node's name contains only alphabetical or numeric characters\n")
                                      + tr("Length of the name mustn't be greater than 30 or smaller than 1"));
                return;
            }
            if (this->_graph->hasNode(new_name.toStdString()))
                QMessageBox::critical(this, "Error", "This name has been used by another node");
            else {
                this->_graph->setNodeName(node_name, new_name.toStdString());
                emit graphChanged();
            }
        }
    });

    _ui->matrixLayout->addWidget(this->_matrix, 0, Qt::AlignCenter);
    auto gLabel = new QLabel(this);
    gLabel->setText("Graph properties");
    _ui->propertiesLayout->addWidget(gLabel);
    _ui->propertiesLayout->addWidget(this->_graphPropertiesTable, 0, Qt::AlignTop);
    auto eLabel = new QLabel(this);
    eLabel->setText("Selected element properties");
    eLabel->setContentsMargins(0, 12, 0, 0);
    _ui->propertiesLayout->addWidget(eLabel);
    _ui->propertiesLayout->addWidget(this->_elementPropertiesTable, 0, Qt::AlignTop);
    this->_view->setScene(this->_scene);
    _ui->visualLayout->addWidget(this->_view);
    this->_view->show();
    setWorkspaceEnabled(false);
}

void MainWindow::resetGraph(Graph *graph) {
    delete this->_graph;
    this->_graph = graph;
    this->_scene->setGraph(_graph);
    this->_matrix->setGraph(_graph);
    this->_elementPropertiesTable->setGraph(_graph);
    this->_graphPropertiesTable->setGraph(_graph);
    _ui->coloringBtn->setVisible(_graph->isUndirected());
    _ui->actionColoring->setVisible(_graph->isUndirected());
    _ui->topoSortBtn->setVisible(_graph->isDirected());
    _ui->actionTopo_Sorting->setVisible(_graph->isDirected());
    _ui->weaklyConnectedBtn->setVisible(_graph->isDirected());
    _ui->actionFind_weakly_connected_components->setVisible(_graph->isDirected());
    _ui->connectedComponentsBtn->setText(_graph->isDirected() ?
        "Find strongly connected components"
        : "Find connected components");
    _ui->actionFind_connected_components->setVisible(_ui->connectedComponentsBtn->isVisible());
}

void MainWindow::initWorkspace(const QString &filename, bool new_file) {

    try {
        if (!new_file) {
            if (this->_dataNeedSaving) {
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Save Graph?",
                                                                          "Your changes will be lost if you don't save them!",
                                                                          QMessageBox::No | QMessageBox::Yes |
                                                                          QMessageBox::Cancel);
                if (reply == QMessageBox::Cancel)
                    return;
            }
            resetGraph(new Graph(Graph::readFromFile(filename.toStdString())));
            this->_dataNeedSaving = false;
        } else {
            bool weighted, directed, ok;
            int node_num;
            GraphOptionDialog::initGraph(this, weighted, directed, node_num, ok);
            if (!ok) return;
            this->_dataNeedSaving = true;
            resetGraph(new Graph(node_num, directed, weighted));
        }
        emit graphChanged();
    }
    catch (...) {
        setWorkspaceEnabled(false);
        QMessageBox::critical(this, "Error",
                              "Something is wrong with this file",
                              QMessageBox::Cancel);
        if (_workingFilename != "") setWorkspaceEnabled(true);
        return;
    }
    this->_workingFilename = filename;
    int index = filename.toStdString().find_last_of("/\\");
    std::string input_trace_filename = filename.toStdString().substr(index + 1);
    setWindowTitle(QString::fromStdString(input_trace_filename) + " - Simple Graph Tool");
    setWorkspaceEnabled(true);
}

MainWindow::~MainWindow() {
    delete _ui;
    delete _graph;
    delete _scene;
    delete _view;
    delete _elementPropertiesTable;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (_dataNeedSaving) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Save Graph?",
                                                                  "Your changes will be lost if you don't save them!",
                                                                  QMessageBox::No | QMessageBox::Yes |
                                                                  QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
            Graph::writeToFile(_workingFilename.toStdString(), *_graph);
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
    QString newNodeName = QInputDialog::getText(this, "Add new node", "Name: ", QLineEdit::Normal, QString::fromStdString(_graph->nextNodeName()), &ok);
    if (ok) {
        if (!re.exactMatch(newNodeName)) {
            QMessageBox::critical(this, "Error", tr("Node's name contains only alphabetical or numeric characters\n")
                                                 +
                                                 tr("Length of the name mustn't be greater than 3 or smaller than 1"));
            return;
        }
        Node newNode(newNodeName.toStdString(), pos);
        bool succeeded = _graph->addNode(newNode);
        if (!succeeded)
            QMessageBox::critical(this, "Error", "This name has been used by another node");
        else
            emit graphChanged();
    }
}

void MainWindow::setWorkspaceEnabled(bool ready) {
    if (ready) _ui->entryWidget->setVisible(false);
    _ui->workingWidget->setVisible(ready);
    _ui->menuGraph->setEnabled(ready);
    _ui->menuAlgorithms->setEnabled(ready);
    for (auto action: _ui->menuFile->actions())
        if (!action->menu() && !action->isSeparator()
            && action->text().contains("Save"))
            action->setEnabled(ready);
    if (ready)
        _view->scale(1, 1);
}

void MainWindow::onGraphChanged() {
    this->_dataNeedSaving = true;
    _ui->statusBar->clearMessage();
    _ui->consoleText->clear();
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
    if (_dataNeedSaving) {
        this->_dataNeedSaving = false;
        Graph::writeToFile(_workingFilename.toStdString(), *_graph);
        _ui->statusBar->showMessage("Saved successfully");
        QTimer::singleShot(2000, this, [this]() {
            this->_ui->statusBar->clearMessage();
        });
    }
}

void MainWindow::on_actionSave_As_triggered() {
    QString filename = showSaveFileDialog();
    if (!filename.isNull())
        Graph::writeToFile(_workingFilename.toStdString(), *_graph);
}

void MainWindow::on_actionNew_Graph_triggered() {
    QString filename = showSaveFileDialog();
    if (!filename.isNull())
        initWorkspace(filename, true);
}

void MainWindow::on_actionOpen_Graph_triggered() {
    QString filename = showOpenFileDialog();
    if (!filename.isNull() && filename != _workingFilename)
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

void MainWindow::on_actionAddEdge_triggered() {
    bool ok{};
    QList<QString> labelText;
    labelText.push_back("From node: ");
    labelText.push_back("To node: ");
    labelText.push_back("Weight: ");
    QList<QString> list = InputDialog::getStrings(this, "Add new edge", labelText, &ok);
    QRegExp re("\\d*");
    if (ok && !list.empty() && re.exactMatch(list[2])) {
        bool succeeded = _graph->setEdge(list[0].toStdString(), list[1].toStdString(), list[2].toInt());
        if (succeeded)
                emit graphChanged();
        else
            QMessageBox::critical(this, "Error", "Cannot set this edge!");
    }
}

void MainWindow::on_actionEditEdge_triggered() {
    bool ok{};
    QList<QString> labelText;
    labelText.push_back("From node: ");
    labelText.push_back("To node: ");
    labelText.push_back("Weight: ");
    QList<QString> list = InputDialog::getStrings(this, "Edit edge", labelText, &ok);
    QRegExp re("\\d*");
    if (ok && !list.empty() && re.exactMatch(list[2])) {
        if (_graph->hasEdge(list[0].toStdString(), list[1].toStdString())) {
            bool succeeded = _graph->setEdge(list[0].toStdString(), list[1].toStdString(), list[2].toInt());
            if (succeeded) {
                emit graphChanged();
                return;
            }
        }
        QMessageBox::critical(this, "Error", "There's no edge like this!");
    }
}

void MainWindow::on_actionDelNode_triggered() {
    bool ok;
    QString nameToDel = QInputDialog::getText(this, "Delete node", "Name: ", QLineEdit::Normal, QString(), &ok);
    if (ok) {
        bool succeeded = _graph->removeNode(nameToDel.toStdString());
        if (!succeeded)
            QMessageBox::critical(this, "Error", "There's no node like this!");
        else
                emit graphChanged();
    }
}

void MainWindow::on_actionDelEdge_triggered() {
    bool ok{};
    QList<QString> labelText;
    labelText.push_back("From node: ");
    labelText.push_back("To node: ");
    QList<QString> list = InputDialog::getStrings(this, "Delete edge", labelText, &ok);
    if (ok && !list.empty()) {
        bool succeeded = _graph->removeEdge(list[0].toStdString(), list[1].toStdString());
        if (succeeded)
                emit graphChanged();
        else
            QMessageBox::critical(this, "Error", "There's no edge like this!");
    }
}

void MainWindow::on_articulationNodeBtn_clicked() {
    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::displayArticulationNodes(_graph);
    emit startDemoAlgorithm(result, GraphDemoFlag::OnlyNode);
}

void MainWindow::on_bridgesBtn_clicked() {
    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::displayBridges(_graph);
    emit startDemoAlgorithm(result, GraphDemoFlag::OnlyEdge);
}

void MainWindow::on_coloringBtn_clicked() {
    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::displayColoring(_graph);
    emit startDemoAlgorithm(result, GraphDemoFlag::Coloring);
}

void MainWindow::on_weaklyConnectedBtn_clicked() {
    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::displayConnectedComponents(_graph, false);
    emit startDemoAlgorithm(result, GraphDemoFlag::Component);

}

void MainWindow::on_connectedComponentsBtn_clicked() {
    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::displayConnectedComponents(_graph);
    emit startDemoAlgorithm(result, GraphDemoFlag::Component);
}

void MainWindow::on_shortestPathBtn_clicked() {
    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    bool ok{};
    QList<QString> labels;
    labels.append("From node: ");
    labels.append("To node: ");
    QList<QString> reply = InputDialog::getStrings(this, "Find shortest path", labels, &ok);
    if (ok) {
        if (reply[0].trimmed().isNull() || reply[1].trimmed().isNull())
            return;
        auto startNode = _graph->node(reply[0].toStdString());
        auto endNode = _graph->node(reply[1].toStdString());
        if (!_graph->hasNode(startNode)) {
            QMessageBox::critical(this, "Error", tr("No node named ") + reply[0]);
            return;
        }
        if (!_graph->hasNode(endNode)) {
            QMessageBox::critical(this, "Error", tr("No node named ") + reply[1]);
            return;
        }
        auto result = GraphUtils::Dijkstra(_graph, startNode->name(), endNode->name());
        emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
    }
}

void MainWindow::on_topoSortBtn_clicked() {

    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::displayTopoSort(_graph);
    emit startDemoAlgorithm(result, GraphDemoFlag::OnlyNode);
}

void MainWindow::on_BFSbtn_clicked() {
    _ui->consoleText->clear();
    bool ok{};
    QString source_str = QInputDialog::getText(this, "Source node", "Name: ", QLineEdit::Normal, QString(), &ok);
    if (ok) {
        if (source_str.isNull())
            return;
        auto source = _graph->node(source_str.toStdString());
        if (_graph->hasNode(source)) {
            QDebugStream qout(std::cout, _ui->consoleText);
            auto result = GraphUtils::BFSToDemo(_graph, source->name());
            emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
        } else {
            QMessageBox::critical(this, "Error", tr("No node named ") + source_str);
        }
    }
}

void MainWindow::on_DFSbtn_clicked() {
    _ui->consoleText->clear();
    bool ok{};
    QString source_str = QInputDialog::getText(this, "Source node", "Name: ", QLineEdit::Normal, QString(), &ok);
    if (ok) {
        if (source_str.isNull())
            return;
        auto source = _graph->node(source_str.toStdString());
        if (_graph->hasNode(source)) {
            QDebugStream qout(std::cout, _ui->consoleText);
            auto result = GraphUtils::DFSToDemo(_graph, source->name());
            emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
        } else
            QMessageBox::critical(this, "Error", tr("No node named ") + source_str);
    }
}

void MainWindow::on_EulerBtn_clicked() {

    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::displayEulerianCircuit(_graph);
    emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
}

void MainWindow::on_HamiltonBtn_clicked() {
    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::displayHamiltonianCycle(_graph);
    emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
}

void MainWindow::on_spanningTreeBtn_clicked() {
    _ui->consoleText->clear();
    QDebugStream qout(std::cout, _ui->consoleText);
    auto result = GraphUtils::Prim(_graph);
    emit startDemoAlgorithm(result, GraphDemoFlag::EdgeAndNode);
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

