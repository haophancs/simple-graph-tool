#include "widgets/headers/MultiComboboxDialog.h"

#include <QLabel>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDebug>

MultiComboboxDialog::MultiComboboxDialog(QWidget *parent, const QString &title, const QList<QString> &labelText)
        : QDialog(parent) {
    auto *lytMain = new QFormLayout(this);
    setWindowTitle(title);
    for (auto &i : labelText) {
        auto tLabel = new QLabel(i, this);
        auto tCombobox = new QComboBox(this);
        lytMain->addRow(tLabel, tCombobox);
        fields << tCombobox;
    }
    auto *buttonBox = new QDialogButtonBox
            (QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
             Qt::Horizontal, this);
    lytMain->addRow(buttonBox);
    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                        this, &MultiComboboxDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &MultiComboboxDialog::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList MultiComboboxDialog::getItems(QWidget *parent, const QString &title, const QStringList &labelText,
                                          const QList<QStringList> &itemLists, bool *ok) {

    auto *dialog = new MultiComboboxDialog(parent, title, labelText);
    for (int i = 0; i < dialog->fields.size(); ++i)
        dialog->fields[i]->addItems(itemLists[i]);
    QStringList list;
    const int ret = dialog->exec();
    if (ok) *ok = ret != 0;
    if (ret) {
        for (auto field: dialog->fields) {
            list << field->currentText();
            qDebug() << field->currentText();
        }
    }
    dialog->deleteLater();
    return list;
}
