#include <QDebug>
#include <QDir>
#include <QXmlStreamReader>
#include <QMessageBox>
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
        QString filePath = directory.filePath(fileName);
        QFile file(filePath);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox messageBox;
            QString messageText = tr("Cannot read file %1:\n%2")
                    .arg(QDir::toNativeSeparators(filePath), file.errorString());

            messageBox.setText(messageText);
            messageBox.exec();
            return;
        }


        //QXmlStreamReader xml;
        //xml.setDevice();
    }
}
