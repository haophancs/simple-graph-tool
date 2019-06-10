#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

class QLineEdit;
class QLabel;

class InputDialog : public QDialog
{
    Q_OBJECT
public:
    explicit InputDialog(QWidget *parent = nullptr, QString title = "Input", QList<QString> labelText = QList<QString>());

    static QStringList getStrings(QWidget *parent, QString title, QList<QString> labelText = QList<QString>(), bool *ok = nullptr);

private:
    QList<QLineEdit*> fields;
};

#endif // INPUTDIALOG_H
