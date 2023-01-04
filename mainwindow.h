#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void counterReached();
private slots:
    void slotButtonClicked(bool checked);

private:
    Ui::MainWindow *ui;
    QPushButton *m_button;
    int m_counter;
};
#endif // MAINWINDOW_H
