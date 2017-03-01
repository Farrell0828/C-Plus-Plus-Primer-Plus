// stacktem.cpp -- testing the template stack class
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
int main()
{
	using std::cout;
	using std::cin;
	Stack<std::string> st;		// create an empty stack
	char ch;
	std::string po;
	cout << "Please enter A to add a purchase order,\n";
	cout << "P to process a PO, or Q to quit.\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
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