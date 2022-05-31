#include <QCoreApplication>
#include "menu.h"
#include "filesearch.h"
#include <QTextStream>
#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL,"ru");

    Plug plg;
    FileSearch file;
    //init items

    Item* menu = new ItemList("Главное меню");
    //create elements menu
    Item* start = new ClickableItem("Старт");
    Item* p_sort = new ItemList("Параметры Сортировки");
    Item* setup = new ItemList("Настройки");
    Item* exit = new ClickableItem("Выход");

    //add elements in main menu

    menu->addItem(start);
    menu->addItem(p_sort);
    menu->addItem(setup);
    menu->addItem(exit);

    //creating elements for submenu p_sort


    Item* saveP = new ClickableItem("Сохранить настройки");
    Item* addMP = new ItemList("Добавить");
    Item* returnToMainMenu = new ClickableItem("Вернуться в главное меню");

    //adding elements in submenu p_sort


    p_sort->addItem(addMP);
    p_sort->addItem(saveP);
    p_sort->addItem(returnToMainMenu);

    //if(){}

    //creating elements for submenu setup

    Item* logger = new ClickableItem("Журнал работы приложения");
    Item* showLogger = new ClickableItem("Показать журнал работы ");
    Item* countsOutPath = new ClickableItem("Количество типов сортируемых файлов");
    Item* backMode = new ClickableItem("Фоновый режим");

    //adding elements in submenu setup

    setup->addItem(logger);
    setup->addItem(showLogger);
    setup->addItem(countsOutPath);
    setup->addItem(backMode);
    setup->addItem(returnToMainMenu);



    QObject::connect(start, &Item::selectedItem, &plg, &Plug::ShowMsg);
    QObject::connect(p_sort, &Item::selectedItem, p_sort, &Item::nextMenu);
    QObject::connect(addMP, &Item::selectedItem, &file, &FileSearch::inputC);
    QObject::connect(saveP, &Item::selectedItem, &file, &FileSearch::inputC);
    QObject::connect(returnToMainMenu, &Item::selectedItem, menu, &Item::nextMenu);
    QObject::connect(&file, &FileSearch::returnInMenu, p_sort, &Item::nextMenu);
    //QObject::connect(addMP, &Item::selectedItem, &file,);


    menu->display();
    menu->selectItem();



    return 0;
}
