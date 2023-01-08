#include <QDebug>
#include <QDir>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDomDocument>
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
        QFile *file = new QFile(filePath);
        if (!file->open(QFile::ReadOnly | QFile::Text)) {
            QString messageText = tr("Cannot read file %1:\n%2")
                    .arg(QDir::toNativeSeparators(filePath), file->errorString());
            showMessage(messageText);
           return;
        }
        QString errorStr;
        int errorLine;
        int errorColumn;
        QDomDocument domDocument;
        if (!domDocument.setContent(file, true, &errorStr, &errorLine, &errorColumn)) {
            QString message = tr("Parse error at line %1, column %2:\n%3")
                    .arg(errorLine)
                    .arg(errorColumn)
                    .arg(errorStr);
            showMessage(message);
        }
        QDomElement root = domDocument.documentElement();
        qInfo() << "Got root element " << root.tagName();
        file->close();
        delete file;


        //QXmlStreamReader xml;
        //xml.setDevice();
    }
}

void MameHashFileReader::showMessage(QString messageText)
{
    QMessageBox messageBox;
    messageBox.setText(messageText);
    messageBox.exec();
}
