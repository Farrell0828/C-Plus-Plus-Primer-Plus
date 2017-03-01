// chartype.cpp -- the char type
#include "iostream"
int main()
{
	using namespace std;

	char ch;
	cout << "Enter a chatacter:" << endl;
	cin >> ch;
	cout << "Hola! Thank you for the " << ch << " character." << endl;
	ch = 77;
	cout << ch << endl;
	int n_ch = ch;
	int n_n_ch = 'M';
	cout << n_ch << endl << n_n_ch << endl;
	return 0;
}