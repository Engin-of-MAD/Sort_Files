#pragma
#include <iostream>
using namespace std;

class Item
{
protected:
	string nameItem;
	string nameOwner;
	void(*my_action) = NULL;
public:
	Item(string nameI) : nameItem(nameI) {}
	string getItemName();
	virtual void show_action() = 0;
	virtual void set_action(string(*action) ()) = 0;
	virtual void addItem(Item* subItem) = 0;
	virtual void removeItem(Item* subItem) = 0;
	virtual void display() = 0;

};


class ClickableItem : public Item {
public:
	void set_action(string(*action) ()) override;
	void show_action() override;
	void display() override;
	void removeItem(Item* subItem) override;
	void addItem(Item* subItem) override;
	ClickableItem(string name) : Item(name) {}
};

class ItemList : public Item {
protected:
	void checkList(int n);
	int setNormalIndex(int index);

	vector<Item*> myItems;

public:
	void set_action(string(*action) ());
	void show_action() override;
	ItemList(string name) : Item(name) {}
	void addItem(Item* subItem) override;

	void removeLastItem();
	void removeItem(Item* name) override;
	void display() override;



};