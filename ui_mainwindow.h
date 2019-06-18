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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QWidget *entry_widget;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_9;
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
    QWidget *working_widget;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *main_layout;
    QTabWidget *tabWidget;
    QWidget *tab_drawing;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *draw_layout;
    QWidget *tab_table;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *table_layout;
    QFrame *line;
    QTextEdit *console_text;
    QWidget *utils;
    QVBoxLayout *verticalLayout;
    QFrame *line_2;
    QVBoxLayout *button_layout;
    QVBoxLayout *verticalLayout_7;
    QLabel *properties_label;
    QTableWidget *propertiesTable;
    QFrame *line_4;
    QLabel *algorithms_label;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *BFSbtn;
    QPushButton *DFSbtn;
    QHBoxLayout *horizontalLayout_8;
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
        MainWindow->resize(1024, 768);
        MainWindow->setMinimumSize(QSize(720, 540));
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
        entry_widget = new QWidget(centralWidget);
        entry_widget->setObjectName(QStringLiteral("entry_widget"));
        horizontalLayout_12 = new QHBoxLayout(entry_widget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_6);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_8);

        createGraphButton = new QPushButton(entry_widget);
        createGraphButton->setObjectName(QStringLiteral("createGraphButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(createGraphButton->sizePolicy().hasHeightForWidth());
        createGraphButton->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(createGraphButton);

        openGraphButton = new QPushButton(entry_widget);
        openGraphButton->setObjectName(QStringLiteral("openGraphButton"));
        sizePolicy.setHeightForWidth(openGraphButton->sizePolicy().hasHeightForWidth());
        openGraphButton->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(openGraphButton);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_9);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_7);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);


        horizontalLayout_12->addLayout(verticalLayout_9);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);


        horizontalLayout->addWidget(entry_widget);

        working_widget = new QWidget(centralWidget);
        working_widget->setObjectName(QStringLiteral("working_widget"));
        horizontalLayout_9 = new QHBoxLayout(working_widget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        main_layout = new QVBoxLayout();
        main_layout->setSpacing(6);
        main_layout->setObjectName(QStringLiteral("main_layout"));
        main_layout->setContentsMargins(6, -1, -1, -1);
        tabWidget = new QTabWidget(working_widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_drawing = new QWidget();
        tab_drawing->setObjectName(QStringLiteral("tab_drawing"));
        horizontalLayout_2 = new QHBoxLayout(tab_drawing);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        draw_layout = new QVBoxLayout();
        draw_layout->setSpacing(6);
        draw_layout->setObjectName(QStringLiteral("draw_layout"));

        horizontalLayout_2->addLayout(draw_layout);

        tabWidget->addTab(tab_drawing, QString());
        tab_table = new QWidget();
        tab_table->setObjectName(QStringLiteral("tab_table"));
        verticalLayout_3 = new QVBoxLayout(tab_table);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        table_layout = new QVBoxLayout();
        table_layout->setSpacing(0);
        table_layout->setObjectName(QStringLiteral("table_layout"));

        verticalLayout_3->addLayout(table_layout);

        tabWidget->addTab(tab_table, QString());

        main_layout->addWidget(tabWidget);

        line = new QFrame(working_widget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        main_layout->addWidget(line);

        console_text = new QTextEdit(working_widget);
        console_text->setObjectName(QStringLiteral("console_text"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(console_text->sizePolicy().hasHeightForWidth());
        console_text->setSizePolicy(sizePolicy1);
        console_text->setMaximumSize(QSize(16777215, 130));

        main_layout->addWidget(console_text);


        horizontalLayout_9->addLayout(main_layout);

        utils = new QWidget(working_widget);
        utils->setObjectName(QStringLiteral("utils"));
        utils->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(utils);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line_2 = new QFrame(utils);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        button_layout = new QVBoxLayout();
        button_layout->setSpacing(6);
        button_layout->setObjectName(QStringLiteral("button_layout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, -1, -1, 6);
        properties_label = new QLabel(utils);
        properties_label->setObjectName(QStringLiteral("properties_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(properties_label->sizePolicy().hasHeightForWidth());
        properties_label->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(properties_label);

        propertiesTable = new QTableWidget(utils);
        propertiesTable->setObjectName(QStringLiteral("propertiesTable"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(propertiesTable->sizePolicy().hasHeightForWidth());
        propertiesTable->setSizePolicy(sizePolicy3);
        propertiesTable->setMaximumSize(QSize(16777215, 16777215));
        propertiesTable->horizontalHeader()->setVisible(false);

        verticalLayout_7->addWidget(propertiesTable);


        button_layout->addLayout(verticalLayout_7);

        line_4 = new QFrame(utils);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        button_layout->addWidget(line_4);

        algorithms_label = new QLabel(utils);
        algorithms_label->setObjectName(QStringLiteral("algorithms_label"));

        button_layout->addWidget(algorithms_label);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        BFSbtn = new QPushButton(utils);
        BFSbtn->setObjectName(QStringLiteral("BFSbtn"));

        horizontalLayout_6->addWidget(BFSbtn);

        DFSbtn = new QPushButton(utils);
        DFSbtn->setObjectName(QStringLiteral("DFSbtn"));

        horizontalLayout_6->addWidget(DFSbtn);


        button_layout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        EulerBtn = new QPushButton(utils);
        EulerBtn->setObjectName(QStringLiteral("EulerBtn"));

        horizontalLayout_8->addWidget(EulerBtn);

        HamiltonBtn = new QPushButton(utils);
        HamiltonBtn->setObjectName(QStringLiteral("HamiltonBtn"));

        horizontalLayout_8->addWidget(HamiltonBtn);


        button_layout->addLayout(horizontalLayout_8);

        coloringBtn = new QPushButton(utils);
        coloringBtn->setObjectName(QStringLiteral("coloringBtn"));

        button_layout->addWidget(coloringBtn);

        topoSortBtn = new QPushButton(utils);
        topoSortBtn->setObjectName(QStringLiteral("topoSortBtn"));

        button_layout->addWidget(topoSortBtn);

        bridgesBtn = new QPushButton(utils);
        bridgesBtn->setObjectName(QStringLiteral("bridgesBtn"));

        button_layout->addWidget(bridgesBtn);

        shortestPathBtn = new QPushButton(utils);
        shortestPathBtn->setObjectName(QStringLiteral("shortestPathBtn"));

        button_layout->addWidget(shortestPathBtn);

        articulationNodeBtn = new QPushButton(utils);
        articulationNodeBtn->setObjectName(QStringLiteral("articulationNodeBtn"));

        button_layout->addWidget(articulationNodeBtn);

        spanningTreeBtn = new QPushButton(utils);
        spanningTreeBtn->setObjectName(QStringLiteral("spanningTreeBtn"));

        button_layout->addWidget(spanningTreeBtn);

        weaklyConnectedBtn = new QPushButton(utils);
        weaklyConnectedBtn->setObjectName(QStringLiteral("weaklyConnectedBtn"));

        button_layout->addWidget(weaklyConnectedBtn);

        connectedComponentsBtn = new QPushButton(utils);
        connectedComponentsBtn->setObjectName(QStringLiteral("connectedComponentsBtn"));

        button_layout->addWidget(connectedComponentsBtn);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        button_layout->addItem(verticalSpacer_10);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        button_layout->addItem(verticalSpacer);


        verticalLayout->addLayout(button_layout);


        horizontalLayout_9->addWidget(utils);


        horizontalLayout->addWidget(working_widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_drawing), QApplication::translate("MainWindow", "Drawing View", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_table), QApplication::translate("MainWindow", "Matrix View", Q_NULLPTR));
        properties_label->setText(QApplication::translate("MainWindow", "Properties", Q_NULLPTR));
        algorithms_label->setText(QApplication::translate("MainWindow", "Algorithms", Q_NULLPTR));
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
