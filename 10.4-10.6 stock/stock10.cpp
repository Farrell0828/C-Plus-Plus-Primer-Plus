// stock10.cpp -- Stock class with constructors, destructor added
#include <iostream>
#include "stock10.h"

// constructors (verbose versions)
Stock::Stock()			// default constructors
{
	std::cout << "Default constructor called\n";
	company_ = "no name";
	shares_ = 0;
	shares_val_ = 0.0;
	total_val_ = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	company_ = co;

	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company_ << " shares set to 0.\n";
		shares_ = 0;
	}
	else
		shares_ = n;
	shares_val_ = pr;
	set_tot();
}

// calss destructor
Stock::~Stock()			// verbose class destructor
{
	std::cout << "Bye, " << company_ << "!\n";
}

// other methods
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}

	else
	{
		shares_ += num;
		shares_val_ = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares_)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares_ -= num;
		shares_val_ = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	shares_val_ = price;
	set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	// set format ro #.###
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "Company: " << company_
		<< "  Shares: " << shares_ << endl;
	cout << "  Share Price: $" << shares_val_;

	// set format to #.##
	cout.precision(2);

	cout << "  Total Worth: $" << total_val_ << endl;

	// restore original format
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}