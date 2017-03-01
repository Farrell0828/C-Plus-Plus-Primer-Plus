// exceed.cpp -- exceeding some integer limits
#include "iostream"
#define ZERO 0	// make ZERO
int main()
{
	using namespace std;

	short sam = SHRT_MAX;
	unsigned short sue = sam;

	cout << "Sam has " << sam << " dollars and Sue has " << sue
		<< " dollars deposited." << endl
		<< "Add $1 to each account." << endl << "Now ";
	sam = sam + 1;
	sue = sue + 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue
		<< " dollars deposited.\nPoor Sam!" << endl << endl;
	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue
		<< " dollars deposited." << endl
		<< "Take $1 from each account." << endl << "Now";
	sam = sam - 1;
	sue = sue - 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue
		<< " dollars deposited.\nLucky Sue!" << endl;
	cin.get();
	return 0;
}
