/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QAction *actionAddArc;
    QAction *actionEditArc;
    QAction *actionDelNode;
    QAction *actionDelArc;
    QAction *actionBFS;
    QAction *actionDFS;
    QAction *actionColoring;
    QAction *actionTopo_Sorting;
    QAction *actionEuler_Cycle;
    QAction *actionHamiltonian_Cycle;
    QAction *actionFind_shortest_path;
    QAction *actionFind_all_bridges;
    QAction *actionFind_all_Articulation_nodes;
    QAction *actionFind_connected_components;
    QAction *actionFInd_minimum_spanning_tree;
    QAction *actionFind_weakly_connected_components;
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
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    QWidget *tabVisualization;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *visualLayout;
    QWidget *tabMatrix;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *matrixLayout;
    QFrame *line;
    QTextEdit *consoleText;
    QWidget *utils;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *propertiesLayout;
    QLabel *propertiesLabel;
    QFrame *line_4;
    QLabel *algorithmsLabel;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BFSbtn;
    QPushButton *DFSbtn;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *EulerBtn;
    QPushButton *HamiltonBtn;
    QPushButton *coloringBtn;
    QPushButton *topoSortBtn;
    QPushButton *bridgesBtn;
    QPushButton *shortestPathBtn;
    QPushButton *articulationNodeBtn;
    QPushButton *spanningTreeBtn;
    QPushButton *weaklyConnectedBtn;
    QPushButton *connectedComponentsBtn;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2024, 1254);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1280, 960));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actionNew_Graph = new QAction(MainWindow);
        actionNew_Graph->setObjectName(QStringLiteral("actionNew_Graph"));
        actionOpen_Graph = new QAction(MainWindow);
        actionOpen_Graph->setObjectName(QStringLiteral("actionOpen_Graph"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionCredits = new QAction(MainWindow);
        actionCredits->setObjectName(QStringLiteral("actionCredits"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAddNode = new QAction(MainWindow);
        actionAddNode->setObjectName(QStringLiteral("actionAddNode"));
        actionAddArc = new QAction(MainWindow);
        actionAddArc->setObjectName(QStringLiteral("actionAddArc"));
        actionEditArc = new QAction(MainWindow);
        actionEditArc->setObjectName(QStringLiteral("actionEditArc"));
        actionDelNode = new QAction(MainWindow);
        actionDelNode->setObjectName(QStringLiteral("actionDelNode"));
        actionDelArc = new QAction(MainWindow);
        actionDelArc->setObjectName(QStringLiteral("actionDelArc"));
        actionBFS = new QAction(MainWindow);
        actionBFS->setObjectName(QStringLiteral("actionBFS"));
        actionDFS = new QAction(MainWindow);
        actionDFS->setObjectName(QStringLiteral("actionDFS"));
        actionColoring = new QAction(MainWindow);
        actionColoring->setObjectName(QStringLiteral("actionColoring"));
        actionTopo_Sorting = new QAction(MainWindow);
        actionTopo_Sorting->setObjectName(QStringLiteral("actionTopo_Sorting"));
        actionEuler_Cycle = new QAction(MainWindow);
        actionEuler_Cycle->setObjectName(QStringLiteral("actionEuler_Cycle"));
        actionHamiltonian_Cycle = new QAction(MainWindow);
        actionHamiltonian_Cycle->setObjectName(QStringLiteral("actionHamiltonian_Cycle"));
        actionFind_shortest_path = new QAction(MainWindow);
        actionFind_shortest_path->setObjectName(QStringLiteral("actionFind_shortest_path"));
        actionFind_all_bridges = new QAction(MainWindow);
        actionFind_all_bridges->setObjectName(QStringLiteral("actionFind_all_bridges"));
        actionFind_all_Articulation_nodes = new QAction(MainWindow);
        actionFind_all_Articulation_nodes->setObjectName(QStringLiteral("actionFind_all_Articulation_nodes"));
        actionFind_connected_components = new QAction(MainWindow);
        actionFind_connected_components->setObjectName(QStringLiteral("actionFind_connected_components"));
        actionFInd_minimum_spanning_tree = new QAction(MainWindow);
        actionFInd_minimum_spanning_tree->setObjectName(QStringLiteral("actionFInd_minimum_spanning_tree"));
        actionFind_weakly_connected_components = new QAction(MainWindow);
        actionFind_weakly_connected_components->setObjectName(QStringLiteral("actionFind_weakly_connected_components"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        entryWidget = new QWidget(centralWidget);
        entryWidget->setObjectName(QStringLiteral("entryWidget"));
        horizontalLayout_12 = new QHBoxLayout(entryWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        createGraphButton = new QPushButton(entryWidget);
        createGraphButton->setObjectName(QStringLiteral("createGraphButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(createGraphButton->sizePolicy().hasHeightForWidth());
        createGraphButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(createGraphButton);

        openGraphButton = new QPushButton(entryWidget);
        openGraphButton->setObjectName(QStringLiteral("openGraphButton"));
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
        workingWidget->setObjectName(QStringLiteral("workingWidget"));
        horizontalLayout_3 = new QHBoxLayout(workingWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter = new QSplitter(workingWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        mainLayout = new QVBoxLayout(layoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(6, 0, 0, 0);
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabVisualization = new QWidget();
        tabVisualization->setObjectName(QStringLiteral("tabVisualization"));
        horizontalLayout_2 = new QHBoxLayout(tabVisualization);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        visualLayout = new QVBoxLayout();
        visualLayout->setSpacing(6);
        visualLayout->setObjectName(QStringLiteral("visualLayout"));

        horizontalLayout_2->addLayout(visualLayout);

        tabWidget->addTab(tabVisualization, QString());
        tabMatrix = new QWidget();
        tabMatrix->setObjectName(QStringLiteral("tabMatrix"));
        verticalLayout_3 = new QVBoxLayout(tabMatrix);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        matrixLayout = new QVBoxLayout();
        matrixLayout->setSpacing(0);
        matrixLayout->setObjectName(QStringLiteral("matrixLayout"));

        verticalLayout_3->addLayout(matrixLayout);

        tabWidget->addTab(tabMatrix, QString());

        mainLayout->addWidget(tabWidget);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        mainLayout->addWidget(line);

        consoleText = new QTextEdit(layoutWidget);
        consoleText->setObjectName(QStringLiteral("consoleText"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(consoleText->sizePolicy().hasHeightForWidth());
        consoleText->setSizePolicy(sizePolicy2);
        consoleText->setMaximumSize(QSize(16777215, 250));

        mainLayout->addWidget(consoleText);

        splitter->addWidget(layoutWidget);
        utils = new QWidget(splitter);
        utils->setObjectName(QStringLiteral("utils"));
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
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        propertiesLayout = new QVBoxLayout();
        propertiesLayout->setSpacing(6);
        propertiesLayout->setObjectName(QStringLiteral("propertiesLayout"));
        propertiesLayout->setContentsMargins(-1, -1, -1, 6);
        propertiesLabel = new QLabel(utils);
        propertiesLabel->setObjectName(QStringLiteral("propertiesLabel"));
        sizePolicy3.setHeightForWidth(propertiesLabel->sizePolicy().hasHeightForWidth());
        propertiesLabel->setSizePolicy(sizePolicy3);

        propertiesLayout->addWidget(propertiesLabel);


        verticalLayout->addLayout(propertiesLayout);

        line_4 = new QFrame(utils);
        line_4->setObjectName(QStringLiteral("line_4"));
        sizePolicy3.setHeightForWidth(line_4->sizePolicy().hasHeightForWidth());
        line_4->setSizePolicy(sizePolicy3);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        algorithmsLabel = new QLabel(utils);
        algorithmsLabel->setObjectName(QStringLiteral("algorithmsLabel"));
        sizePolicy3.setHeightForWidth(algorithmsLabel->sizePolicy().hasHeightForWidth());
        algorithmsLabel->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(algorithmsLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        BFSbtn = new QPushButton(utils);
        BFSbtn->setObjectName(QStringLiteral("BFSbtn"));
        sizePolicy3.setHeightForWidth(BFSbtn->sizePolicy().hasHeightForWidth());
        BFSbtn->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(BFSbtn);

        DFSbtn = new QPushButton(utils);
        DFSbtn->setObjectName(QStringLiteral("DFSbtn"));
        sizePolicy3.setHeightForWidth(DFSbtn->sizePolicy().hasHeightForWidth());
        DFSbtn->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(DFSbtn);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        EulerBtn = new QPushButton(utils);
        EulerBtn->setObjectName(QStringLiteral("EulerBtn"));
        sizePolicy3.setHeightForWidth(EulerBtn->sizePolicy().hasHeightForWidth());
        EulerBtn->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(EulerBtn);

        HamiltonBtn = new QPushButton(utils);
        HamiltonBtn->setObjectName(QStringLiteral("HamiltonBtn"));
        sizePolicy3.setHeightForWidth(HamiltonBtn->sizePolicy().hasHeightForWidth());
        HamiltonBtn->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(HamiltonBtn);


        verticalLayout->addLayout(horizontalLayout_5);

        coloringBtn = new QPushButton(utils);
        coloringBtn->setObjectName(QStringLiteral("coloringBtn"));
        sizePolicy3.setHeightForWidth(coloringBtn->sizePolicy().hasHeightForWidth());
        coloringBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(coloringBtn);

        topoSortBtn = new QPushButton(utils);
        topoSortBtn->setObjectName(QStringLiteral("topoSortBtn"));
        sizePolicy3.setHeightForWidth(topoSortBtn->sizePolicy().hasHeightForWidth());
        topoSortBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(topoSortBtn);

        bridgesBtn = new QPushButton(utils);
        bridgesBtn->setObjectName(QStringLiteral("bridgesBtn"));
        sizePolicy3.setHeightForWidth(bridgesBtn->sizePolicy().hasHeightForWidth());
        bridgesBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(bridgesBtn);

        shortestPathBtn = new QPushButton(utils);
        shortestPathBtn->setObjectName(QStringLiteral("shortestPathBtn"));
        sizePolicy3.setHeightForWidth(shortestPathBtn->sizePolicy().hasHeightForWidth());
        shortestPathBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(shortestPathBtn);

        articulationNodeBtn = new QPushButton(utils);
        articulationNodeBtn->setObjectName(QStringLiteral("articulationNodeBtn"));
        sizePolicy3.setHeightForWidth(articulationNodeBtn->sizePolicy().hasHeightForWidth());
        articulationNodeBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(articulationNodeBtn);

        spanningTreeBtn = new QPushButton(utils);
        spanningTreeBtn->setObjectName(QStringLiteral("spanningTreeBtn"));
        sizePolicy3.setHeightForWidth(spanningTreeBtn->sizePolicy().hasHeightForWidth());
        spanningTreeBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(spanningTreeBtn);

        weaklyConnectedBtn = new QPushButton(utils);
        weaklyConnectedBtn->setObjectName(QStringLiteral("weaklyConnectedBtn"));
        sizePolicy3.setHeightForWidth(weaklyConnectedBtn->sizePolicy().hasHeightForWidth());
        weaklyConnectedBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(weaklyConnectedBtn);

        connectedComponentsBtn = new QPushButton(utils);
        connectedComponentsBtn->setObjectName(QStringLiteral("connectedComponentsBtn"));
        sizePolicy3.setHeightForWidth(connectedComponentsBtn->sizePolicy().hasHeightForWidth());
        connectedComponentsBtn->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(connectedComponentsBtn);

        verticalSpacer_10 = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        verticalSpacer = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        splitter->addWidget(utils);

        horizontalLayout_3->addWidget(splitter);


        horizontalLayout->addWidget(workingWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 2024, 37));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuGraph = new QMenu(menuBar);
        menuGraph->setObjectName(QStringLiteral("menuGraph"));
        menuAdd = new QMenu(menuGraph);
        menuAdd->setObjectName(QStringLiteral("menuAdd"));
        menuEdit = new QMenu(menuGraph);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuDelete = new QMenu(menuGraph);
        menuDelete->setObjectName(QStringLiteral("menuDelete"));
        menuAlgorithms = new QMenu(menuBar);
        menuAlgorithms->setObjectName(QStringLiteral("menuAlgorithms"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        menuAdd->addAction(actionAddArc);
        menuEdit->addAction(actionEditArc);
        menuDelete->addAction(actionDelNode);
        menuDelete->addAction(actionDelArc);
        menuAlgorithms->addAction(actionBFS);
        menuAlgorithms->addAction(actionDFS);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionColoring);
        menuAlgorithms->addAction(actionTopo_Sorting);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionEuler_Cycle);
        menuAlgorithms->addAction(actionHamiltonian_Cycle);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionFind_shortest_path);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionNew_Graph->setText(QApplication::translate("MainWindow", "&New Graph", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew_Graph->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen_Graph->setText(QApplication::translate("MainWindow", "&Open Graph", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen_Graph->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "&Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save &As", Q_NULLPTR));
        actionCredits->setText(QApplication::translate("MainWindow", "&Credits", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Alt+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAddNode->setText(QApplication::translate("MainWindow", "&Node", Q_NULLPTR));
        actionAddArc->setText(QApplication::translate("MainWindow", "&Arc", Q_NULLPTR));
        actionEditArc->setText(QApplication::translate("MainWindow", "&Arc", Q_NULLPTR));
        actionDelNode->setText(QApplication::translate("MainWindow", "&Node", Q_NULLPTR));
        actionDelArc->setText(QApplication::translate("MainWindow", "&Arc", Q_NULLPTR));
        actionBFS->setText(QApplication::translate("MainWindow", "&BFS", Q_NULLPTR));
        actionDFS->setText(QApplication::translate("MainWindow", "&DFS", Q_NULLPTR));
        actionColoring->setText(QApplication::translate("MainWindow", "&Coloring", Q_NULLPTR));
        actionTopo_Sorting->setText(QApplication::translate("MainWindow", "&Topo Sorting", Q_NULLPTR));
        actionEuler_Cycle->setText(QApplication::translate("MainWindow", "&Euler Cycle", Q_NULLPTR));
        actionHamiltonian_Cycle->setText(QApplication::translate("MainWindow", "&Hamiltonian Cycle", Q_NULLPTR));
        actionFind_shortest_path->setText(QApplication::translate("MainWindow", "Find shortest path", Q_NULLPTR));
        actionFind_all_bridges->setText(QApplication::translate("MainWindow", "Find all bridges", Q_NULLPTR));
        actionFind_all_Articulation_nodes->setText(QApplication::translate("MainWindow", "Find all Articulation nodes", Q_NULLPTR));
        actionFind_connected_components->setText(QApplication::translate("MainWindow", "Find strongly connected components", Q_NULLPTR));
        actionFInd_minimum_spanning_tree->setText(QApplication::translate("MainWindow", "Find minimum spanning tree", Q_NULLPTR));
        actionFind_weakly_connected_components->setText(QApplication::translate("MainWindow", "Find weakly connected components", Q_NULLPTR));
        createGraphButton->setText(QApplication::translate("MainWindow", "Create New Graph", Q_NULLPTR));
        openGraphButton->setText(QApplication::translate("MainWindow", "Open Existing Graph", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabVisualization), QApplication::translate("MainWindow", "Visual View", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabMatrix), QApplication::translate("MainWindow", "Matrix View", Q_NULLPTR));
        propertiesLabel->setText(QApplication::translate("MainWindow", "Properties", Q_NULLPTR));
        algorithmsLabel->setText(QApplication::translate("MainWindow", "Algorithms", Q_NULLPTR));
        BFSbtn->setText(QApplication::translate("MainWindow", "BFS", Q_NULLPTR));
        DFSbtn->setText(QApplication::translate("MainWindow", "DFS", Q_NULLPTR));
        EulerBtn->setText(QApplication::translate("MainWindow", "Euler", Q_NULLPTR));
        HamiltonBtn->setText(QApplication::translate("MainWindow", "Hamiltonian", Q_NULLPTR));
        coloringBtn->setText(QApplication::translate("MainWindow", "Coloring", Q_NULLPTR));
        topoSortBtn->setText(QApplication::translate("MainWindow", "Topo sorting", Q_NULLPTR));
        bridgesBtn->setText(QApplication::translate("MainWindow", "Find all bridges", Q_NULLPTR));
        shortestPathBtn->setText(QApplication::translate("MainWindow", " Find shortest path", Q_NULLPTR));
        articulationNodeBtn->setText(QApplication::translate("MainWindow", "Find all Articulation nodes", Q_NULLPTR));
        spanningTreeBtn->setText(QApplication::translate("MainWindow", "Find minimum spanning tree", Q_NULLPTR));
        weaklyConnectedBtn->setText(QApplication::translate("MainWindow", "Find weakly connected components", Q_NULLPTR));
        connectedComponentsBtn->setText(QApplication::translate("MainWindow", "Find strongly connected components", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuGraph->setTitle(QApplication::translate("MainWindow", "&Graph", Q_NULLPTR));
        menuAdd->setTitle(QApplication::translate("MainWindow", "&Add", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", Q_NULLPTR));
        menuDelete->setTitle(QApplication::translate("MainWindow", "&Delete", Q_NULLPTR));
        menuAlgorithms->setTitle(QApplication::translate("MainWindow", "&Algorithms", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
