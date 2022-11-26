#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDate>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QLine line(QPoint (100,200),QPoint(150,210));
//    QLine newLine =line.translated(20,20);
//    qDebug() << "平移前的坐标点：" << line;
//    qDebug() << "平移后的坐标点：" << newLine;

    //获取当前日期
    QDate d = QDate::currentDate();
    //方式一
    qDebug()  <<"year: " << d.year() <<", moth: " << d.month() << ", day: " << d.day();
//    方式二
    QString str = d.toString("yyyy-MM-dd");
    qDebug() << "date str: " << str;

    //获取当前时间
   QTime curtime =  QTime::currentTime();
   //方式一
   qDebug() << "hour: " <<curtime.hour() << ", minute: " << curtime.minute() << ", second: " << curtime.second() << ", millisecond: "<< curtime.msec();
   //方式二
   QString strtm =  curtime.toString("hh:mm:ss.zzz");
   qDebug() << "格式化的日期：" << strtm;

   //获取当前日期+时间
   QDateTime dt = QDateTime::currentDateTime();
   //格式化
   QString strdt = dt.toString("yyyy/MM/dd hh:mm:ss ap");
   qDebug() << "当前日期+时间：" << strdt;
   //先取日期
   d = dt.date();
   qDebug()  <<"year: " << d.year() <<", moth: " << d.month() << ", day: " << d.day();
   //再取时间
  QTime t = dt.time();
   qDebug() << "hour: " <<t.hour() << ", minute: " << t.minute() << ", second: " << t.second() << ", millisecond: "<< t.msec();


}

MainWindow::~MainWindow()
{
    delete ui;
}

