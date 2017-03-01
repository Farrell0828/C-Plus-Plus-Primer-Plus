// worker0.h -- working classes
#ifndef WORKER_H_
#define WORKER_H_
#include <string>

class Worker	// an abstract base class
{
private:
	std::string full_name_;
	long id_;
public:
	Worker() : full_name_("no one"), id_(0L) {}
	Worker(const std::string &s, long n)
		: full_name_(s), id_(n) {}
	virtual ~Worker() = 0;	// pure virtual destructor
	virtual void Set();
	virtual void Show() const;
};

class Waiter : public Worker
{
private:
	int panache_;
public:
	Waiter() : Worker(), panache_(0) {}
	Waiter(const std::string &s, long n, int p = 0)
		: Worker(s, n), panache_(p) {}
	Waiter(const Worker & wk, int p = 0)
		: Worker(wk), panache_(p) {}
	void Set();
	void Show() const;
};

class Singer : public Worker
{
protected:
	enum { other, alto, contralto, soprano,
	       bass, baritone, tenor };
	enum { Vtypes = 7 };
private:
	static char *pv_[Vtypes];	// string equivs of voice types
	int voice_;
public:
	Singer() : Worker(), voice_(other) {}
	Singer(const std::string &s, long n, int v = other)
		: Worker(s, n), voice_(v) {}
	Singer(const Worker &wk, int v = other)
		: Worker(wk), voice_(v) {}
	void Set();
	void Show() const;
};

#endif