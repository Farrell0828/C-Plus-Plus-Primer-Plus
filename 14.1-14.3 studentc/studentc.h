// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_
#include <iostream>
#include <string>
#include <valarray>
class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name_;		// contained object
	ArrayDb scores_;		// contained object
	// private method for scores output
	std::ostream & arr_out(std::ostream &os) const;
public:
	Student() : name_("Null Student"), scores_() {}
	explicit Student(const std::string &s)
		: name_(s), scores_() {}
	explicit Student(int n) : name_("Nully"), scores_(n) {}
	Student(const std::string &s, int n)
		: name_(s), scores_(n) {}
	Student(const std::string &s, const ArrayDb &a)
		: name_(s), scores_(a) {}
	Student(const char *str, const double *pd, int n)
		: name_(str), scores_(pd, n) {}
	~Student() {}
	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);
	double operator[](int i) const;
	// friends
	// input
	friend std::istream & operator>>(std::istream &is,
		Student &stu);		// 1 word
	friend std::istream & getline(std::istream &is,
		Student &stu);		// 1 line
	// output
	friend std::ostream & operator<<(std::ostream &os,
		const Student &stu);
};
#endif