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

    // version 0 means no migrations has been run
    int version = 0;

    QSqlQuery q;
    q.exec("PRAGMA user_version");
    if (q.first()){
        version = q.value(0).toInt();
        qDebug() << "Database current user_version is: " << version;
    }

    int index = 0;
    int migrationCount = sizeof(MIGRATION_LIST) / sizeof(QLatin1String*);

    if (migrationCount == version){
        qDebug() << "Database up to date.";
        return  QSqlError("", "", QSqlError::NoError);
    }

    // [0] = first migration => version = i+1
    for(int i = version; i < migrationCount; i++){
        qDebug() << "Running migration: "
                 << i << " "
                 << *MIGRATION_LIST[i];
        if(!q.exec(*MIGRATION_LIST[i])) {
            qWarning() << "Failed running migration " << *MIGRATION_LIST[i];
            return QSqlError("", "Failed running migration.", QSqlError::UnknownError);
        }
    }
    qDebug() << "Setting schema version " << migrationCount;
    QString setPragmaUserVersion = QString("PRAGMA user_version=%1").arg(migrationCount);
    if (!q.exec(setPragmaUserVersion)){
       qWarning() << "Failed setting db schema version.";
       return QSqlError("", "Failed setting db schema version.", QSqlError::UnknownError);
    }
    q.exec("PRAGMA user_version");
    if (q.first()){
        version = q.value(0).toInt();
        qDebug() << "Database current user_version is: " << version;
    }

    return QSqlError("", "", QSqlError::NoError);
}

 QVariant DatabaseProvider::addSoftwareList(QSqlQuery &q, QString &name, QString &description)
 {
    q.addBindValue(name);
    q.addBindValue(description);
    q.exec();
    return q.lastInsertId();
 }
