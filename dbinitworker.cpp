#include "dbinitworker.h"
#include "databaseprovider.h"

DbInitWorker::DbInitWorker()
{

}

void DbInitWorker::doWork(const QString &filePath)
{
    qDebug() << "Start initializing database.";
    DatabaseProvider::initDb(filePath);
    qDebug() << "Done initializing database.";
    emit initDone();
}
