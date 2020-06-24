#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

class QLineEdit;

class QLabel;

class InputDialog : public QDialog {
Q_OBJECT
public:
    explicit InputDialog(QWidget *parent = nullptr, const QString &title = "Input",
                         const QList<QString>& labelText = QList<QString>());

    static QStringList
    getStrings(QWidget *parent, const QString& title, const QList<QString>& labelText = QList<QString>(), bool *ok = nullptr);

private:
    QList<QLineEdit *> fields;
};

#endif // INPUTDIALOG_H
