#pragma once
#ifndef MENU_H
#define MENU_H

#include "filesearch.h"
#include <QObject>
#include <QString>
#include <vector>


class Item : public QObject
{
    Q_OBJECT
protected:



    QString nameItem;
    QString nameOwner;
public:

    Item(QString nameI) : nameItem(nameI) {}
    Item(){}
    QString getItemName();


    virtual void addItem(Item* subItem) = 0;
    virtual void removeItem(Item* subItem) = 0;
    virtual void display() = 0;
    virtual void selectAction();

    void showAction();
    virtual void selectItem() = 0;
public slots:
    virtual void nextMenu() = 0;
signals:
    void selectedItem();
};


class ClickableItem : public Item {
    Q_OBJECT
public:

    ClickableItem(QString name) : Item(name) {}
    ClickableItem(){}

    void setItemName();
    void selectItem() override;
    void display() override;
    void removeItem(Item* subItem) override;
    void addItem(Item* subItem) override;
public slots:
    void nextMenu() override;

};

class ItemList : public Item {
    Q_OBJECT
protected:
    int check(int chs);
    int corr_inpt(int num);
    std::vector<Item*> myItems;
public:

    ItemList(QString name) : Item(name) {}
    ItemList();
    void setItemName();
    void addItem(Item* subItem) override;
    void selectItem() override;
    void removeLastItem();
    void removeItem(Item* name) override;
    void display() override;
public slots:
    void nextMenu() override;

};

class P_Item : public Item{
private:

    QString InPath;
    QString OutPath;
    QString Filter;
public:
    P_Item(QString label, QString inPath, QString outPath, QString filter){
        this->nameItem = label;
        this->InPath = inPath;
        this->Filter = filter;
        this->OutPath = outPath;

    }
    void selectItem() override;
    void display() override;
    void removeItem(Item* subItem) override;
    void addItem(Item* subItem) override;
    void nextMenu() override;

};



#endif
