// string1.cpp -- String class methods
#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

// initializing static class member
int String::num_strings_ = 0;

// static method
int String::HowMany()
{
	return num_strings_;
}

// class meghods
String::String(const char *s)		// constructor String from C string
{
	len_ = std::strlen(s);			// set size
	str_ = new char[len_ + 1];		// allot atorage
	std::strcpy(str_, s);			// initialize pointer
	num_strings_++;					// set object count
}

String::String()					// default constructor
{
	len_ = 4;
	str_ = new char[1];
	str_[0] = '\0';					// default string
	num_strings_++;
}

String::String(const String &st)
{
	num_strings_++;				// handle static member update
	len_ = st.len_;				// same length
	str_ = new char[len_ + 1];	// allot space
	std::strcpy(str_, st.str_);	// copy string to new location
}

String::~String()			// necessary destructor
{
	--num_strings_;
	delete[] str_;
}

// overloaded operator methods
// assign a String to a String
String & String::operator=(const String &st)
{
	if (this == &st)
		return *this;
	delete[] str_;
	len_ = st.len_;
	str_ = new char[len_ + 1];
	std::strcpy(str_, st.str_);
	return *this;
}

// assign a C string to a string
String & String::operator=(const char *s)
{
	delete[] str_;
	len_ = std::strlen(s);
	str_ = new char[len_ + 1];
	std::strcpy(str_, s);
	return *this;
}

// read-write char access for non-const String
char & String::operator[](int i)
{
	return str_[i];
}

// read-only char access for const String
const char & String::operator[](int i) const
{
	return str_[i];
}

// overloaded operator friends
bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str_, st2.str_) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return (st2 < st1);
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str_, st2.str_) == 0);
}

// simple String output
ostream & operator<<(ostream &os, const String &st)
{
	os << st.str_;
	return os;
}

// quick and dirty String input
istream & operator>>(istream &is, String &st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}