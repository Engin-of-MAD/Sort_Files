#include "menu.h"
#include <vector>
#include <iostream>

using namespace std;

string Item::getItemName() {
	return nameItem;
}


void ClickableItem::set_action(string(*action) ())  {
	my_action = action;
}

void ClickableItem::show_action() {
	cout << my_action << endl;
}

void ClickableItem::display() {
	cout << nameItem << endl;
}

void ClickableItem::removeItem(Item* subItem) {
	throw exception();
}

void ClickableItem::addItem(Item* subItem) {
	throw exception();
}



void ItemList::display() {
	int index = 1;
	for (int i = 0; i < myItems.size(); i++) {
		cout << index << "." << myItems[i]->getItemName() << endl;
		index++;
	}
}

void ItemList::removeItem(Item* name) {

}
void ItemList::removeLastItem() {
	myItems.pop_back();
}
void ItemList::addItem(Item* subItem) {
	myItems.push_back(subItem);
}

void ItemList::set_action(string(*action) ())  {
	my_action = action;
}
void ItemList::show_action() {
	cout << my_action << endl;
}
void ItemList::checkList(int n) {
	if (n < 0 or n > myItems.size()) {
		throw exception();
	}
}

int ItemList::setNormalIndex(int index) {
	index -= 1;
	return index;
}