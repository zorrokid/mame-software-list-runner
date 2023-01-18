#include "dbinitcontroller.h"
#include "dbinitworker.h"

DbInitController::DbInitController(QObject* parent)
{
    setParent(parent);
    DbInitWorker *worker = new DbInitWorker();
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, &QObject::deleteLater);
    connect(this, &DbInitController::operate, worker, &DbInitWorker::doWork);
    connect(worker, &DbInitWorker::initDone, this, &DbInitController::handlerResults);
    workerThread.start();
}

DbInitController::~DbInitController()
{
    workerThread.quit();
    workerThread.wait();
}

void DbInitController::handlerResults()
{
}
