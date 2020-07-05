#ifndef MULTICOMBOBOXDIALOG_H
#define MULTICOMBOBOXDIALOG_H

#include <QDialog>
#include <QtWidgets/QComboBox>

class QComboBox;

class QLabel;

class MultiComboboxDialog : public QDialog {
Q_OBJECT
public:
    explicit MultiComboboxDialog(QWidget *parent = nullptr, const QString &title = "Input",
                                 const QList<QString> &labelText = QList<QString>());

    static QStringList
    getItems(QWidget *parent, const QString &title, const QStringList &labelText = QStringList(),
             const QList<QStringList> &itemLists = QList<QStringList>(), bool *ok = nullptr);

private:
    QList<QComboBox *> fields;
};

#endif // MULTICOMBOBOXDIALOG_H

