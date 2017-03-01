// randwalk.cpp -- using the Vector class
// compile with the vector.cpp file
#include <iostream>
#include <cstdlib>		// rand(), srand() prototypes
#include <ctime>		// time() prototypes
#include "vector.h"
int main()
{
	using namespace std;
	using vector::Vector;
	srand(time(0));		// seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		while (result.mag_val() < target)
		{
			direction = rand() % 360;
			step.Reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			<< "has the following location:\n";
		cout << result << endl;
		result.PolarMode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.mag_val() / steps << endl;
		steps = 0;
		result.Reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}