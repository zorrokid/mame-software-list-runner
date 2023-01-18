#include "databaseprovider.h"

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

    QStringList tables = db.tables();
    if (tables.contains("softwareList", Qt::CaseInsensitive))
        return QSqlError();

    QSqlQuery q;
    if (!q.exec(SOFTWARE_LISTS_SQL))
        return q.lastError();

    return QSqlError();
}

 QVariant DatabaseProvider::addSoftwareList(QSqlQuery &q, QString &name, QString &description)
 {
    q.addBindValue(name);
    q.addBindValue(description);
    q.exec();
    return q.lastInsertId();
 }
