// student.cpp -- Student class using containment
#include "studentc.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;
// public methods
double Student::Average() const
{
	if (scores_.size() > 0)
		return scores_.sum() / scores_.size();
	else
		return 0;
}

const string & Student::Name() const
{
	return name_;
}

double & Student::operator[](int i)
{
	return scores_[i];		// use valarray<double>::operator[]()
}

double Student::operator[](int i) const
{
	return scores_[i];
}

// private method
ostream & Student::arr_out(ostream &os) const
{
	int i;
	int lim = scores_.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores_[i] << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
	{
		os << " empty array ";
	}
	return os;
}

// friend
// use string version of operator>>()
istream & operator>>(istream &is, Student &stu)
{
	is >> stu.name_;
	return is;
}

// use string friend getline(ostream &, const string &)
istream & getline(istream &is, Student & stu)
{
	getline(is, stu.name_);
	return is;
}

// use string version of operator<<()
ostream & operator<<(ostream &os, const Student &stu)
{
	os << "Scores for " << stu.name_ << ":\n";
	stu.arr_out(os);	// use private method for scores
	return os;
}