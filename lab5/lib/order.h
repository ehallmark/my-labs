#include <map>
#include <string>
#include <iostream>

class Order {
	public:
		Order();
		Order(std::string);
		Order(const Order &o);
		~Order();
		void clearOrder();
		Order& operator=(const Order &rhs);
		Order operator+(const Order &rhs);

	private:
		std::map<std::string, int> *items;	// Key = item name, Value = amount of that item
};