#include "../lib/order.h"

// Constructor
Order::Order()
{
	items = new std::map<std::string, int>();
}

// Constructor which allocates one item
Order::Order(std::string i)
{
	// Allocate items
	items = new std::map<std::string, int>();

	// insert item = i, amount = 1
	// Only inserts if the map does not already contain an element with the key i
	items->insert(std::make_pair(i, 1));
	// can use (*items)[i] = 1, which does not care if the key already exists
}

// Copy Constructor - Part 1
Order::Order(const Order &rhs) {
	// STUB: Assign rhs contents to this
}

Order::~Order() {
	delete items;
}

// Deletes all items in variable ITEMS.
void Order::clearOrder() {
	items->clear();
}

// Prints out what items are in the order and their corresponding amounts - Part 2
std::ostream& operator<<(std::ostream& os, const Order& o) {
	// STUB: Display each item and its amount
	return os;
}

// Assigns Order RHS values to the current Order's values - Part 2
Order& Order::operator=(const Order &rhs) {
	// Starter code: self-assignment can cause unseen problems. It won't
	// happen in this program, but let's get you in the habit early.
	if(this == &rhs) {
		return *this;
	}

	// STUB: remove any elements in the current Order before assigning all
	// rhs's values to "this".

	return *this;
}

/* 
Part 2
This operator should create a new Order that represents the
combined outcome of the current Order and the Order passed in via
parameter.
Note: It should not directly modify the current Order, but return
a copy of the combined Order instead. 
*/
Order Order::operator+(const Order &rhs)
{
	// Starter code: operator+ should not modify THIS, so we make a copy
	Order lhs(*this);

	// STUB: Add all items and their amounts to the current Order,
	// and return the final merged Order.

	return lhs;
}