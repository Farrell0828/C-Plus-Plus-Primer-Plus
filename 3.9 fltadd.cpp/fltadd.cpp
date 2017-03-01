// fltadd.cpp -- precision problems with float
#include "iostream"

int main()
{
	using namespace std;

	float a = 2.34e+22f;
	float b = a + 1.0f;
	
	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;

	// playing time
	float f_num = 3.99;
	int n_num = f_num;
	cout << n_num << endl;		// output n_num = 3

	int c = -7;
	int d = 3;
	int f = c / d;
	int g = c % d;
	cout << f << endl << g << endl;		// 余数可以是负数呢。
	
	return 0;
}