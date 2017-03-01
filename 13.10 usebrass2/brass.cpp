// brass.cpp -- bank account class methods
#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format SetFormat();
void restore(format f, precis p);

// Brass methods
Brass::Brass(const string &s, long an, double bal)
{
	full_name_ = s;
	acct_num_ = an;
	balance_ = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; "
		<< "deposit is cancelled.\n";
	else
		balance_ += amt;
}

void Brass::Withdraw(double amt)
{
	// set up ###.## format
	format initial_state = SetFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "Withdrawal amount must be positive; "
		<< "withdrawal canceled.\n";
	else if (amt <= balance_)
		balance_ -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		<< " exceeds your balance.\n"
		<< "Withdrawal canceled.\n";
	restore(initial_state, prec);
}

double Brass::Balance() const
{
	return balance_;
}

void Brass::ViewAcct() const
{
	// set up ###.## format
	format initial_state = SetFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << full_name_ << endl;
	cout << "Account Number: " << acct_num_ << endl;
	cout << "Balance: $" << balance_ << endl;
	restore(initial_state, prec);	// restore original format
}

// BrassPlus Methods
BrassPlus::BrassPlus(const string &s, long an, double bal,
	double ml, double r) : Brass(s, an, bal)
{
	max_loan_ = ml;
	owes_bank_ = 0.0;
	rate_ = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
	: Brass(ba)		// uses implicit copy constructor
{
	max_loan_ = ml;
	owes_bank_ = 0.0;
	rate_ = r;
}

// redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
	// set up ###.## format
	format initial_state = SetFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();		// display base portion
	cout << "Maximum loan: $" << max_loan_ << endl;
	cout << "Owed to bank: $" << owes_bank_ << endl;
	cout.precision(3);		// ###.### format
	cout << "Loan Rate: " << 100 * rate_ << "%\n";
	restore(initial_state, prec);
}

// redefine how WithDraw() works
void BrassPlus::Withdraw(double amt)
{
	// set up ###.## format
	format initial_state = SetFormat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	}
	else if (amt <= bal + max_loan_ - owes_bank_)
	{
		double advance = amt - bal;
		owes_bank_ += advance * (1.0 + rate_);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finace charge: $" << advance * rate_ << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
	{
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	}
	restore(initial_state, prec);
}

format SetFormat()
{
	// set up ###.## format
	return cout.setf(std::ios_base::fixed,
		std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}