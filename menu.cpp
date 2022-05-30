#include "menu.h"
#include <vector>
#include <iostream>
#include <QTextStream>
#include <QSettings>
using namespace std;


QString Item::getItemName() {
    return nameItem;
}

void Item::selectAction()
{
    emit selectedItem();
}

void Item::showAction()
{
    emit selectedItem();
}


void ClickableItem::selectItem()
{
    //cout << "I'm here" << endl;
    throw exception();
}

void ClickableItem::display() {
    QTextStream in(stdin);
    QTextStream out(stdout);
    out << nameItem << "\n";
}

void ClickableItem::removeItem(Item* subItem) {
    throw exception();
}

void ClickableItem::addItem(Item* subItem) {
    throw exception();
}

void ClickableItem::nextMenu()
{
    throw std::exception();
}



void ItemList::display() {
    QTextStream in(stdin);
    QTextStream out(stdout);
    int index = 1;
    for (int i = 0; i < myItems.size(); i++) {
        out << index << "." << myItems[i]->getItemName() << "\n";
        index++;
    }
}

void ItemList::nextMenu()
{
    display();
    selectItem();
}


void ItemList::removeLastItem() {
    myItems.pop_back();
}
int ItemList::check(int chs)
{
    size_t size  = myItems.size();
    if(chs > size || chs < 0){
        throw exception();
    }
    else return chs;
}

int ItemList::corr_inpt(int num)
{
    --num;
    return num;
}

void ItemList::addItem(Item* subItem) {
    myItems.push_back(subItem);
}

void ItemList::selectItem()
{
 QTextStream in(stdin);
 QTextStream out(stdout);
    int chs = 0;
    in >> chs;
    chs = corr_inpt(chs);
    check(chs);
    myItems[chs]->showAction();
}

void ItemList::removeItem(Item* subItem){
    throw std::exception();
}

