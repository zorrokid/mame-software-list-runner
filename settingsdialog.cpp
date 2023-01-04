#include "settingsdialog.h"
#include <QPushButton>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    QPushButton *buttonInfo = new QPushButton("Info", this);
    buttonInfo->setGeometry(10, 10, 80, 30);

    setWindowTitle(tr("Settings"));
    setMinimumSize(160, 160);
    resize(480,320);

}
