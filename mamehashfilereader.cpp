#include <QDebug>
#include "mamehashfilereader.h"

MameHashFileReader::MameHashFileReader(QString hashFilePath, QObject *parent)
    : QObject{parent}, hashFilePath(hashFilePath)
{  }

void MameHashFileReader::read()
{
    qInfo() << "Start reading path" << hashFilePath;
    // TODO
}
