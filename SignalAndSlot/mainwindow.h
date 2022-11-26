#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "girlfriend.h"
#include "me.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void hungrySlot();

private:
    Ui::MainWindow *ui;

    Me* m_me;
    GirlFriend* m_girl;
};
#endif // MAINWINDOW_H
