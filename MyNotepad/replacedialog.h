#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QPlainTextEdit *textEdit = nullptr, QWidget *parent = nullptr);
    ~ReplaceDialog();

private slots:
    void on_btnSearchNext_clicked();

    void on_btnReplace_clicked();

    void on_btnReplaceAll_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ReplaceDialog *ui;
    QPlainTextEdit *pTextEdit;
};

#endif // REPLACEDIALOG_H
