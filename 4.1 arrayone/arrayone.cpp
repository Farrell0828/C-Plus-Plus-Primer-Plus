// arrayone.cpp -- small arrays of integers
#include "iostream"
int main()
{
	using namespace std;
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;
	int yamcosts[3] = { 20, 30, 5 };
	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs ";
	cout << yamcosts[1] << " cents per yam.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "The total yam expense is " << total << " cents.\n";
	cout << "\nSize of yams array = " << sizeof yams;
	cout << " bytes.\n";
	cout << "Size of one element = " << sizeof yams[0];
	cout << " bytes.\n";

	// play time.
	int cards[4] = { 3, 6, 8, 10 };
	int hand[4];
	cout << cards[3] << endl;
	cout << hand[1] << endl;

	short things[] = { 1, 5, 3, 8 };
	int num_elements = sizeof things / sizeof(short);
	cout << num_elements << endl;

	char dog[8] = { 'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I' };
	char cat[8] = { 'f', 'a', 't', 'e', 's', 's', 'a', '\0' };
	cout << dog << endl;
	cout << cat << endl;

	return 0;
}