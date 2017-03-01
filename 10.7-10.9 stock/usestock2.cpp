// usestock2.cpp -- using the Stock class
// compile with stock20.cpp
#include <iostream>
#include "stock20.h"
const int Stks = 4;

int main()
{
	Stock stocks[Stks] =
	{
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};		// create an array of initialized objects
	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < Stks; ++st)
		stocks[st].show();
	const Stock *top = &stocks[0];		// set pointer to first element
	for (st = 1; st < Stks; ++st)
		top = &top->topval(stocks[st]);
	// now top pointers to the most valuable holding
	std::cout << "\nMost valuable holding:\n";
	top->show();
	return 0;
}