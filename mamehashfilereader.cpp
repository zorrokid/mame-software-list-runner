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
        readFile(fileName, directory);
    }
}

void MameHashFileReader::readFile(const QString &fileName, const QDir &directory)
{
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
    } else {
        processDocument(domDocument);
    }
    file->close();
    delete file;
}

void MameHashFileReader::processDocument(const QDomDocument &domDocument)
{
    QDomElement root = domDocument.documentElement();
    if (root.tagName() != "softwarelist") {
        qWarning() << "Document didn't have a 'softwarelist' root element.";
        return;
    }

    qInfo() << "name" << root.attribute("name");
    qInfo() << "description" << root.attribute("description");

    // Software list has at least one software child element
    QDomNodeList softwareNodes = root.childNodes();
    for(int i = 0; i < softwareNodes.length(); i++) {
        QDomElement software = softwareNodes.item(i).toElement();
        processSoftwareElement(software);
    }
}

/* Software has the following child elements:
 * - description, year, publisher
 * - 0..n: info*, sharedfeat*, part*
 * - optional: notes?
 * And the following attributes:
 * - name
 * - supported
 * - cloneof
 */
void MameHashFileReader::processSoftwareElement(const QDomElement &software)
{
    qInfo() << "name: " << software.attribute("name");
    qInfo() << "supported: " << software.attribute("supported");

    QDomElement description = software.firstChildElement("description");
    qInfo() << "description: " << description.text();

    QDomElement year = software.firstChildElement("year");
    qInfo() << "year: " << year.text();

    QDomElement publisher = software.firstChildElement("publisher");
    qInfo() << "publisher: " << publisher.text();

    // part can have 0..n of the following child elements:
    // feature*, dataarea*, diskarea*, dipswitch*
    QDomElement part = software.firstChildElement("part");
    qInfo() << "part.name: " << part.attribute("name");
    qInfo() << "part.interface: " << part.attribute("interface");

    // dataarea can have 0..n rom child elements
    QDomElement dataArea = part.firstChildElement("dataarea");
    qInfo() << "part/dataarea.name: " << dataArea.attribute("name");
    qInfo() << "part/dataarea.size: " << dataArea.attribute("size");

    QDomElement rom = dataArea.firstChildElement("rom");
    qInfo() << "part/dataarea/rom.name: " << rom.attribute("name");
    qInfo() << "part/dataarea/rom.size: " << rom.attribute("size");
    qInfo() << "part/dataarea/rom.crs: " << rom.attribute("crc");
    qInfo() << "part/dataarea/rom.sha1: " << rom.attribute("sha1");

    // TODO: diskarea can have 0..n disk child elements
    // TODO: dipswitch can have 0..n dipvalue child elements
}

void MameHashFileReader::showMessage(QString messageText)
{
    QMessageBox messageBox;
    messageBox.setText(messageText);
    messageBox.exec();
}
