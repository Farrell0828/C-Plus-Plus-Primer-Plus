// usebrass2.cpp -- polymorphic example
// compile with brass.cpp
#include <iostream>
#include <string>
#include "brass.h"
const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	Brass *p_clients[CLIENTS];
	std::string temp;
	long temp_num;
	double temp_bal;
	char kind;

	for (int i = 0; i < CLIENTS; ++i)
	{
		cout << "Enter client's name: ";
		getline(cin, temp);
		cout << "Enter client's account number: ";
		cin >> temp_num;
		cout << "Enter opening balance: $";
		cin >> temp_bal;
		cout << "Enter 1 for Brass Account or "
			<< "2 for BrassPlus Account: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";
		if (kind == '1')
		{
			p_clients[i] = new Brass(temp, temp_num, temp_bal);
		}
		else
		{
			double t_max, t_rate;
			cout << "Enter teh overdraft limit: $";
			cin >> t_max;
			cout << "Enter the interest rate "
				<< "as a decimal fraction: ";
			cin >> t_rate;
			p_clients[i] = new BrassPlus(temp, temp_num, temp_bal,
				t_max, t_rate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; ++i)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; ++i)
		delete p_clients[i];	// free memory
	cout << "Done.\n";
	return 0;
}