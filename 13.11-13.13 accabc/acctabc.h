// acctabc.h -- bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H
#include <iostream>
#include <string>

// Abstract Base Class
class AcctABC
{
private:
	std::string full_name_;
	long acct_num_;
	double balance_;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName() const { return full_name_; }
	long AcctNum() const { return acct_num_; }
	Formatting SetFormat() const;
	void Restore(Formatting &f) const;
public:
	AcctABC(const std::string &s = "Nullbody", long an = -1,
		double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;	// pure virtual function
	double Balance() const { return balance_; }
	virtual void ViewAcct() const = 0;		// pure virtual function
	virtual ~AcctABC() {}
};

// Brass Account Class
class Brass : public AcctABC
{
public:
	Brass(const std::string &s = "Nullbody", long an = -1,
		double bal = 0.0) : AcctABC(s, an, bal) {}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

// Brass Plus Account Class
class BrassPlus : public AcctABC
{
private:
	double max_loan_;
	double rate_;
	double owes_bank_;
public:
	BrassPlus(const std::string &s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { max_loan_ = m; }
	void ResetRate(double r) { rate_ = r; }
	void ResetOwes() { owes_bank_ = 0; }
};
#endif