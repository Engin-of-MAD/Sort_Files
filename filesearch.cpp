#include "filesearch.h"
#include <QDir>
#include <QTextStream>
#include <QStringList>
#include <QFileInfo>
#include <QFileInfoList>
#include <iostream>


void Plug::ShowMsg(){
    QTextStream out(stdout);
    out << "Empty Message\n";
}

void Plug::Show()
{
    QTextStream out(stdout);
    out << "Slot was activated\n";
}





QString FileSearch::getOutPath(){
    return outPath;
}

QString FileSearch::getInPath()
{
    return inPath;
}

QString FileSearch::getExtd()
{
    return this->extdF;
}





void FileSearch::setExtd(QString extd)
{
    this->extdF = extd;
    this->extdList << extd;
}

QStringList FileSearch::getInPathList()
{
    return this->inPathList;
}

QStringList FileSearch::getOutPathList()
{
    return this->outPathList;
}

QStringList FileSearch::getExtdList()
{
    return this->extdList;
}

QStringList FileSearch::getLabelList()
{
    return this->labelList;
}

QString FileSearch::getLabel()
{
    return this->label;
}

void FileSearch::setLabel(QString label)
{
    this->label = label;
}

void FileSearch::setInPath(QString path)
{
    this->inPath = path;
}

void FileSearch::setOutPath(QString path)
{
    this->outPath = path;
}






QString FileSearch::inptInPath()
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QString path;
    QString tmp_path;
    QString msg = "Входящий путь";
    cout << msg << Qt::endl;
    cin >> tmp_path;

    if (tmp_path == "q" || tmp_path == "Q"){
        return tmp_path;
    }

    setInPath(path);
    return path;
}

QString FileSearch::inptOutPath()
{

    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString path;
    QString tmp_path;
    QString msg = "Исходящий путь";
    cout << msg << Qt::endl;
    cin >> tmp_path;

    if (tmp_path == "q" || tmp_path == "Q") {
        rim();
        return tmp_path;
    }

    path = tmp_path;
    setOutPath(path);
    return path;
}

QString FileSearch::inptExtd()
{
    QString extd;
    QString tmp_extd;
    QString msg = "Введите расширение файла";
    QString msg1 = "Пример расширения файла \"*.txt(или другое расширение)\"";

    QTextStream cout(stdout);
    QTextStream cin(stdin);


    cout << msg << Qt::endl;
    cout << msg1 << Qt::endl;
    cin >> tmp_extd;

    if (tmp_extd == "q" || tmp_extd == "Q"){
        return tmp_extd;
    }

    extd = tmp_extd;
    extdList << extd;
    myDirI.setNameFilters(extdList);
    myDirI.setFilter(QDir::Files);

    return extd;
}

Item *FileSearch::addItem()
{
    Item* p_item = new P_Item(getLabel(), getInPath(), getOutPath(), getExtd());
    return p_item;
}


QString FileSearch::inptLabel()
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString label;
    QString tmp_label;
    QString msg = "Имя сортировки";
    cout << msg << Qt::endl;
    cin >> tmp_label;

    if (tmp_label == "q" || tmp_label == "Q") {
        rim();
        return tmp_label;
    }

    label = tmp_label;
    setLabel(label);
    return label;
}



void FileSearch::rim()
{
    emit returnInMenu();
}

void FileSearch::addlI()
{
    emit addlabelItem();
}

void FileSearch::saveI()
{

}




void FileSearch::moveFiles()
{
    QTextStream cout(stdout);

    myDirI.setPath(getInPath());
    fileList = myDirI.entryInfoList(extdList, QDir::Files);
    myDirO.setPath(getOutPath());

    for (QFileInfo file : fileList) {
            QString tmp_inPath = myDirI.absolutePath() + myDirI.separator() + file.fileName();
            cout << tmp_inPath << Qt::endl;
            QString tmp_outPath = myDirO.absolutePath() + myDirO.separator() + file.fileName();
            myFile.setFileName(tmp_inPath);

                if(myFile.rename(tmp_inPath, tmp_outPath)){
                    cout << "Succsses\n";
                }
                else cout << "Fail\n";
    }

}



void FileSearch::inputC()
{
   //Item* p_item;
   inptInPath();
   inptOutPath();
   inptExtd();
   rim();

}


