#include "author.h"
#include "ui_author.h"

author::author(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::author)
{
    ui->setupUi(this);
    //点击子窗口按钮，触发sSlot


}

author::~author()
{
    delete ui;
}
