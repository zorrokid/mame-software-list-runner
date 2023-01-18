#ifndef DBINITWORKER_H
#define DBINITWORKER_H

#include <QObject>

class DbInitWorker : public QObject
{
    Q_OBJECT
public:
    DbInitWorker();
public slots:
    void doWork(const QString &filePath);
signals:
    void initDone();
};

#endif // DBINITWORKER_H
