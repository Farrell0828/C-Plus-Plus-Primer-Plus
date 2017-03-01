// bondini.cpp -- using escape sequences
#include "iostream"

int main()
{
	using namespace std;

	cout << "Operation \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code: ________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "Your entered " << code << endl;
	cout << "\aCode verified Proceed with Plan Z3!\n";

	// playing time
	int k\u00F6rper;
	cout << "Let them eat g\u00E2teau k\u00F6rper.\n";		// win32 cmd can't support this.
	
	wchar_t bob = L'p';
	wcout << L"tall" << endl;		// wchar_t.

	bool is_ready = true;
	int i = true;
	bool j = -8;
	cout << is_ready << endl << i << endl << j;		// -8 is true.
	return 0;
}