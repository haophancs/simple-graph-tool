#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QCheckBox;

class QDialogButtonBox;

class QGroupBox;

class QLabel;

class QLineEdit;

class QPushButton;

QT_END_NAMESPACE

class GraphOptionDialog : public QDialog {
Q_OBJECT

public:
    explicit GraphOptionDialog(QWidget *parent = nullptr);

    static void initGraph(QWidget *parent, bool &weighted, bool &directed, int &node_num, bool &ok);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *weightedCheckBox;
    QCheckBox *directedCheckBox;
    QDialogButtonBox *buttonBox;
};

#endif