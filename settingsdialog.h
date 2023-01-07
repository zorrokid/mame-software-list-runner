#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>

class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    SettingsDialog(QWidget *parent = nullptr);
private slots:
    void slotOpenFileSelector();
};

#endif // SETTINGSDIALOG_H
