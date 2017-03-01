// stock20.cpp -- augmented version
#include <iostream>
#include "stock20.h"

// constructors
Stock::Stock()		// default constructor
{
	company_ = "no name";
	shares_ = 0;
	share_val_ = 0.0;
	total_val_ = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
	company_ = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company_ << " shares set to 0.\n";
		shares_ = 0;
	}
	else
		shares_ = n;
	share_val_ = pr;
	set_tot();
}

// class destructor
Stock::~Stock() {}		// quiet class destructor

// other methords
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
		share_val_ = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. "
			<< "Transaction is abrted.\n";
	}
	else if (num > shares_)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is abrted.\n";
	}
	else
	{
		shares_ -= num;
		share_val_ = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	shares_ = price;
	set_tot();
}

void Stock::show() const
{
	using std::cout;
	using std::ios_base;
	// set format to #.###
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "Company: " << company_ << "  Shares: " << shares_ << std::endl;
	cout << "  Share Price: $" << share_val_;
	// set format to #.##
	cout.precision(2);
	cout << "  Total Worth: $" << total_val_ << std::endl;

	// restore priginal format and original format
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

const Stock & Stock::topval(const Stock &s) const
{
	if (s.total_val_ > total_val_)
		return s;
	else
		return *this;
}