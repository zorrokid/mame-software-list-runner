#include <QDebug>
#include <QDir>
#include <QXmlStreamReader>
#include "mamehashfilereader.h"

MameHashFileReader::MameHashFileReader(QString hashFilePath, QObject *parent)
    : QObject{parent}, hashFilePath(hashFilePath)
{  }

void MameHashFileReader::read()
{
    qInfo() << "Start reading path" << hashFilePath;
    QDir directory = QDir(hashFilePath);
    QStringList filters;
    filters << "*.xml";
    QStringList fileNames = directory.entryList(filters);
    for(const auto& fileName : fileNames){
        qInfo() << "Read file " << fileName;
        //QXmlStreamReader xml;
        //xml.setDevice();
    }
}
