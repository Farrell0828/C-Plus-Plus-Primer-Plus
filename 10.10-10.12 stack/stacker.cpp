// stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype>
#include "stack.h"
int main()
{
	using namespace std;
	Stack st;		// create an empty stack
	char ch;
	unsigned long po;
	cout << "Please enter A to add a purchase order,\n";
	cout << "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'a':
		case 'A':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.IsFull())
				cout << "stack already full\n";
			else
				st.Push(po);
			break;
		case 'p':
		case 'P': 
			if (st.IsEmpty())
			{
				cout << "stack already empty\n";
			}
			else
			{
				st.Pop(po);
				cout << "PO #" << po << " popped\n";
			}
			break;
		default:
			break;
		}
		cout << "Please enter A to add a purchase order,\n";
		cout << "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}