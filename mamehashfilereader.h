#ifndef MAMEHASHFILEREADER_H
#define MAMEHASHFILEREADER_H

#include <QObject>

class MameHashFileReader : public QObject
{
    Q_OBJECT
public:
    explicit MameHashFileReader(QString hashFilePath, QObject *parent = nullptr);

    void read();

signals:

private:
    QString hashFilePath;
};

#endif // MAMEHASHFILEREADER_H
