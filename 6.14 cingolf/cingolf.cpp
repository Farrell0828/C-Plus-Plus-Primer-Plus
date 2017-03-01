// cingolf.cpp -- non-numeric input skipped
#include <iostream>
const int Max = 5;
int main()
{
	using namespace std;
	// get data
	int golf[Max];
	cout << "Please enter your golf scores.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Please enter a number: ";
		}
	}
	// claculate average
	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];
	// report results
	cout << total / Max << " = average score "
		 << Max << " rounds\n";
	return 0;
}