// hexoct2.ccp -- display values in hex and octal
#include "iostream"

int main()
{
	using namespace std;

	int chest = 42;
	int waist = 42;
	int inseam = 42;
	int who = 88;
	cout << "Monsieur cuts a striking figure!" << endl;
	cout << "chest = " << chest << " (decimal for 42)" << endl;
	cout << hex;
	cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
	cout << who << endl;
	cout << oct;
	cout << "inseam = " << inseam << " (octal for 42)" << endl;
	cout << who << endl;
	return 0;
}