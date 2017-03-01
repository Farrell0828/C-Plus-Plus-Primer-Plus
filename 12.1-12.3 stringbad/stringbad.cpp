// stringbad.cpp -- StringBad class methods
#include <cstring>
#include "stringbad.h"
using std::cout;

// initializing static class member
int StringBad::num_strings_ = 0;

// class methods
// constructor StringBad from C string
StringBad::StringBad(const char *s)
{
	len_ = std::strlen(s);				// set size
	str_ = new char[len_ + 1];			// allot storage
	std::strcpy(str_, s);				// initialize pointer
	num_strings_++;						// set object count
	cout << num_strings_ << ": \"" << str_
		<< "\" object created\n";		// for your information
}

StringBad::StringBad()					// default constructor
{
	len_ = 4;
	str_ = new char[4];
	std::strcpy(str_, "C++");			// default string
	num_strings_++;
	cout << num_strings_ << ": \"" << str_
		<< "\" default object created\n";	// FYI
}

StringBad::~StringBad()				// necessary destructor
{
	cout << "\"" << str_ << "\" object deleted, ";	// FYI
	--num_strings_;					// required
	cout << num_strings_ << " left\n";	// FYI
	delete[] str_;					// required
}

std::ostream & operator<<(std::ostream &os, const StringBad &st)
{
	os << st.str_;
	return os;
}