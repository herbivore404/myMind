#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "searchdialog.h"
#include "replacedialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QColorDialog>
#include <QFontDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    textChanged = false;
    on_actionNew_triggered();

    statusLabel.setMaximumWidth(180);
    statusLabel.setText("length：" + QString::number(0) + "      lines：" + QString::number(1));
    ui->statusbar->addPermanentWidget(&statusLabel);

    statusCursorLabel.setMaximumWidth(180);
    statusCursorLabel.setText("      Ln：" + QString::number(0) + "      Col：" + QString::number(1));
    ui->statusbar->addPermanentWidget(&statusCursorLabel);

    QLabel *author = new QLabel(ui->statusbar);
    author->setText(tr("      ChenZhiCong"));
    ui->statusbar->addPermanentWidget(author);

    ui->actionCopy->setEnabled(false);
    ui->actionPaste->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    QPlainTextEdit::LineWrapMode mode = ui->plainTextEdit->lineWrapMode();

    if (mode ==QTextEdit::NoWrap) {
        ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        ui->actionWordWrap->setChecked(true);
    } else {
        ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        ui->actionWordWrap->setChecked(false);
    }

    ui->actionStatusbar->setChecked(true);
    ui->actionToolbar->setChecked(true);
    ui->actionLineNum->setChecked(true);
//    on_actionLineNum_triggered();

    connect(ui->actionLineNum, SIGNAL(triggered(bool)),ui->plainTextEdit,SLOT(hideLineNumberArea(bool)));

    tim = new QTimer();
    //默认定时20s自动保存
    tim->setInterval(20000);
    connect(tim, SIGNAL(timeout()),this,SLOT(onTimeOut()));
    tim->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeOut()
{
    if(filePath == ""){
        return;
    } else{
        QFile file(filePath);
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this, "Notepad-LEMON","保存文件失败");
            return;
        }
        QTextStream out(&file);
        QString text = ui->plainTextEdit->toPlainText();
        out << text;
        file.flush();
        file.close();

        this->setWindowTitle(QFileInfo(filePath).absoluteFilePath());
        textChanged = false;
        printf("已自动保存！");
    }
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg;
    dlg.exec();
}


void MainWindow::on_actionFind_triggered()
{
//    SearchDialog dlg;
    SearchDialog dlg(ui->plainTextEdit);
    dlg.exec();
}


void MainWindow::on_actionReplace_triggered()
{
    ReplaceDialog dlg(ui->plainTextEdit);
    dlg.exec();
}


void MainWindow::on_actionNew_triggered()
{
    if(!userEditConfirmed())
        return;

    filePath = "";
    ui->plainTextEdit->clear();
    this->setWindowTitle(tr("未命名 - Notepad-LEMON"));

    textChanged = false;
}


void MainWindow::on_actionOpen_triggered()
{
    if(!userEditConfirmed())
        return;

    QString filename = QFileDialog::getOpenFileName(this, "打开文件", ".",tr("Text files (*.txt);;All (*.*)"));
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Notepad-LEMON","打开文件失败");
        return;
    }

    filePath = filename;
    ui->plainTextEdit->clear();
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->insertPlainText(text);
    file.close();

    this->setWindowTitle(QFileInfo(filename).absoluteFilePath());

    textChanged = false;
}


void MainWindow::on_actionSave_triggered()
{
//    QFile file(filePath);
//    if(!file.open(QFile::WriteOnly | QFile::Text)){
//        QMessageBox::warning(this, "..","打开文件失败");
//        QString filename = QFileDialog::getSaveFileName(this,"保存文件",".",tr("Text files (*.txt)"));

//        QFile file(filename);
//        if(!file.open(QFile::WriteOnly | QFile::Text)){
//            QMessageBox::warning(this, "..","保存文件失败");
//            return;
//        }
//        filePath = filename;
//    }

    if(filePath == ""){
        QString filename = QFileDialog::getSaveFileName(this,"保存文件",".",tr("Text files (*.txt)"));
        QFile file(filename);
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this, "Notepad-LEMON","保存文件失败");
            return;
        }
        file.close();
        filePath = filename;
    }
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Notepad-LEMON","保存文件失败");
        return;
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

    this->setWindowTitle(QFileInfo(filePath).absoluteFilePath());
    textChanged = false;
}


void MainWindow::on_actionSaveAs_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"另存文件",".",tr("Text files (*.txt)"));
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Notepad-LEMON","另存文件失败");
        return;
    }
    filePath = filename;
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

     this->setWindowTitle(QFileInfo(filePath).absoluteFilePath());
}


