// stock10.h -- Stock class declaration with constructors, destructor added
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class Stock
{
private:
	std::string company_;
	long shares_;
	double shares_val_;
	double total_val_;
	void set_tot() { total_val_ = shares_ * shares_val_; }
public:
	// two constructors
	Stock();			// default constructor
	Stock(const std::string &co, long n = 0, double pr = 0.0);
	~Stock();			// noisy destructor
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};
#endif	// STOCK10_H_