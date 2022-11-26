#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QDebug>
#include <QSqlRecord>
#include <QDateTime>

class IDatabase : public  QObject
{
    Q_OBJECT
public:
    static IDatabase  &getInstance(){
        static IDatabase instance;
        return instance;
    }

    QString userLogin(QString userName, QString password);

private:
    explicit IDatabase(QObject *parent = nullptr);
    IDatabase(IDatabase const &) = delete;
    void operator=(IDatabase const &) = delete;

    QSqlDatabase database;

    void initDatabase();

public:
    bool initPatientModel();
    int addNewPatient();
    bool searchPatient(QString filter);
    bool deleteCurrentPatient();
    bool submitPatientEdit();
    void revertPatientEdit();

    QSqlTableModel *patientTabModel;    //数据模型
    QItemSelectionModel *thePatientSelection;   //选择模型


signals:


};

#endif
