// string1.h -- fixed and augmented string class definition
#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
using std::ostream;
using std::istream;
class String
{
private:
	char *str_;				// pointer to string
	int len_;				// length of string
	static int num_strings_;// num of objects
	static const int CINLIM = 80;	// cin input limit
public:
	// constructor and other methods
	String(const char *s);		// constructor
	String();					// default constructor
	String(const String &);		// copy constructor
	~String();					// destructor
	int length() const { return len_; }
	// overloaded operator methods
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
	// overloaded operator friends
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream &os, const String &st);
	friend istream & operator>>(istream &is, String &st);
	// static function
	static int HowMany();
};
#endif