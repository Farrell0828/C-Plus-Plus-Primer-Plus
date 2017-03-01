// queuetp.h -- queue template with a nested class
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename Item>
class QueueTP
{
private:
	enum { Q_SIZE = 10 };
	// Node is a nested class definition
	class Node
	{
	public:
		Item item;
		Node *next;
		Node(const Item &i) : item(i), next(nullptr) {}
	};
	Node *front;		// pointer to front of Queue
	Node *rear;			// pointer to rear of Queue
	int items;			// current number of items in Queue
	const int qsize;	// maxinum number of items in Queue
	QueueTP(const QueueTP &q) : qsize(0) {}
	QueueTP & operator=(const QueueTP &q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool IsEmpty() const { return items == 0; }
	bool IsFull() const { return items == qsize; }
	int QueueCount() const { return items; }
	bool EnQueue(const Item &item);
	bool DeQueue(Item &item);		// remove item from front
};

// Queue methods
template <typename Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = 0;
	items = 0;
}

template <typename Item>
QueueTP<Item>::~QueueTP()
{
	Node *temp;
	while (front != 0)		// while queue is not yet empty
	{
		temp = front;		// save address of front item
		front = front->next;// reset pointer to next item
		delete temp;		// delete former front
	}
}

// Add item to queue
template <typename Item>
bool QueueTP<Item>::EnQueue(const Item &item)
{
	if (IsFull())
		return false;
	Node *add = new Node(item);		// create node
	// on failure, new throws std::bad_alloc exception
	items++;
	if (front == 0)			// if queue is empty
		front = add;
	else
		rear->next = add;	// else palce at rear
	rear = add;				// have rear pointer to new node
	return true;
}

// Place front item into item variable and remove from queue
template <typename Item>
bool QueueTP<Item>::DeQueue(Item &item)
{
	if (front == 0)
		return false;
	item = front->item;		// set item to first item in queue
	items--;
	Node *temp = front;		// save location of first item
	front = front->next;	// reset front to next item
	delete temp;
	if (items == 0)
		rear = 0;
	return true;
}

#endif