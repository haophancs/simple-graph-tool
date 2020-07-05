#ifndef MULTILINEINPUTDIALOG_H
#define MULTILINEINPUTDIALOG_H

#include <QDialog>
#include <QtWidgets/QComboBox>

class QLineEdit;

class QLabel;

class MultiLineInputDialog : public QDialog {
Q_OBJECT
public:
    explicit MultiLineInputDialog(QWidget *parent = nullptr, const QString &title = "Input",
                                  const QList<QString> &labelText = QList<QString>());

    static QStringList
    getStrings(QWidget *parent, const QString &title, const QList<QString> &labelText = QList<QString>(),
               bool *ok = nullptr);

private:
    QList<QLineEdit *> fields;
};

#endif // MULTILINEINPUTDIALOG_H
