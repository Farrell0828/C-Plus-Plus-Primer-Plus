// stick20.h -- augmented version
#ifndef STOCK20_H_
#define STOCk20_H_
#include <string>

class Stock
{
private:
	std::string company_;
	int shares_;
	double share_val_;
	double total_val_;
	void set_tot() { total_val_ = shares_ * share_val_; }
public:
	Stock();		// default constructor
	Stock(const std::string &co, long n = 0, double pr = 0.0);
	~Stock();		// do-nothing destructor
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock &topval(const Stock &s) const;
};
#endif	// STOCK20_H_