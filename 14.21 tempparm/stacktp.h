// stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_
template <typename T>
class Stack
{
private:
	enum { Max = 10 };		// constant specific to class
	T items[Max];			// holds stack items
	int top;				// index for top stack item
public:
	Stack();
	bool IsEmpty() const;
	bool IsFull() const;
	bool Push(const T &item);	// add item to stack
	bool Pop(T &item);			// pop top into item
};

template <typename T>
Stack<T>::Stack()		// create an empty stack
{
	top = 0;
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
	return top == 0;
}

template <typename T>
bool Stack<T>::IsFull() const
{
	return top == Max;
}

template <typename T>
bool Stack<T>::Push(const T &item)
{
	if (top < Max)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <typename T>
bool Stack<T>::Pop(T &item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
#endif