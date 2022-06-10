#ifndef FILESEARCH_H
#define FILESEARCH_H
#include "menu.h"
#include <QObject>
#include <QDir>
#include <QFile>
#include <QString>
#include <QStringList>





#define NAPP "QSort"
#define NORG "IDNK"

class Item;
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

    QString label;
    QString outPath;
    QString extdF;
    QString inPath;

    void setLabel(QString label);
    void setInPath(QString path);
    void setOutPath(QString path);
    void setExtd(QString extd);


public:
    QStringList getInPathList();
    QStringList getOutPathList();
    QStringList getExtdList();
    QStringList getLabelList();

    QString getLabel();
    QString getOutPath();
    QString getInPath();
    QString getExtd();

    QString inptLabel();
    QString inptInPath();
    QString inptOutPath();
    QString inptExtd();

    Item *addItem();

    void rim();
    void addlI();
public slots:
   void saveI();
   void moveFiles();
   void inputC();
signals:
   void addlabelItem();
   void returnInMenu();
};

#endif // FILESEARCH_H
