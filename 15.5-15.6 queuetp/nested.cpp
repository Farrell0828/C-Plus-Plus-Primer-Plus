// nested.cpp -- using a queue that has a nested class
#include <iostream>
#include <string>
#include "queuetp.h"

int main()
{
	using std::string;
	using std::cin;
	using std::cout;
	QueueTP<string> cs(5);
	string temp;
	while (!cs.IsFull())
	{
		cout << "Please enter your name. You will be "
			"served in the order of arrival.\n"
			"name: ";
		getline(cin, temp);
		cs.EnQueue(temp);
	}
	cout << "The queue is full. Processing begins!\n";
	while (!cs.IsEmpty())
	{
		cs.DeQueue(temp);
		cout << "Now processing " << temp << "...\n";
	}
	return 0;
}