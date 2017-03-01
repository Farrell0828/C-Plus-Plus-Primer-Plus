// stack.cpp -- Stack member functions
#include "stack.h"
Stack::Stack()		// create an empty stack
{
	top = 0;
}

bool Stack::IsEmpty() const
{
	return top == 0;
}

bool Stack::IsFull() const
{
	return top == Max;
}

bool Stack::Push(const Item &item)
{
	if (top < Max)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::Pop(Item &item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}