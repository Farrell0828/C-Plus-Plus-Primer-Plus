// topfive.cpp -- handling an array of string objects
#include <iostream>
#include <string>
using namespace std;
const int Size = 5;
void display(const string sa[], int n);
int main()
{
	string list[Size];		// an array holding 5 string object
	cout << "Enter your " << Size << " favorite astronomical sights:\n";
	for (int i = 0; i < Size; i++)
	{
		cout << i + 1 << ": ";
		getline(cin, list[i]);
	}
	cout << "Your list:\n";
	display(list, Size);
	return 0;
}

void display(const string sa[], int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ": " << sa[i] << endl;
}