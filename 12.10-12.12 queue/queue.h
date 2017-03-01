// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
// This queue will contain Customer items
class Customer
{
private:
	long arrive_;			// arrival time for customer
	int process_time_;		// processing time for customer
public:
	Customer() { arrive_ = process_time_ = 0; }
	void Set(long when);
	long When() const { return arrive_; }
	int PTime() const { return process_time_; }
};

typedef Customer Item;

class Queue
{
private:
	// class scope definitions
	// Node is a nested structure definition loval to this c
	struct Node { Item item; struct Node *next; };
	enum { Q_SIZE = 10 };
	// private class members
	Node *front_;			// pointer to front fo Queue
	Node *rear_;			// pointer to rear of Queue
	int items_;				// current number of items in Queue
	const int q_size_;		// maximum number of items in Queue
	// preemptive definitions to prevent public copying
	Queue(const Queue &q) : q_size_(0) {}
	Queue & operator=(const Queue &q) { return *this; }
public:
	Queue(int qs = Q_SIZE);		// create queue with a qs limit
	~Queue();
	bool IsEmpty() const;
	bool IsFull() const;
	int QueueCount() const;
	bool EnQueue(const Item &item);		// add item to end
	bool DeQueue(Item &item);			// remove item from front
};
#endif