#ifndef QBOOTSTRAP_H
#define QBOOTSTRAP_H

#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QList>

class QBootstrap
{
    class QBootInfo
    {
    public:
        QBootInfo()
        {
            correct=false;
            bootDirectoryPath="/home/root/ksu_boot1";
            startupFileName="ksu_boot.strip";
            checksumFileName="ksu_boot.strip.md5";
            checksumString="";
            createdDateTime=QDateTime::currentDateTime();
        }
        bool correct;
        QString bootDirectoryPath;
        QString startupFileName;
        QString checksumFileName;
        QString checksumString;
        QDateTime createdDateTime;
    };

    static bool findInList(const QStringList &list, const QString &findString);
    static int choiceLastCreated(const QStringList &pathList, const QStringList &exceptPathList, QDateTime &lastCreated);
    static bool extractChecksumString(const QString &text, QString &checksumString);
    static bool getChecksumString(const QString &checksumFileName, QString &checksumString);
    static bool checkSum(const QString &fileName, const QString &checksumString);
    static bool getBootInfo(const QString &bootPath, QBootInfo &bootInfo);
    static void printBootInfo(const QBootInfo &bootInfo);

public:

    static void printBootPath(const QString &bootPath);
    static void printBootPathList(const QStringList &bootPathList);
    static bool bootstrap(const QString &bootPath, const QString &workDirectory);
    static bool bootstrap(const QStringList &bootPathList, const QString &workDirectory);
};

#endif // QBOOTSTRAP_H
