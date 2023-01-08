#include "settingsdialog.h"
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QSettings>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    QFormLayout *formLayout = new QFormLayout();
    mameHashPathEdit = new QLineEdit();
    QSettings settings;
    QString mameHashFilePath = settings.value("mamePaths/hashFilesPath").toString();
    mameHashPathEdit->setText(mameHashFilePath);

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
                QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    mameHashPathEdit->setText(dir);
    QSettings settings;
    settings.setValue("mamePaths/hashFilesPath", dir);
}
