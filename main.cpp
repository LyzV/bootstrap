#include <QCoreApplication>
#include "qbootstrap.h"
#include <QStringList>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("bootstrap");
    QCoreApplication::setApplicationVersion("1.0.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("First time boot KSU-loarer");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("path1", "First boot path");
    parser.addPositionalArgument("path2", "Second boot path");
    parser.addPositionalArgument("directory", "Current work directory");

    QCommandLineOption firstBootPath(QStringList() << "f" << "first",
                                     "First boot path",
                                     "directory1",
                                     "/home/root/ksu_boot1");
    parser.addOption(firstBootPath);
    QCommandLineOption secondBootPath(QStringList() << "s" << "second",
                                      "Second boot path",
                                      "directory2",
                                      "/home/root/ksu_boot2");
    parser.addOption(secondBootPath);
    QCommandLineOption currentWorkDirectory(QStringList() << "d" << "work_directory",
                                            "Current work directory",
                                            "work_directory",
                                            "/home/root");
    parser.addOption(currentWorkDirectory);

    QStringList bootPathList;
    parser.process(a);
    bootPathList.append(parser.value(firstBootPath));
    bootPathList.append(parser.value(secondBootPath));
    QString currentWorkDirectoryName=parser.value(currentWorkDirectory);

    bool ret=QBootstrap::bootstrap(bootPathList, currentWorkDirectoryName);
    if(false==ret)
    {
        a.exit(1);
        return 1;
    }

    a.exit(0);
    return 0;
}
