// calling.cpp -- defining, prototyping, and calling a function
#include <iostream>
void simple();

int main()
{
	using namespace std;
	cout << "main() will claa the simple() function:\n";
	simple();		// function call
	cout << "main() is finished with the simple() function.\n";
	return 0;
}

// function definition
void simple()
{
	using namespace std;
	cout << "I'm but a simple function.\n";
}