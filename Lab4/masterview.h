#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include "loginview.h"
#include "doctorview.h"
#include "departmentview.h"
#include "patientview.h"
#include "patienteditview.h"
#include "welcomeview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MasterView; }
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goPatientView();
    void goDepartmentView();
    void goPatientEditView(int rowNo);
    void goPreviousView();

private slots:
    void on_btBack_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btLogout_clicked();

private:
    Ui::MasterView *ui;

    void pushWidgetToStackView(QWidget *widget);

    WelcomeView *welcomeView;
    LoginView *loginView;
    DoctorView *doctorView;
    PatientView *patientView;
    PatientEditView *patientEditView;
    DepartmentView *departmentView;

};
#endif // MASTERVIEW_H
