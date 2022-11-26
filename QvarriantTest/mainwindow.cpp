#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //整型数
    int value = dataPlus(10,20).toInt();
    //字符串
    QString str = dataPlus("hello", "world").toString();

    qDebug() << "int value: " << value;
    qDebug() << "string value: " << str;

    Person p;
    p.id = 250;
    p.name = "lemon";
#if 0
    QVariant v;
    v.setValue(p);
#else
    QVariant v = QVariant::fromValue(p);
#endif

    //取出v对象中数据
    if(v.canConvert<Person>())
    {
        Person tmp = v.value<Person>();
        qDebug() << "id: " << tmp.id << ", name: " << tmp.name;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVariant MainWindow::dataPlus(QVariant a, QVariant b)
{
    //判断类型
    QVariant ret;
    if(a.type() == QVariant::Int && b.type() ==QVariant::Int){
        ret = QVariant(a.toInt() + b.toInt());
    }
    else if(a.type() == QVariant::String && b.type() ==QVariant::String){
//        ret = QVariant(a.toString() + b.toString());
        ret.setValue(a.toString() + b.toString());
    }
    return ret;
}

