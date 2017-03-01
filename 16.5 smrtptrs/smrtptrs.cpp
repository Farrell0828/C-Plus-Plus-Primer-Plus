// smrtptrs.cpp -- using three kinds of smart pointers
// requires support of c++11 shared_ptr and unique_ptr
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) : str(s)
	{
		std::cout << "Object created!\n";
	}
	~Report() { std::cout << "Object deleted!\n"; }
	void comment() const { std::cout << str << std::endl; }
};

int main()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();		// use -> to invoke a member function
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
	{
		int a = 4;
		std::auto_ptr<int> psi(&a);
		std::cout << a << std::endl << *psi << std::endl;
	}
	return 0;
}