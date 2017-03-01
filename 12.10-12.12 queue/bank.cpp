// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib>	// for rand() and stand()
#include <ctime>	// for time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool NewCustomer(double x);	// is there a new customer?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// setting things up
	std::srand(std::time(0));	// random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);			// line queue holds up to qs people

	cout << "Enter the number of simulation hours: ";
	int hours;				// hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cycle_limit = MIN_PER_HR * hours;	// # of cycles

	cout << "Enter the average number of customers per hour: ";
	double per_hour;		// average # of arrival per hour
	cin >> per_hour;
	double min_per_cust;	// average time between arrivals
	min_per_cust = MIN_PER_HR / per_hour;

	Item temp;				// new customer data
	long turn_aways = 0;	// turned away by full queue
	long customers = 0;		// joined the queue
	long served = 0;		// served during the simulation
	long sum_line = 0;		// cumulative line length
	int wait_time = 0;		// time until autoteller is free
	long line_wait = 0;		// cumulative time in line

	// running the simulation
	for (int cycle = 0; cycle < cycle_limit; ++cycle)
	{
		if (NewCustomer(min_per_cust))	// have newcomer
		{
			if (line.IsFull())
			{
				++turn_aways;
			}
			else
			{
				++customers;
				temp.Set(cycle);	// cycle = time of arrival
				line.EnQueue(temp);	// add newcomer to line
			}
		}
		if (wait_time <= 0 && !line.IsEmpty())
		{
			line.DeQueue(temp);			// attend next customer
			wait_time = temp.PTime();	// for wait_time minuters
			line_wait += cycle - temp.When();
			++served;
		}
		if (wait_time > 0)
			--wait_time;
		sum_line += line.QueueCount();
	}

	// report results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turn_aways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << double(sum_line) / cycle_limit << endl;
		cout << " average wait time: "
			<< double(line_wait) / served << " minutes\n";
	}
	else
	{
		cout << "No customers!\n";
	}
	cout << "Done!\n";

	return 0;
}

// x = average time, in minuters, between customers
// return value is true if customer shows up this minute
bool NewCustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}