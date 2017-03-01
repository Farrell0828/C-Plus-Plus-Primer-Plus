// convert.cpp -- convert stone to pounds
#include "iostream"
double StoneTolb(double);

int main()
{
	using namespace std;

	cout << "Enter the weight in stone: ";
	double stone;
	cin >> stone;
	double pounds = StoneTolb(stone);
	cout << stone << " stone = " << pounds << " pounds.";
	cin.get();
	cin.get();
	return 0;
}

double StoneTolb(double sts)
{
	return 14 * sts;
}