#ifndef FILESEARCH_H
#define FILESEARCH_H
#include "menu.h"
#include <QObject>
#include <QDir>
#include <QFile>
#include <QString>
#include <QStringList>





//#define NAPP "QSort"
//#define NORG "IDNK"

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

    Item* trg_item;
    Item* cr_item;

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
    //Название параметра
    QString inptLabel();
    //Откуда переместить
    QString inptInPath();
    //Куда переместить
    QString inptOutPath();
    //Расширение объекта
    QString inptExtd();
    //Создать Item с необходимыми параметрами
    void cr_pItem();
    //куда встаить Item с параметрами
    void setItem(Item* trg_item);

    void rim();
    void add_pr();
public slots:
   void saveI();
   void moveFiles();
   //Ввод с консоли
   void inputC();
   //Добавить Item с параметрами в список
   void addPr();
signals:
   void addIPr();
   void returnInMenu();
};

#endif // FILESEARCH_H
