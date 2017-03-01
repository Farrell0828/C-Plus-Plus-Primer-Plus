// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_
typedef unsigned long Item;
class Stack
{
private:
	enum{ Max = 10 };		// constant specific to class
	Item items[Max];		// holds stack items
	int top;				// index for top stack item
public:
	Stack();
	bool IsEmpty() const;
	bool IsFull() const;
	// Push() returns false if stack already is full, true otherwise
	bool Push(const Item &item);	// add item to stack
	// Pop() returns false if stack already is empty, true otherwise
	bool Pop(Item &item);			// pop top into item
};
#endif