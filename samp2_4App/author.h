#ifndef AUTHOR_H
#define AUTHOR_H

#include <QWidget>

namespace Ui {
class author;
}

class author : public QWidget
{
    Q_OBJECT

public:
    explicit author(QWidget *parent = nullptr);
    ~author();

private:
    Ui::author *ui;

public slots:
    void sSlots();
signals:
    void sSignal();

};

#endif // AUTHOR_H
