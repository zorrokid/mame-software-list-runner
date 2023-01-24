#include "databaseprovider.h"
#include "dbmigrations.h"

DatabaseProvider::DatabaseProvider()
{

}

QSqlDatabase DatabaseProvider::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MameSoftwareListRunner");
    return db;
}

QSqlError DatabaseProvider::initDb(const QString &filePath)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QDir path(filePath);
    db.setDatabaseName(path.filePath("MameSoftwareLists"));

    if (!db.open())
        return db.lastError();

    // version 0 means no migrations have been run
    int version = 0;

    QSqlQuery q;
    q.exec("PRAGMA user_version");
    if (q.first()){
        version = q.value(0).toInt();
        qDebug() << "Database current user_version is: " << version;
    }

    int index = 0;
    int migrationCount = sizeof(MIGRATION_LIST) / sizeof(QLatin1String*);

    // [0] = first migration => version = i+1
    for(int i = version; i < migrationCount; i++){
        qDebug() << "Running migration: "
                 << *MIGRATION_LIST[i];
        q.exec(*MIGRATION_LIST[i]);
    }
    q.prepare("PRAGMA user_version = ?");
    q.bindValue(0, migrationCount);
    q.exec();

    QStringList tables = db.tables();
    if (tables.contains("softwareList", Qt::CaseInsensitive))
        return QSqlError();

    //if (!q.exec(SOFTWARE_LISTS_SQL))
     //   return q.lastError();

    return QSqlError();
}

 QVariant DatabaseProvider::addSoftwareList(QSqlQuery &q, QString &name, QString &description)
 {
    q.addBindValue(name);
    q.addBindValue(description);
    q.exec();
    return q.lastInsertId();
 }
