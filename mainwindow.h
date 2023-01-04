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


//signals:
 //   void counterReached();
protected:
#ifndef QT_NO_CONTEXTMENU
   //void contextMenuEvent(QContextMenuEvent *event) override;
#endif


private slots:
    //void slotButtonClicked(bool checked);
    void slotShowInfo();
    void slotOpenSettingsDialog();

private:
    /*QPushButton *m_button;
    int m_counter;*/
    QMenu *fileMenu;
    QMenu *aboutMenu;
    QAction *openSettingsDialogAction;
    QAction *aboutQtAction;
    QAction *quitAction;
    QLabel *infoLabel;

    void createActions();
    void createMenus();


};
#endif // MAINWINDOW_H
