#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QMenu;
class QAction;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void slotShowInfo();
    void slotOpenSettingsDialog();

private:
    QMenu *fileMenu;
    QMenu *aboutMenu;
    QAction *openSettingsDialogAction;
    QAction *aboutQtAction;
    QAction *quitAction;
    QAction *scanHashFilesAction;
    QLabel *infoLabel;

    void createActions();
    void createMenus();
    void initializeSettings();


};
#endif // MAINWINDOW_H
