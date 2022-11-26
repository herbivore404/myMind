#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QMessageBox>

//SearchDialog::SearchDialog(QWidget *parent) :
SearchDialog::SearchDialog(QPlainTextEdit *textEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    // 去掉问号，只保留关闭
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    pTextEdit = textEdit;
    ui->rbDown->setChecked(true);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_btnFindNext_clicked()
{
    QString target = ui->searchText->text();

    if(target == "" || pTextEdit == nullptr)
        return;

    QString text = pTextEdit->toPlainText();
    QTextCursor c = pTextEdit->textCursor();
    int index = -1;
    if(ui->rbDown->isChecked()){
        index = text.indexOf(target, c.position(), ui->aBcheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);
        if(index >= 0){
            c.setPosition(index);
            c.setPosition(index + target.length(), QTextCursor::KeepAnchor);
            pTextEdit->setTextCursor(c);
        }
    } else if(ui->rbUp->isChecked()){
        index = text.lastIndexOf(target, c.position() - text.length() -1, ui->aBcheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);
        if(index >= 0){
            c.setPosition(index + target.length());
            c.setPosition(index , QTextCursor::KeepAnchor);
            pTextEdit->setTextCursor(c);
        }
    }
    if(index < 0){
        QMessageBox msg(this);
        msg.setWindowTitle("Notepad-lEMON");
        msg.setText(QString("找不到 ") + target +QString(" !!"));
        msg.setWindowFlag(Qt::Drawer);
        msg.setIcon(QMessageBox::Information);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}


void SearchDialog::on_btnCancel_clicked()
{
    accept();
}

