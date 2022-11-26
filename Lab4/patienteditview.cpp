#include "patienteditview.h"
#include "ui_patienteditview.h"
#include "idatabase.h"
#include <QSqlTableModel>

PatientEditView::PatientEditView(QWidget *parent, int index) :
    QWidget(parent),
    ui(new Ui::PatientEditView)
{
    ui->setupUi(this);

    //创建界面组件与数据模型的字段之间的数据映射
        dataMapper= new QDataWidgetMapper();
        QSqlTableModel *tabModel = IDatabase::getInstance().patientTabModel;
        dataMapper->setModel(IDatabase::getInstance().patientTabModel);//设置数据模型
        dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);//

    //界面组件与tabModel的具体字段之间的联系
        dataMapper->addMapping(ui->dbEditID,tabModel->fieldIndex("ID"));
        dataMapper->addMapping(ui->dbEditName,tabModel->fieldIndex("NAME"));
        dataMapper->addMapping(ui->dbEditIDCard,tabModel->fieldIndex("ID_CARD"));
        dataMapper->addMapping(ui->dbComboSex,tabModel->fieldIndex("SEX"));
        dataMapper->addMapping(ui->dbSpinAge,tabModel->fieldIndex("AGE"));
        dataMapper->addMapping(ui->dbDateEditDOB,tabModel->fieldIndex("DOB"));
        dataMapper->addMapping(ui->dbSpinHeight,tabModel->fieldIndex("HEIGHT"));
        dataMapper->addMapping(ui->dbSpinWeight,tabModel->fieldIndex("WEIGHT"));
        dataMapper->addMapping(ui->dbEditMobile,tabModel->fieldIndex("MOBILEPHONE"));
        dataMapper->addMapping(ui->dbCreatedTimeStamp,tabModel->fieldIndex("CREATEDTIMESTAMP"));

        dataMapper->setCurrentIndex(index);
}

PatientEditView::~PatientEditView()
{
    delete ui;
}

void PatientEditView::on_btSave_clicked()
{
    IDatabase::getInstance().submitPatientEdit();

    emit goPreviousView();
}


void PatientEditView::on_btCancel_clicked()
{
    IDatabase::getInstance().revertPatientEdit();

    emit goPreviousView();
}

