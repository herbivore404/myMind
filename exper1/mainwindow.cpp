#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBtns = {
        {Qt::Key_0,ui->btnNum0},
        {Qt::Key_1,ui->btnNum1},
        {Qt::Key_2,ui->btnNum2},
        {Qt::Key_3,ui->btnNum3},
        {Qt::Key_4,ui->btnNum4},
        {Qt::Key_5,ui->btnNum5},
        {Qt::Key_6,ui->btnNum6},
        {Qt::Key_7,ui->btnNum7},
        {Qt::Key_8,ui->btnNum8},
        {Qt::Key_9,ui->btnNum9},
    };
    foreach(auto btn, digitBtns)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

//    connect(ui->btnNum0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    digitBtnDOperations={
        {Qt::Key_Plus,ui->btnPlus},
        {Qt::Key_Minus,ui->btnMimus},
        {Qt::Key_Asterisk,ui->btnMultiple},
        {Qt::Key_Slash,ui->btnDivide},
    };
    foreach(auto btn1, digitBtnDOperations)
        connect(btn1,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

//    connect(ui->btnPlus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
//    connect(ui->btnMimus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
//    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
//    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSign,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));

    digitBtnOperations={
        {Qt::Key_Percent,ui->btnPercentage},
        {Qt::Key_Backspace,ui->btnDel},
        {Qt::Key_Period,ui->btnPeriod},
        {Qt::Key_Equal,ui->btnEqual},
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if(operands.size()==2 &&  opcodes.size()>0){
        result=0;
        double operand1=operands.front().toDouble();
        operands.pop_front();
        double operand2=operands.front().toDouble();
        operands.pop_front();

        QString op=opcodes.front();
        opcodes.pop_front();

        if (op == "+"){
            result = operand1 + operand2;
        } else if (op == "-") {
            result = operand1 - operand2;
        } else if (op =="×") {
            result = operand1*operand2;
        } else if (op =="÷") {
             result = operand1/operand2;
        }
        operands.push_back(QString::number(result));
        ui->statusbar->showMessage(QString("calculation is in progess! operand is %1, opcode is %2")
                                   .arg(operands.size()).arg(opcodes.size()));
    }else{
        ui->statusbar->showMessage(QString("operand is %1, opcode is %2")
                                   .arg(operands.size()).arg(opcodes.size()));
    }
    return QString::number(result);
}

void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    if(digit == "0" && operand == "0")
        digit = "";

    if(operand == "0" && digit != "0")
        operand="";

    operand += digit;

    ui->display->setText(operand);

}

void MainWindow::on_btnPeriod_clicked()
{
    if (!operand.contains("."))
        operand += qobject_cast<QPushButton *>(sender())->text();
    ui->display->setText(operand);

}


void MainWindow::on_btnDel_clicked()
{
    operand = operand.left(operand.length() - 1);
    ui->display->setText(operand);

}


void MainWindow::on_btnClear_clicked()
{
    operand.clear();
    ui->display->setText(operand);
}

void MainWindow::btnBinaryOperatorClicked()
{
    ui->statusbar->showMessage("last operand " + operand);
    opcode = qobject_cast<QPushButton*>(sender())->text();

    if (operand != ""){
        operands.push_back(operand);
        operand = "";
        opcodes.push_back(opcode);
    }

    QString result=calculation();
    ui->display->setText(result);
}

void MainWindow::btnUnaryOperatorClicked()
{
    if (operand != ""){
        double result = operand.toDouble();
        operand = "";

        QString op = qobject_cast<QPushButton*>(sender())->text();

        if (op == "%"){
            result /= 100.0;
        } else if (op == "1/x"){
            result = 1/result;
        } else if (op == "x²"){
            result *= result;
        } else if (op =="√"){
            result = sqrt(result);
        } else if (op =="±"){
            result = (-1)*result;
        }

        operand = QString::number(result);

        ui->display->setText(QString::number(result));
    }
}

void MainWindow::on_btnEqual_clicked()
{
    if (operand != ""){
        operands.push_back(operand);
        operand = "";
    }

    QString result=calculation();
    ui->display->setText(result);


}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach (auto btnKey, digitBtns.keys()) {
        if(event->key() == btnKey)
            digitBtns[btnKey]->animateClick(100);
    }
    foreach (auto btnKey, digitBtnDOperations.keys()) {
        if(event->key() == btnKey)
            digitBtnDOperations[btnKey]->animateClick(100);
    }
    foreach (auto btnKey, digitBtnOperations.keys()) {
        if(event->key() == btnKey)
            digitBtnOperations[btnKey]->animateClick(100);
    }
}

