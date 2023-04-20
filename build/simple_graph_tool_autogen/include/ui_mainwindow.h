/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Graph;
    QAction *actionOpen_Graph;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionCredits;
    QAction *actionExit;
    QAction *actionAddNode;
    QAction *actionAddEdge;
    QAction *actionEditEdge;
    QAction *actionDelNode;
    QAction *actionDelEdge;
    QAction *actionBFS;
    QAction *actionDFS;
    QAction *actionColoring;
    QAction *actionTopo_Sorting;
    QAction *actionEuler_Cycle;
    QAction *actionHamiltonian_Cycle;
    QAction *actionDijkstra;
    QAction *actionFind_all_bridges;
    QAction *actionFind_all_Articulation_nodes;
    QAction *actionFind_connected_components;
    QAction *actionFInd_minimum_spanning_tree;
    QAction *actionFind_weakly_connected_components;
    QAction *actionA_star;
    QAction *actionFind_all_cycles;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *entryWidget;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_8;
    QPushButton *createGraphButton;
    QPushButton *openGraphButton;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *workingWidget;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *verticalSplitter;
    QTabWidget *tabWidget;
    QWidget *tabVisualization;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *visualLayout;
    QWidget *tabAdjMat;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *adjMatLayout;
    QWidget *tabIncMat;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *incMatLayout;
    QTextEdit *consoleText;
    QWidget *utils;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *propertiesLayout;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QSlider *horizontalSlider;
    QFrame *line;
    QVBoxLayout *verticalLayout_6;
    QLabel *algorithmsLabel;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BFSbtn;
    QPushButton *DFSbtn;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *EulerBtn;
    QPushButton *HamiltonBtn;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *aStarBtn;
    QPushButton *dijkstraBtn;
    QPushButton *coloringBtn;
    QPushButton *topoSortBtn;
    QPushButton *bridgesBtn;
    QPushButton *articulationNodeBtn;
    QPushButton *spanningTreeBtn;
    QPushButton *cyclesBtn;
    QPushButton *connectedComponentsBtn;
    QPushButton *weaklyConnectedBtn;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuGraph;
    QMenu *menuAdd;
    QMenu *menuEdit;
    QMenu *menuDelete;
    QMenu *menuAlgorithms;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1950, 1440);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1920, 1440));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actionNew_Graph = new QAction(MainWindow);
        actionNew_Graph->setObjectName(QString::fromUtf8("actionNew_Graph"));
        actionOpen_Graph = new QAction(MainWindow);
        actionOpen_Graph->setObjectName(QString::fromUtf8("actionOpen_Graph"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionCredits = new QAction(MainWindow);
        actionCredits->setObjectName(QString::fromUtf8("actionCredits"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAddNode = new QAction(MainWindow);
        actionAddNode->setObjectName(QString::fromUtf8("actionAddNode"));
        actionAddEdge = new QAction(MainWindow);
        actionAddEdge->setObjectName(QString::fromUtf8("actionAddEdge"));
        actionEditEdge = new QAction(MainWindow);
        actionEditEdge->setObjectName(QString::fromUtf8("actionEditEdge"));
        actionDelNode = new QAction(MainWindow);
        actionDelNode->setObjectName(QString::fromUtf8("actionDelNode"));
        actionDelEdge = new QAction(MainWindow);
        actionDelEdge->setObjectName(QString::fromUtf8("actionDelEdge"));
        actionBFS = new QAction(MainWindow);
        actionBFS->setObjectName(QString::fromUtf8("actionBFS"));
        actionDFS = new QAction(MainWindow);
        actionDFS->setObjectName(QString::fromUtf8("actionDFS"));
        actionColoring = new QAction(MainWindow);
        actionColoring->setObjectName(QString::fromUtf8("actionColoring"));
        actionTopo_Sorting = new QAction(MainWindow);
        actionTopo_Sorting->setObjectName(QString::fromUtf8("actionTopo_Sorting"));
        actionEuler_Cycle = new QAction(MainWindow);
        actionEuler_Cycle->setObjectName(QString::fromUtf8("actionEuler_Cycle"));
        actionHamiltonian_Cycle = new QAction(MainWindow);
        actionHamiltonian_Cycle->setObjectName(QString::fromUtf8("actionHamiltonian_Cycle"));
        actionDijkstra = new QAction(MainWindow);
        actionDijkstra->setObjectName(QString::fromUtf8("actionDijkstra"));
        actionFind_all_bridges = new QAction(MainWindow);
        actionFind_all_bridges->setObjectName(QString::fromUtf8("actionFind_all_bridges"));
        actionFind_all_Articulation_nodes = new QAction(MainWindow);
        actionFind_all_Articulation_nodes->setObjectName(QString::fromUtf8("actionFind_all_Articulation_nodes"));
        actionFind_connected_components = new QAction(MainWindow);
        actionFind_connected_components->setObjectName(QString::fromUtf8("actionFind_connected_components"));
        actionFInd_minimum_spanning_tree = new QAction(MainWindow);
        actionFInd_minimum_spanning_tree->setObjectName(QString::fromUtf8("actionFInd_minimum_spanning_tree"));
        actionFind_weakly_connected_components = new QAction(MainWindow);
        actionFind_weakly_connected_components->setObjectName(QString::fromUtf8("actionFind_weakly_connected_components"));
        actionA_star = new QAction(MainWindow);
        actionA_star->setObjectName(QString::fromUtf8("actionA_star"));
        actionFind_all_cycles = new QAction(MainWindow);
        actionFind_all_cycles->setObjectName(QString::fromUtf8("actionFind_all_cycles"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 12);
        entryWidget = new QWidget(centralWidget);
        entryWidget->setObjectName(QString::fromUtf8("entryWidget"));
        horizontalLayout_12 = new QHBoxLayout(entryWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        createGraphButton = new QPushButton(entryWidget);
        createGraphButton->setObjectName(QString::fromUtf8("createGraphButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(createGraphButton->sizePolicy().hasHeightForWidth());
        createGraphButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(createGraphButton);

        openGraphButton = new QPushButton(entryWidget);
        openGraphButton->setObjectName(QString::fromUtf8("openGraphButton"));
        sizePolicy1.setHeightForWidth(openGraphButton->sizePolicy().hasHeightForWidth());
        openGraphButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(openGraphButton);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_12->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);


        horizontalLayout->addWidget(entryWidget);

        workingWidget = new QWidget(centralWidget);
        workingWidget->setObjectName(QString::fromUtf8("workingWidget"));
        horizontalLayout_3 = new QHBoxLayout(workingWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalSplitter = new QSplitter(workingWidget);
        verticalSplitter->setObjectName(QString::fromUtf8("verticalSplitter"));
        sizePolicy1.setHeightForWidth(verticalSplitter->sizePolicy().hasHeightForWidth());
        verticalSplitter->setSizePolicy(sizePolicy1);
        verticalSplitter->setLineWidth(2);
        verticalSplitter->setOrientation(Qt::Vertical);
        verticalSplitter->setChildrenCollapsible(false);
        tabWidget = new QTabWidget(verticalSplitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(1024, 960));
        tabWidget->setMaximumSize(QSize(16777215, 2520));
        tabVisualization = new QWidget();
        tabVisualization->setObjectName(QString::fromUtf8("tabVisualization"));
        horizontalLayout_2 = new QHBoxLayout(tabVisualization);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        visualLayout = new QVBoxLayout();
        visualLayout->setSpacing(6);
        visualLayout->setObjectName(QString::fromUtf8("visualLayout"));

        horizontalLayout_2->addLayout(visualLayout);

        tabWidget->addTab(tabVisualization, QString());
        tabAdjMat = new QWidget();
        tabAdjMat->setObjectName(QString::fromUtf8("tabAdjMat"));
        verticalLayout_3 = new QVBoxLayout(tabAdjMat);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        adjMatLayout = new QVBoxLayout();
        adjMatLayout->setSpacing(0);
        adjMatLayout->setObjectName(QString::fromUtf8("adjMatLayout"));

        verticalLayout_3->addLayout(adjMatLayout);

        tabWidget->addTab(tabAdjMat, QString());
        tabIncMat = new QWidget();
        tabIncMat->setObjectName(QString::fromUtf8("tabIncMat"));
        verticalLayout_5 = new QVBoxLayout(tabIncMat);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        incMatLayout = new QVBoxLayout();
        incMatLayout->setSpacing(6);
        incMatLayout->setObjectName(QString::fromUtf8("incMatLayout"));

        verticalLayout_5->addLayout(incMatLayout);

        tabWidget->addTab(tabIncMat, QString());
        verticalSplitter->addWidget(tabWidget);
        consoleText = new QTextEdit(verticalSplitter);
        consoleText->setObjectName(QString::fromUtf8("consoleText"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(240);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(consoleText->sizePolicy().hasHeightForWidth());
        consoleText->setSizePolicy(sizePolicy2);
        consoleText->setMinimumSize(QSize(0, 240));
        consoleText->setMaximumSize(QSize(16777215, 720));
        verticalSplitter->addWidget(consoleText);

        horizontalLayout_3->addWidget(verticalSplitter);

        utils = new QWidget(workingWidget);
        utils->setObjectName(QString::fromUtf8("utils"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(utils->sizePolicy().hasHeightForWidth());
        utils->setSizePolicy(sizePolicy3);
        utils->setMinimumSize(QSize(480, 0));
        utils->setMaximumSize(QSize(540, 16777215));
        verticalLayout = new QVBoxLayout(utils);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        propertiesLayout = new QVBoxLayout();
        propertiesLayout->setSpacing(6);
        propertiesLayout->setObjectName(QString::fromUtf8("propertiesLayout"));
        propertiesLayout->setContentsMargins(-1, -1, -1, 6);

        verticalLayout->addLayout(propertiesLayout);

        line_4 = new QFrame(utils);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        sizePolicy3.setHeightForWidth(line_4->sizePolicy().hasHeightForWidth());
        line_4->setSizePolicy(sizePolicy3);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 6, -1, 3);
        label = new QLabel(utils);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        horizontalSlider = new QSlider(utils);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(10);
        horizontalSlider->setMaximum(600);
        horizontalSlider->setSliderPosition(300);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider);


        verticalLayout->addLayout(verticalLayout_4);

        line = new QFrame(utils);
        line->setObjectName(QString::fromUtf8("line"));
        sizePolicy3.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 6, -1, -1);
        algorithmsLabel = new QLabel(utils);
        algorithmsLabel->setObjectName(QString::fromUtf8("algorithmsLabel"));
        sizePolicy3.setHeightForWidth(algorithmsLabel->sizePolicy().hasHeightForWidth());
        algorithmsLabel->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(algorithmsLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        BFSbtn = new QPushButton(utils);
        BFSbtn->setObjectName(QString::fromUtf8("BFSbtn"));
        sizePolicy3.setHeightForWidth(BFSbtn->sizePolicy().hasHeightForWidth());
        BFSbtn->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(BFSbtn);

        DFSbtn = new QPushButton(utils);
        DFSbtn->setObjectName(QString::fromUtf8("DFSbtn"));
        sizePolicy3.setHeightForWidth(DFSbtn->sizePolicy().hasHeightForWidth());
        DFSbtn->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(DFSbtn);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        EulerBtn = new QPushButton(utils);
        EulerBtn->setObjectName(QString::fromUtf8("EulerBtn"));
        sizePolicy3.setHeightForWidth(EulerBtn->sizePolicy().hasHeightForWidth());
        EulerBtn->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(EulerBtn);

        HamiltonBtn = new QPushButton(utils);
        HamiltonBtn->setObjectName(QString::fromUtf8("HamiltonBtn"));
        sizePolicy3.setHeightForWidth(HamiltonBtn->sizePolicy().hasHeightForWidth());
        HamiltonBtn->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(HamiltonBtn);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        aStarBtn = new QPushButton(utils);
        aStarBtn->setObjectName(QString::fromUtf8("aStarBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(aStarBtn->sizePolicy().hasHeightForWidth());
        aStarBtn->setSizePolicy(sizePolicy4);

        horizontalLayout_6->addWidget(aStarBtn);

        dijkstraBtn = new QPushButton(utils);
        dijkstraBtn->setObjectName(QString::fromUtf8("dijkstraBtn"));
        sizePolicy3.setHeightForWidth(dijkstraBtn->sizePolicy().hasHeightForWidth());
        dijkstraBtn->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(dijkstraBtn);


        verticalLayout_6->addLayout(horizontalLayout_6);

        coloringBtn = new QPushButton(utils);
        coloringBtn->setObjectName(QString::fromUtf8("coloringBtn"));
        sizePolicy3.setHeightForWidth(coloringBtn->sizePolicy().hasHeightForWidth());
        coloringBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(coloringBtn);

        topoSortBtn = new QPushButton(utils);
        topoSortBtn->setObjectName(QString::fromUtf8("topoSortBtn"));
        sizePolicy3.setHeightForWidth(topoSortBtn->sizePolicy().hasHeightForWidth());
        topoSortBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(topoSortBtn);

        bridgesBtn = new QPushButton(utils);
        bridgesBtn->setObjectName(QString::fromUtf8("bridgesBtn"));
        sizePolicy3.setHeightForWidth(bridgesBtn->sizePolicy().hasHeightForWidth());
        bridgesBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(bridgesBtn);

        articulationNodeBtn = new QPushButton(utils);
        articulationNodeBtn->setObjectName(QString::fromUtf8("articulationNodeBtn"));
        sizePolicy3.setHeightForWidth(articulationNodeBtn->sizePolicy().hasHeightForWidth());
        articulationNodeBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(articulationNodeBtn);

        spanningTreeBtn = new QPushButton(utils);
        spanningTreeBtn->setObjectName(QString::fromUtf8("spanningTreeBtn"));
        sizePolicy3.setHeightForWidth(spanningTreeBtn->sizePolicy().hasHeightForWidth());
        spanningTreeBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(spanningTreeBtn);

        cyclesBtn = new QPushButton(utils);
        cyclesBtn->setObjectName(QString::fromUtf8("cyclesBtn"));

        verticalLayout_6->addWidget(cyclesBtn);

        connectedComponentsBtn = new QPushButton(utils);
        connectedComponentsBtn->setObjectName(QString::fromUtf8("connectedComponentsBtn"));
        sizePolicy3.setHeightForWidth(connectedComponentsBtn->sizePolicy().hasHeightForWidth());
        connectedComponentsBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(connectedComponentsBtn);

        weaklyConnectedBtn = new QPushButton(utils);
        weaklyConnectedBtn->setObjectName(QString::fromUtf8("weaklyConnectedBtn"));
        sizePolicy3.setHeightForWidth(weaklyConnectedBtn->sizePolicy().hasHeightForWidth());
        weaklyConnectedBtn->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(weaklyConnectedBtn);


        verticalLayout->addLayout(verticalLayout_6);

        verticalSpacer_10 = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        verticalSpacer = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(utils);


        horizontalLayout->addWidget(workingWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1950, 37));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuGraph = new QMenu(menuBar);
        menuGraph->setObjectName(QString::fromUtf8("menuGraph"));
        menuAdd = new QMenu(menuGraph);
        menuAdd->setObjectName(QString::fromUtf8("menuAdd"));
        menuEdit = new QMenu(menuGraph);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuDelete = new QMenu(menuGraph);
        menuDelete->setObjectName(QString::fromUtf8("menuDelete"));
        menuAlgorithms = new QMenu(menuBar);
        menuAlgorithms->setObjectName(QString::fromUtf8("menuAlgorithms"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuGraph->menuAction());
        menuBar->addAction(menuAlgorithms->menuAction());
        menuFile->addAction(actionNew_Graph);
        menuFile->addAction(actionOpen_Graph);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionCredits);
        menuFile->addAction(actionExit);
        menuGraph->addAction(menuAdd->menuAction());
        menuGraph->addAction(menuEdit->menuAction());
        menuGraph->addAction(menuDelete->menuAction());
        menuAdd->addAction(actionAddNode);
        menuAdd->addAction(actionAddEdge);
        menuEdit->addAction(actionEditEdge);
        menuDelete->addAction(actionDelNode);
        menuDelete->addAction(actionDelEdge);
        menuAlgorithms->addAction(actionBFS);
        menuAlgorithms->addAction(actionDFS);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionA_star);
        menuAlgorithms->addAction(actionDijkstra);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionColoring);
        menuAlgorithms->addAction(actionTopo_Sorting);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionEuler_Cycle);
        menuAlgorithms->addAction(actionHamiltonian_Cycle);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionFind_all_bridges);
        menuAlgorithms->addAction(actionFind_all_Articulation_nodes);
        menuAlgorithms->addAction(actionFInd_minimum_spanning_tree);
        menuAlgorithms->addAction(actionFind_weakly_connected_components);
        menuAlgorithms->addAction(actionFind_connected_components);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Graph->setText(QCoreApplication::translate("MainWindow", "&New Graph", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Graph->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Graph->setText(QCoreApplication::translate("MainWindow", "&Open Graph", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_Graph->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save &As", nullptr));
        actionCredits->setText(QCoreApplication::translate("MainWindow", "&Credits", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAddNode->setText(QCoreApplication::translate("MainWindow", "&Node", nullptr));
        actionAddEdge->setText(QCoreApplication::translate("MainWindow", "&Edge", nullptr));
        actionEditEdge->setText(QCoreApplication::translate("MainWindow", "&Edge", nullptr));
        actionDelNode->setText(QCoreApplication::translate("MainWindow", "&Node", nullptr));
        actionDelEdge->setText(QCoreApplication::translate("MainWindow", "&Edge", nullptr));
        actionBFS->setText(QCoreApplication::translate("MainWindow", "&BFS", nullptr));
        actionDFS->setText(QCoreApplication::translate("MainWindow", "&DFS", nullptr));
        actionColoring->setText(QCoreApplication::translate("MainWindow", "&Coloring", nullptr));
        actionTopo_Sorting->setText(QCoreApplication::translate("MainWindow", "&Topo Sorting", nullptr));
        actionEuler_Cycle->setText(QCoreApplication::translate("MainWindow", "&Euler Cycle", nullptr));
        actionHamiltonian_Cycle->setText(QCoreApplication::translate("MainWindow", "&Hamiltonian Cycle", nullptr));
        actionDijkstra->setText(QCoreApplication::translate("MainWindow", "Dijkstra", nullptr));
        actionFind_all_bridges->setText(QCoreApplication::translate("MainWindow", "Find all bridges", nullptr));
        actionFind_all_Articulation_nodes->setText(QCoreApplication::translate("MainWindow", "Find all Articulation nodes", nullptr));
        actionFind_connected_components->setText(QCoreApplication::translate("MainWindow", "Find strongly connected components", nullptr));
        actionFInd_minimum_spanning_tree->setText(QCoreApplication::translate("MainWindow", "Find minimum spanning tree", nullptr));
        actionFind_weakly_connected_components->setText(QCoreApplication::translate("MainWindow", "Find weakly connected components", nullptr));
        actionA_star->setText(QCoreApplication::translate("MainWindow", "A-star", nullptr));
        actionFind_all_cycles->setText(QCoreApplication::translate("MainWindow", "Find fundamental sets of cycle", nullptr));
        createGraphButton->setText(QCoreApplication::translate("MainWindow", "Create New Graph", nullptr));
        openGraphButton->setText(QCoreApplication::translate("MainWindow", "Open Existing Graph", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabVisualization), QCoreApplication::translate("MainWindow", "Visualization", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAdjMat), QCoreApplication::translate("MainWindow", "Adjency Matrix", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabIncMat), QCoreApplication::translate("MainWindow", "Incidence Matrix", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Animation interval", nullptr));
        algorithmsLabel->setText(QCoreApplication::translate("MainWindow", "Algorithms", nullptr));
        BFSbtn->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        DFSbtn->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        EulerBtn->setText(QCoreApplication::translate("MainWindow", "Euler", nullptr));
        HamiltonBtn->setText(QCoreApplication::translate("MainWindow", "Hamiltonian", nullptr));
        aStarBtn->setText(QCoreApplication::translate("MainWindow", "A-star", nullptr));
        dijkstraBtn->setText(QCoreApplication::translate("MainWindow", "Dijkstra", nullptr));
        coloringBtn->setText(QCoreApplication::translate("MainWindow", "Coloring", nullptr));
        topoSortBtn->setText(QCoreApplication::translate("MainWindow", "Topo sort", nullptr));
        bridgesBtn->setText(QCoreApplication::translate("MainWindow", "Find all bridges", nullptr));
        articulationNodeBtn->setText(QCoreApplication::translate("MainWindow", "Find all articulation nodes", nullptr));
        spanningTreeBtn->setText(QCoreApplication::translate("MainWindow", "Find minimum spanning tree", nullptr));
        cyclesBtn->setText(QCoreApplication::translate("MainWindow", "Find independent sets of cycle", nullptr));
        connectedComponentsBtn->setText(QCoreApplication::translate("MainWindow", "Find strongly connected components", nullptr));
        weaklyConnectedBtn->setText(QCoreApplication::translate("MainWindow", "Find weakly connected components", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuGraph->setTitle(QCoreApplication::translate("MainWindow", "&Graph", nullptr));
        menuAdd->setTitle(QCoreApplication::translate("MainWindow", "&Add", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "&Edit", nullptr));
        menuDelete->setTitle(QCoreApplication::translate("MainWindow", "&Delete", nullptr));
        menuAlgorithms->setTitle(QCoreApplication::translate("MainWindow", "&Algorithms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
