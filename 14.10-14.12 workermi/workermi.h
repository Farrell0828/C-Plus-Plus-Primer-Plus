// workermi.h -- working classes with MI
#ifndef WORKERMI_H_
#define WORKERMI_H_
#include <string>

class Worker	// an abstract base class
{
private:
	std::string full_name_;
	long id_;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : full_name_("no one"), id_(0L) {}
	Worker(const std::string &s, long n)
		: full_name_(s), id_(n) {}
	virtual ~Worker() = 0;	// pure virtual function
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
	int panache_;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache_(0) {}
	Waiter(const std::string &s, long n, int p = 0)
		: Worker(s, n), panache_(p) {}
	Waiter(const Worker &wk, int p = 0)
		: Worker(wk), panache_(p) {}
	void Set();
	void Show() const;
};

class Singer : virtual public Worker
{
protected:
	enum {
		other, alto, contralto, soprano,
		bass, baritone, tenor
	};
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static char *pv_[Vtypes];	// string equivs of voice types
	int voice_;
public:
	Singer() : Worker(), voice_(other) {}
	Singer(const std::string &s, long n, int v = other)
		: Worker(s, n), voice_(n) {}
	Singer(const Worker &wk, int v = other)
		: Worker(wk), voice_(v) {}
	void Set();
	void Show() const;
};

// multiple inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string &s, long n,
		int p = 0, int v = other)
		: Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	SingingWaiter(const Worker &wk, int p = 0, int v = other)
		: Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	SingingWaiter(const Waiter &wk, int v = other)
		: Worker(wk), Waiter(wk), Singer(wk, v) {}
	SingingWaiter(const Singer &wk, int p = 0)
		: Worker(wk), Waiter(wk, p), Singer(wk) {}
	void Set();
	void Show() const;
};

#endif