// assign.cpp -- type changes on initialization
#include "iostream"

int main()
{
	using namespace std;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;
	int guess(3.9832);
	int debt = 7.2E12;
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;

	// play time
	const int code = 66;
	int x = 66;
	char c1 = { 31 };
	char c2 = { 66 };
	char c3 = { code };
	char c4 = { 1 };
	x = 31325;
	char c5 = x;
	cout << c1 << endl << c2 << endl << c3 << endl << c4 << endl << c5 << endl;

	return 0;
}