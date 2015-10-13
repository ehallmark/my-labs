#include "inventory.h"


Inventory::Inventory() { }

/* Add an item to the inventory with the given name and amount. */
void Inventory::addItem(std::string name, int amount) {
	Inventory::iterator pos = find(name);
	if(pos==end()) {
		//not found
		insert(std::make_pair(name,amount));
	} else {
		//found
		pos->second+= amount;
	}
}
/* Remove all items with this name from the inventory. */
void Inventory::removeItem(std::string name) {
	Inventory::iterator pos = find(name);
	if(pos!=end()){
		erase(pos);
	}
}
/* Return the number of items with this name from the inventory. */
int Inventory::getNumItems(std::string name) {
	Inventory::iterator pos = find(name);
	if (pos!=end()) {
		return pos->second;
	} else {
		return 0;
	}
}

/* Print all the items in this format:
	key value
	key value
	key value
*/
void Inventory::printAllItems() {
	Inventory::iterator it;
	for(it=begin();it!=end(); ++it) {
		std::cout << it->first << ' ' << it->second << '\n';
	}
}