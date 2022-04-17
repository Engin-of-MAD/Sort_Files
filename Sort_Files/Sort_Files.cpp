using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "menu.h"
/*
class Item
{
protected:
	string nameItem;
	string nameOwner;
	void(*my_action);
public:
	Item(string nameI) : nameItem(nameI){}
	string getItemName() {
		return nameItem;
	}
	virtual void show_action() = 0;
	virtual void set_action( string (*action) () ) = 0;
	virtual void addItem(Item* subItem) = 0;
	virtual void removeItem(Item* subItem) = 0;
	virtual void display() = 0;
	
};
class ClickableItem : public Item {
public:
	void set_action(string (*action) () ) override {
		my_action = action;
	}

	void show_action() override {
		cout << my_action << endl;
	}

	void display() override{
		cout << nameItem << endl;
	}

	void removeItem(Item* subItem) override {
		throw exception();
	}

	void addItem(Item* subItem) override{
		throw exception();
	}
	ClickableItem(string name) : Item(name) {}
};
class ItemList : public Item{
protected:
	void checkList(int n) {
		if (n < 0 or n > myItems.size()) {
			throw exception();
		}
	}

	int setNormalIndex(int index) {
		index -= 1;
		return index;
	}

	vector<Item*> myItems;
	
public:
	void set_action(string (*action) ()) override {
		my_action = action;
	}
	void show_action() override{
		cout << my_action << endl;
	}
	ItemList(string name) : Item(name){}
	void addItem(Item* subItem) override {
		myItems.push_back(subItem);
	}

	void removeLastItem() {
		myItems.pop_back();
	}

	void removeItem(Item* name) override {
		
	}
	void display() override {
		int index = 1;
		for (int i = 0; i < myItems.size(); i++) {
			cout << index << "." << myItems[i]->getItemName() << endl;
			index++;
		}
	}

	void selectItem(int selItem) {
		selItem = setNormalIndex(selItem);
		checkList(selItem);
		cout << myItems[selItem]->getItemName() << endl;
	}
	
};
*/
class SortFile {
protected:
	string myPath;
public:
	SortFile(string path) {
		this->myPath = path;
	}

};



int main()
{
	
	setlocale(LC_ALL, "ru");
	Item* show_text = new ItemList("Показать текст");
	Item* settings = new ItemList("Настройка");
	Item* parametrs = new ItemList("Параметры");
	Item* exit = new ClickableItem("Выход");
	Item* menu = new ItemList("menu");

	menu->addItem(show_text);
	menu->addItem(settings);
	menu->addItem(parametrs);
	menu->addItem(exit);
	//menu->display();
	
}
