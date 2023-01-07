#include "settingsdialog.h"
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QFileDialog>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    QFormLayout *formLayout = new QFormLayout();
    mameHashPathEdit = new QLineEdit();
    QPushButton *buttonInfo = new QPushButton("Browse", this);
    QHBoxLayout *mamePathLayout = new QHBoxLayout();
    mamePathLayout->addWidget(mameHashPathEdit);
    mamePathLayout->addWidget(buttonInfo);
    formLayout->addRow(tr("Path to MAME hash files folder"), mamePathLayout);
    setLayout(formLayout);
    connect(buttonInfo, SIGNAL(clicked()), this, SLOT(slotOpenFileSelector()));
    setWindowTitle(tr("Settings"));
    setMinimumSize(160, 160);
    resize(480,320);
}

void SettingsDialog::slotOpenFileSelector()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open directory with MAME hash files"),
                "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    mameHashPathEdit->setText(dir);
}
