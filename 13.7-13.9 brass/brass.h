// brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
// Brass Account Class
class Brass
{
private:
	std::string full_name_;
	long acct_num_;
	double balance_;
public:
	Brass(const std::string &s = "Nullbody", long an = -1,
		double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

// Brass Plus Account Class
class BrassPlus : public Brass
{
private:
	double max_loan_;
	double rate_;
	double owes_bank_;
public:
	BrassPlus(const std::string &s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass &ba, double ml = 500,
		double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetRate(double r) { rate_ = r; }
	void ReaetOwes() { owes_bank_ = 0; }
};
#endif