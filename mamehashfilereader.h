#ifndef MAMEHASHFILEREADER_H
#define MAMEHASHFILEREADER_H

#include <QObject>
#include "databaseprovider.h"

class QDir;
class QDomDocument;
class QDomElement;

class MameHashFileReader : public QObject
{
    Q_OBJECT
public:
    explicit MameHashFileReader(QString hashFilePath, QObject *parent = nullptr);

    void read();

signals:

private:
    QString hashFilePath;
    DatabaseProvider* databaseProvider;
    void showMessage(QString message);
    void readFile(const QString &fileName, const QDir &directory);
    void processDocument(const QDomDocument &document);
    void processSoftwareElement(const QDomElement &software);
};

#endif // MAMEHASHFILEREADER_H
