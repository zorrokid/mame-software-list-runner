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
#include <QSettings>
#include <QMessageBox>
#include "settingsdialog.h"
#include "settingnames.h"

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
    initializeSettings();

    setWindowTitle("Mame Software List Runner");
    setMinimumSize(160, 160);
    resize(480,320);
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

    scanHashFilesAction = new QAction(tr("Scan MAME hash files"));
    connect(scanHashFilesAction, &QAction::triggered, this, &MainWindow::slotScanHashFiles);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(scanHashFilesAction);
    fileMenu->addAction(openSettingsDialogAction);
    fileMenu->addAction(quitAction);

    aboutMenu = menuBar()->addMenu(tr("&Info"));
    aboutMenu->addAction(aboutQtAction);
}

void MainWindow::slotShowInfo()
{
    QApplication::aboutQt();
}

void MainWindow::slotOpenSettingsDialog()
{
    SettingsDialog *dialog = new SettingsDialog(this);
    dialog->show();
}

void MainWindow::slotScanHashFiles()
{
    QSettings settings;
    QString mameHashFilePath = settings.value(SettingNames::MameHashFilePath).toString();
    if (mameHashFilePath.isNull() || mameHashFilePath.isEmpty()){
        QMessageBox messageBox;
        messageBox.setText(tr("Set mame hash file path to settings using settings dialog first."));
        messageBox.exec();
        return;
    }
}

void MainWindow::initializeSettings()
{
    QCoreApplication::setOrganizationName("Zorrokid");
    QCoreApplication::setApplicationName("Mame Software List Runner");
}