void MainWindow::on_plainTextEdit_textChanged()
{
    if(!textChanged){
        this->setWindowTitle("*" + this->windowTitle());
        textChanged = true;
    }
    statusLabel.setText("length：" + QString::number(ui->plainTextEdit->toPlainText().length()) +
                        "      lines：" + QString::number(ui->plainTextEdit->document()->lineCount()));
}

bool MainWindow::userEditConfirmed()
{
    if(textChanged){
        QString path = (filePath != "") ? filePath : "未命名.txt";
        QMessageBox msg(this);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowTitle("Notepad-LEMON");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText(QString("是否将文件保存至\n") + "\"" + path + "\" ?" );
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        int r = msg.exec();
        switch(r){
            case QMessageBox::Yes:
                on_actionSave_triggered();
                break;
        case QMessageBox::No:
            textChanged = false;
            break;
        case QMessageBox::Cancel:
            return false;
        }
    }
    return true;
}


void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}


void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
    ui->actionPaste->setEnabled(true);
}


void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
    ui->actionPaste->setEnabled(true);
}


void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}


void MainWindow::on_plainTextEdit_copyAvailable(bool b)
{
    ui->actionCopy->setEnabled(b);
    ui->actionCut->setEnabled(b);
}


void MainWindow::on_plainTextEdit_redoAvailable(bool b)
{
    ui->actionRedo->setEnabled(b);
}


void MainWindow::on_plainTextEdit_undoAvailable(bool b)
{
    ui->actionUndo->setEnabled(b);
}


void MainWindow::on_actionFontColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "选择字体颜色");
    if(color.isValid()){
        _fontColor = color.name();
        _styleSheet = "QPlainTextEdit {color: %1}";
        _styleSheets = _styleSheets  + _styleSheet.arg(_fontColor);
        ui->plainTextEdit->setStyleSheet(_styleSheets);

//        ui->plainTextEdit->setStyleSheet(QString("QPlainTextEdit {color: %1}").arg(color.name()));
    }
}

void MainWindow::on_actionBackColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "选择背景颜色");
    if(color.isValid()){
        _bgColor = color.name();
        _styleSheet = "QPlainTextEdit {background-color: %1}";
        _styleSheets = _styleSheets  + _styleSheet.arg(_bgColor);
        ui->plainTextEdit->setStyleSheet(_styleSheets);

//        ui->plainTextEdit->setStyleSheet(QString("QPlainTextEdit {background-color: %1}").arg(color.name()));
    }
}

void MainWindow::on_actionFontBackColor_triggered()
{

}

void MainWindow::on_actionWordWrap_triggered()
{
    QPlainTextEdit::LineWrapMode mode = ui->plainTextEdit->lineWrapMode();

    if (mode ==QTextEdit::NoWrap) {
        ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        ui->actionWordWrap->setChecked(true);
    } else {
        ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        ui->actionWordWrap->setChecked(false);
    }
}


void MainWindow::on_actionFont_triggered()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok){
        ui->plainTextEdit->setFont(font);
    }
}


void MainWindow::on_actionStatusbar_triggered()
{
    bool visible = ui->statusbar->isVisible();
    ui->statusbar->setVisible(!visible);
    ui->actionStatusbar->setChecked(!visible);
}


void MainWindow::on_actionToolbar_triggered()
{
    bool visible = ui->toolBar->isVisible();
    ui->toolBar->setVisible(!visible);
    ui->actionToolbar->setChecked(!visible);
}


void MainWindow::on_actionSelectAll_triggered()
{
    ui->plainTextEdit->selectAll();
}


void MainWindow::on_actionExit_triggered()
{
    if(userEditConfirmed())
        exit(0);
}


void MainWindow::on_plainTextEdit_cursorPositionChanged()
{
    int col = 0;
    int ln = 0;
    int flg = -1;
    int pos = ui->plainTextEdit->textCursor().position();
    QString text = ui -> plainTextEdit->toPlainText();
    for(int i=0; i<pos; i++){
        if(text[i] == '\n'){
            ln++;
            flg = i;
        }
    }
    flg++;
    col = pos - flg;
    statusCursorLabel.setText("      Ln：" + QString::number(ln + 1) + "      Col：" + QString::number(col+1));
}


//void MainWindow::on_actionLineNum_triggered(bool checked)
//{
//    ui->plainTextEdit->hideLineNumberArea(!checked);
//}

