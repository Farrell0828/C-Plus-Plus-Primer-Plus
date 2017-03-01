// stacktp1.h -- modified stack template
#ifndef STACKTP1_H_
#define STACKTP1_H_

template <typename T>
class Stack
{
private:
	enum { SIZE = 10 };		// default size
	int stack_size_;
	T *items_;				// holds stack items
	int top_;				// index for top stack item
public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack &st);
	~Stack() { delete[] items_; }
	bool IsEmpty() { return top_ == 0; }
	bool IsFull() { return top_ == SIZE; }
	bool Push(const T &item);		// add item to stack
	bool Pop(T &item);				// pop top into item
	Stack & operator=(const Stack &st);
};

template<typename T>
Stack<T>::Stack(int ss) : stack_size_(ss), top_(0)
{
	items_ = new T[stack_size_];
}

template <typename T>
Stack<T>::Stack(const Stack &st)
{
	stack_size_ = st.stack_size_;
	top_ = st.top_;
	items_ = new T[stack_size_];
	for (int i = 0; i < top_; ++i)
		items_[i] = st.items_[i];
}

template <typename T>
bool Stack<T>::Push(const T &item)
{
	if (top_ < stack_size_)
	{
		items_[top_++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool Stack<T>::Pop(T &item)
{
	if (top_ > 0)
	{
		item = items_[--top_];
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> &st)
{
	if (this == &st)
		return *this;
	delete[] items_;
	stack_size_ = st.stack_size_;
	top_ = st.top_;
	items_ = new T[stack_size_];
	for (int i = 0; i < top_; ++i)
		items_[i] = st.items_[i];
	return *this;
}
#endif