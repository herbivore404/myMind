#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "textwidget.h"
#include "textdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //一般在qt的构造函数中进行初始化
   #if 1
        //创建窗口对象
        //没有指定父对象，独立窗口
        //通过show()显示
        TextWidget* w = new TextWidget;
        //显示当前窗口
        w->show();
#else
    //创建窗口对象
    // explicit TextWidget(QWidget *parent = nullptr);
    //有指定父对象，不是独立窗口，没有边框
    TextWidget* w = new TextWidget(this);
#endif

#if 0
    //创建对话框窗口
    TextDialog* dig = new TextDialog(this);
    //非模态
    dig->show();
 #else
    //创建对话框窗口
    TextDialog* dig = new TextDialog(this);
    //模态，exc()
    //阻塞程序的执行
    dig->exec();
#endif


}

MainWindow::~MainWindow()
{
    delete ui;
}

