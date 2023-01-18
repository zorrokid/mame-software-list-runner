#ifndef DBINITCONTROLLER_H
#define DBINITCONTROLLER_H

#include <QObject>
#include <QThread>

class DbInitController : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    DbInitController(QObject *);
    ~DbInitController();
public slots:
    void handlerResults();

signals:
    void operate(const QString &dbFilePath);
};

#endif // DBINITCONTROLLER_H
