// usebrass1.cpp -- testing bank account classes
// compile with brass.cpp
#include <iostream>
#include "brass.h"

int main()
{
	using std::cout;
	using std::endl;

	Brass piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus hoggy("Horatio Hogg", 382288, 3000.00);
	piggy.ViewAcct();
	cout << endl;
	hoggy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Hogg Account: \n";
	hoggy.Deposit(1000.00);
	cout << "New balance: $" << hoggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Pigg Account:\n";
	piggy.Withdraw(4200.00);
	cout << "Pigg account balance: $" << piggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Hogg Account:\n";
	hoggy.Withdraw(4200.00);
	hoggy.ViewAcct();

	return 0;
}