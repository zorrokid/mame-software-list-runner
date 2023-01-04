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
    ui->setupUi(this);
    setFixedSize(500, 500);
    m_button = new QPushButton("Test", this);
    m_button->setGeometry(10, 10, 80, 30);

    connect(m_button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

