#ifndef FILESEARCH_H
#define FILESEARCH_H

#include <iostream>
#include <QObject>
#include <QDir>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QSettings>
//#include "menu.h"

#define NAPP "QSort"
#define NORG "IDNK"
using namespace std;
class Plug: public QObject{
    Q_OBJECT
private:

public:

public slots:
    void Show();
    void ShowMsg();
};


class FileSearch: public QObject
{
    Q_OBJECT
private:

    QDir myDirI;
    QDir myDirO;
    QFile myFile;

    QFileInfoList fileList;

    QStringList labelList;
    QStringList extdList;
    QStringList inPathList;
    QStringList outPathList;

    QString outPath;
    QString extdF;
    QString inPath;

    void setInPath(QString path);
    void setOutPath(QString path);
    void setExtd(QString extd);


public:
    QStringList getInPathList();
    QStringList getOutPathList();
    QStringList getExtdList();

    QString getOutPath();
    QString getInPath();
    QString getExtd();

    QString inptInPath();
    QString inptOutPath();
    QString inptExtd();
   // QString inputLabel(Item *item);
    //void saveData(FileSearch* file);
    void rim();

public slots:
   void moveFiles();
   void inputC();
signals:
   void Save();
   void returnInMenu();
};

#endif // FILESEARCH_H
