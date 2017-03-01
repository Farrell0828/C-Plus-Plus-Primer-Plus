// 2.2 carrots.cpp

#include "iostream"


int main()
{
	using namespace std;

	int carrots;

	carrots = 25;
	cout << "I have " << carrots << "carrots." << endl;
	carrots = carrots - 1;
	cout << "Crunch, crunch. Now I have " << carrots << "carrots.";
	cin.get();
	return 0;
}