// stkoptr1.cpp -- testing stack of pointers
#include <iostream>
#include <cstdlib>		// for rand(), srand()
#include <ctime>		// for time()
#include "stacktp1.h"
const int Num = 10;
int main()
{
	std::srand(std::time(0));	// randomize rand()
	std::cout << "Please enter stack size: ";
	int stack_size;
	std::cin >> stack_size;
	// create an empty stack with stack_size slots
	Stack<const char *> st(stack_size);
	// in basket
	const char * in[Num] =
	{
		" 1: Hank Gilgamesh", " 2: Kiki Ishtar",
		" 3: Betty Rocker", " 4: Ian Flagranti",
		" 5: Wolfgang Kibble", " 6: Portia Koop",
		" 7: Joy Almondo", " 8: Xaverie Paprika",
		" 9: Juan Moore", "10: Misha Mache"
	};
	// out basket
	const char * out[Num];
	int proccessed = 0;
	int next_in = 0;
	while (proccessed < Num)
	{
		if (st.IsEmpty())
			st.Push(in[next_in++]);
		else if (st.IsFull())
			st.Pop(out[proccessed++]);
		else if (std::rand() % 2 && next_in < Num)	// 50-50 chance
			st.Push(in[next_in++]);
		else
			st.Pop(out[proccessed++]);
	}
	for (int i = 0; i < Num; i++)
		std::cout << out[i] << std::endl;
	std::cout << "Bye\n";
	return 0;
}