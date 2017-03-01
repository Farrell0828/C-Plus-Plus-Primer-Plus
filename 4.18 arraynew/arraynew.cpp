// arraynew.cpp -- pointer addition
#include "iostream"
int main()
{
	using namespace std;
	double * p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 + 1;
	cout << "Now, p3[0] is " << p3[0]
		 << " and p3[1] is " << p3[1] << ".\n";
	p3 = p3 - 1;
	delete [] p3;

	// play time
	int * p4 = new int[3];
	p4[0] = 1;
	p4[1] = 2;
	p4[2] = 3;
	cout << *p4 << endl;
	cout << p4[0] << endl << p4[1] << endl;
	p4++;
	cout << p4[0] << endl << p4[-1] << endl;
	p4--;
	delete [] p4;
	return 0;
}