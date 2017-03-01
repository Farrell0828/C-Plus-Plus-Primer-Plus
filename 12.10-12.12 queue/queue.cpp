// queue.cpp -- Queue and Customer methods
#include <cstdlib>
#include "queue.h"

// Queue methods
Queue::Queue(int qs) : q_size_(qs)
{
	front_ = rear_ = NULL;
	items_ = 0;
}

Queue::~Queue()
{
	Node *temp;
	while (front_ != NULL)		// while queue is not yet empty
	{
		temp = front_;			// save address of front item
		front_ = front_->next;	// reset pointer to next item
		delete temp;			// delete format front
	}
}

bool Queue::IsEmpty() const
{
	return items_ == 0;
}

bool Queue::IsFull() const
{
	return items_ == q_size_;
}

int Queue::QueueCount() const
{
	return items_;
}

// add item to queue
bool Queue::EnQueue(const Item &item)
{
	if (IsFull())
		return false;
	Node *add = new Node;		// create node
	// on failure, new throws std::bad_alloc exception
	add->item = item;			// set node pointers
	add->next = NULL;			// or nullptr
	items_++;
	if (front_ == NULL)		// if queue is empty
		front_ = add;		// place item at front
	else
		rear_->next = add;	// else place at rear
	rear_ = add;			// have rear pointer to new node
	return true;
}

// place front item into item variable and remove from queue
bool Queue::DeQueue(Item &item)
{
	if (front_ == NULL)
		return false;
	item = front_->item;	// set item to first item in queue
	items_--;
	Node *temp = front_;	// save lovation of first item
	front_ = front_->next;	// reset front to next item
	delete temp;			// delete formar first item
	if (items_ == 0)
		rear_ = NULL;
	return true;
}

// time set to a random value in the range 1 - 3
void Customer::Set(long when)
{
	process_time_ = std::rand() % 3 + 1;
	arrive_ = when;
}