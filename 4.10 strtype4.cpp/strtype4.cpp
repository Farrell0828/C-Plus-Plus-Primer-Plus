// strtype4.cpp -- line input
#include "iostream"
#include "string"
#include "cstring"
int main()
{
	using namespace std;
	char charr[20];
	string str;

	cout << "Length of string in charr before input: "
		<< strlen(charr) << endl;
	cout << "Length of string in str before input: "
		<< str.size() << endl;
	cout << "Enter a line of text:\n";
	cin.getline(charr, 20);
	cout << "You entered: " << charr << endl;
	cout << "Enter anther line of text:\n";
	getline(cin, str);
	cout << "You entered: " << str << endl;
	cout << "Length of string in charr after input: "
		<< strlen(charr) << endl;
	cout << "Length of string in str after input: "
		<< str.size() << endl;

	// play time
	string str2;
	cout << "Enter a string: ";
	getline(cin, str2);
	cout << str2 << endl;
	string str3;
	cout << "Enter the string again: ";
	getline(cin, str3);
	cout << str3 << endl;

	cout << R"("How are you?", she ask me.
I say: "I am fine, thank you.")";
	
	return 0;
}