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
    void showMessage(QString message);
};

#endif // MAMEHASHFILEREADER_H
