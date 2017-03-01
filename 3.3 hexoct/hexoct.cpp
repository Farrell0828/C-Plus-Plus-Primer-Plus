// hexoct.cpp -- shows hex and octal lliterals
#include "iostream"

int main()
{
	using namespace std;

	int chest = 42;
	int waist = 0x42;
	int inseam = 042;

	cout << "Monsieur cuts a striking figurel!" << endl
		<< "chest = " << chest << " (42 in decimal)" << endl
		<< "waist = " << waist << " (0x42 in hex)" << endl
		<< "inseam = " << inseam << " (042 in octal)" << endl;
	cin.get();
	return 0;
}