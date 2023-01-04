#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QProgressBar>
#include <QApplication>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    m_counter = 0;
    ui->setupUi(this);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotButtonClicked(bool checked)
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
}

void MainWindow::slotShowInfo()
{
    QApplication::aboutQt();
}

