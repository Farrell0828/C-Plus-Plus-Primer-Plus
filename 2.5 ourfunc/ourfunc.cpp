// ourfunc.cpp -- defining your own function
#include "iostream"
void Simon(int);

int main()
{
	using namespace std;

	Simon(3);
	cout << "Pick an integer: ";
	int count;
	cin >> count;
	Simon(count);
	cout << "Done!" << endl;
	cin.get();
	cin.get();
	return 0;
}

void Simon(int n)
{
	using namespace std;

	cout << "Simon says touch your toes " << n << " times.";
}