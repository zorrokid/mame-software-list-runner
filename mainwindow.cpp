#include "mainwindow.h"
#include <QPushButton>
#include <QProgressBar>
#include <QApplication>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QStatusBar>
#include <QMenu>
#include "settingsdialog.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget();
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option or right click to invoke context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget();
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    // layout should be always set to central widget (instead of main window)
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle("Mame Software List Runner");
    setMinimumSize(160, 160);
    resize(480,320);

    /*m_counter = 0;
    setFixedSize(500, 500);
    m_button = new QPushButton("Test", this);
    m_button->setGeometry(10, 10, 80, 30);
    m_button->setCheckable(true);

    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    connect(this, SIGNAL(counterReached()), QApplication::instance(), SLOT(quit()));

    // connect(m_button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 40, 180, 30);

    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 80, 180, 30);

    QObject::connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

    QPushButton *buttonInfo = new QPushButton("Info", this);
    buttonInfo->setGeometry(50, 100, 80, 30);
    connect(buttonInfo, SIGNAL(clicked()), this, SLOT(slotShowInfo()));

    QPushButton *buttonQuit = new QPushButton("Quit", this);
    buttonQuit->setGeometry(10, 120, 80, 30);

    connect(buttonQuit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    */
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    aboutQtAction = new QAction(tr("About Qt"), this);
    connect(aboutQtAction, &QAction::triggered, this, &MainWindow::slotShowInfo);

    quitAction = new QAction(tr("Quit"), this);
    connect(quitAction, &QAction::triggered, QApplication::instance(), &QApplication::quit);

    openSettingsDialogAction = new QAction(tr("Open settings dialog"));
    connect(openSettingsDialogAction, &QAction::triggered, this, &MainWindow::slotOpenSettingsDialog);

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openSettingsDialogAction);
    fileMenu->addAction(quitAction);

    aboutMenu = menuBar()->addMenu(tr("&Info"));
    aboutMenu->addAction(aboutQtAction);


}

/*void MainWindow::slotButtonClicked(bool checked)
{
    if (checked) {
        m_button->setText("Checked");
    } else {
        m_button->setText("Hellow world");
    }
    m_counter++;
    if(m_counter == 10) {
        emit counterReached();
    }
}*/

void MainWindow::slotShowInfo()
{
    QApplication::aboutQt();
}

void MainWindow::slotOpenSettingsDialog()
{
    SettingsDialog *dialog = new SettingsDialog(this);
    dialog->show();
}

