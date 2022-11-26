#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_me = new Me;
    m_girl = new GirlFriend;
    connect(m_girl, &GirlFriend::hungry, m_me, &Me::eat);
    connect(ui->hungry, &QPushButton::clicked, this, &MainWindow::hungrySlot);

    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hungrySlot()
{
    //发射自定义信号
    emit m_girl->hungry();
}

