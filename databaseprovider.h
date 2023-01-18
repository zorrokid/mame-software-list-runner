#ifndef DATABASEPROVIDER_H
#define DATABASEPROVIDER_H

#include <QObject>
#include <QtSql>

const auto SOFTWARE_LISTS_SQL = QLatin1String(R"(
    CREATE TABLE softwareLists(
        id INTEGER PRIMARY KEY,
        name VARCHAR,
        description VARCHAR
    )
)");

const auto INSERT_SOFTWARE_LISTS_SQL = QLatin1String(R"(
    INSERT INTO softwareLists(name, description)
    VALUES (?, ?)
)");

class DatabaseProvider
{
public:
    DatabaseProvider();
    static QSqlError initDb(const QString &filePath);
    QSqlDatabase connect();
    QVariant addSoftwareList(QSqlQuery &q, QString &name, QString &description);
};

#endif // DATABASEPROVIDER_H
