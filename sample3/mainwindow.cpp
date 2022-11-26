#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::initUI()
{
   fLabCurFile = new QLabel;
   fLabCurFile->setMinimumWidth(150);
   fLabCurFile->setText("当前文件: ");
   fLabCurFile->repaint();
   ui->statusbar->addWidget(fLabCurFile);

   progressBar=new QProgressBar;//状态栏上的进度条
   progressBar->setMaximumWidth(200);//设置组件最大宽度
   progressBar->setMinimum(5);
   progressBar->setMaximum(50);
   progressBar->setValue(ui->textEdit->font().pointSize());//初始值
   ui->statusbar->addWidget(progressBar); //添加到状态栏

   spinFontSize = new QSpinBox;// 工具栏上的文字大小 SpinBox
   spinFontSize->setMinimum(5);
   spinFontSize->setMaximum(50);
   spinFontSize->setValue(ui->textEdit->font().pointSize());//初始值
   spinFontSize->setMinimumWidth(50);//设置组件最小宽度
   ui->toolBar->addWidget(new QLabel("字体大小 ")); //不引用的Label无需定义变量
   ui->toolBar->addWidget(spinFontSize); //SpinBox添加到工具栏
   ui->toolBar->addSeparator(); //工具栏上增加分隔条

   ui->toolBar->addWidget(new QLabel(" 字体 "));
   comboFont = new QFontComboBox;//字体名称ComboBox
   comboFont->setMinimumWidth(150); //设置组件最小宽度
   ui->toolBar->addWidget(comboFont);//添加到工具栏

}

void MainWindow::iniSignalSlots()
{
    //信号与槽的关联，当函数带有参数时，必须写明参数的类型
   connect(spinFontSize,SIGNAL(valueChanged(int)),
                this,SLOT(on_spinBoxFontSize_valueChanged(int)));

   connect(comboFont,SIGNAL(currentIndexChanged(const QString &)),
                this,SLOT(on_comboFont_currentIndexChanged(const QString &)));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    initUI();
    iniSignalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{
    //有文字可copy时更新cut,copy的Enable状态
        ui->actCut->setEnabled(b); //能否 cut
        ui->actCopy->setEnabled(b);  //能否copy

        ui->actPaste->setEnabled(ui->textEdit->canPaste()); //能否paste
}


void MainWindow::on_textEdit_selectionChanged()
{
    //当前选择的文字发生变化,更新粗体、斜体、下划线3个action的checked状态
        QTextCharFormat fmt;
        fmt=ui->textEdit->currentCharFormat(); //获取文字的格式

        ui->actFontItalic->setChecked(fmt.fontItalic()); //是否斜体
        ui->actFontBold->setChecked(fmt.font().bold()); //是否粗体
        ui->actUnderline->setChecked(fmt.fontUnderline()); //是否有下划线
}

void MainWindow::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    //改变字体大小的SpinBox的响应
        QTextCharFormat fmt;
        fmt.setFontPointSize(aFontSize); //设置字体大小
        ui->textEdit->mergeCurrentCharFormat(fmt);
        progressBar->setValue(aFontSize);
}

void MainWindow::on_comboFont_currentIndexChanged(const QString &arg1)
{
    //FontCombobox的响应，选择字体名称
        QTextCharFormat fmt;
        fmt.setFontFamily(arg1);//设置字体名称
        ui->textEdit->mergeCurrentCharFormat(fmt);
}

