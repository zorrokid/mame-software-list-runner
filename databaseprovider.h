#ifndef DATABASEPROVIDER_H
#define DATABASEPROVIDER_H

#include <QObject>
#include <QtSql>

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
