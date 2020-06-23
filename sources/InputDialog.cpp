#include "headers/InputDialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

InputDialog::InputDialog(QWidget *parent, const QString& title, QList<QString> labelText) : QDialog(parent)
{
    auto *lytMain = new QFormLayout(this);
    setWindowTitle(title);
    for (auto & i : labelText) {
        auto tLabel = new QLabel(i, this);
        auto tLine = new QLineEdit(this);
        lytMain->addRow(tLabel, tLine);
        fields << tLine;
    }
    auto *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
              Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);
    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                   this, &InputDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &InputDialog::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList InputDialog::getStrings(QWidget *parent, QString title, QList<QString> labelText, bool *ok)
{
    auto *dialog = new InputDialog(parent, title, labelText);
    QStringList list;
    const int ret = dialog->exec();
    if (ok)
        *ok = ret != 0;
    if (ret) {
        for (auto field: dialog->fields) {
            list << field->text();
        }
    }
    dialog->deleteLater();
    return list;
}
