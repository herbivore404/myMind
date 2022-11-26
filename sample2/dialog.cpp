#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPlainTextEdit>

void Dialog::iniUI()
{
    checkBoxUnderline = new QCheckBox(tr("Underline"));
    checkBoxItalic = new QCheckBox(tr("Itralic"));
    checkBoxBold = new QCheckBox(tr("Bold"));
    QHBoxLayout *HLayout1 = new QHBoxLayout;
    HLayout1->addWidget(checkBoxUnderline);
    HLayout1->addWidget(checkBoxItalic);
    HLayout1->addWidget(checkBoxBold);

    rBtnGreen = new QRadioButton("Green");
    rBtnBlue = new QRadioButton("Blue");
    rBtnRed = new QRadioButton("Red");
    QHBoxLayout *HLayout2 = new QHBoxLayout;
    HLayout2->addWidget(rBtnGreen);
    HLayout2->addWidget(rBtnBlue);
    HLayout2->addWidget(rBtnRed);

    plainTexEdit = new QPlainTextEdit;
    QFont font = plainTexEdit->font();
    font.setPointSize(20);
    plainTexEdit->setFont(font);
    plainTexEdit->setPlainText("Hello world!\n\nI an Lemon!");

    btnOK = new QPushButton("OK");
    btnCancel = new QPushButton("Cancel");
    btnClose = new QPushButton("Close");
    QHBoxLayout *HLayout3 = new QHBoxLayout;
    HLayout3->addStretch();
    HLayout3->addWidget(btnOK);
    HLayout3->addWidget(btnCancel);
    HLayout3->addStretch();
    HLayout3->addWidget(btnClose);

    QVBoxLayout *VLayout = new QVBoxLayout;
    VLayout->addLayout(HLayout1);
    VLayout->addLayout(HLayout2);
    VLayout->addWidget(plainTexEdit);
    VLayout->addLayout(HLayout3);
    setLayout(VLayout);
}

void Dialog::on_checkUnderline(bool checked)
{
    QFont font = plainTexEdit->font();
    font.setUnderline(checked);
    plainTexEdit->setFont(font);
}

void Dialog::on_checkItalic(bool checked)
{
    QFont font = plainTexEdit->font();
    font.setItalic(checked);
    plainTexEdit->setFont(font);
}

void Dialog::on_checkBold(bool checked)
{
    QFont font = plainTexEdit->font();
    font.setBold(checked);
    plainTexEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
        QPalette plet = plainTexEdit->palette();
        if(rBtnGreen->isChecked())
            plet.setColor(QPalette::Text,Qt::green);
        else if(rBtnBlue->isChecked())
            plet.setColor(QPalette::Text,Qt::blue);
        else if(rBtnRed->isChecked())
            plet.setColor(QPalette::Text,Qt::red);
       else
            plet.setColor(QPalette::Text,Qt::black);
        plainTexEdit->setPalette(plet);

}

void Dialog::iniSignalSlots()
{
    connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));

    connect(checkBoxUnderline,SIGNAL(clicked(bool)),this,SLOT(on_checkUnderline(bool)));
    connect(checkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_checkItalic(bool)));
    connect(checkBoxBold,SIGNAL(clicked(bool)),this,SLOT(on_checkBold(bool)));

    connect(rBtnGreen,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();

}

Dialog::~Dialog()
{
}

