// arrstruc.cpp -- an array of structures
#include "iostream"
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

// play time
struct widget
{
	char brand[20];
	int type;
	union id
	{
		long id_num;
		char id_char[20];
	};
	id id_val;
};
union one2all
{
	int int_val;
	long long_val;
	double double_val;
};

int main()
{
	using namespace std;
	inflatable guests[2] = 
	{
		{"Bambi", 0.5, 21.99},
		{"Godzilla", 2000, 565.99}
	};

	cout << "The guests " << guests[0].name << " and " << guests[1].name
		<< "\nhave a combined volume of "
		<< guests[0].volume + guests[1].volume << " cubic feet.\n";
	

	// play time
	one2all pail;
	pail.int_val = 15;
	cout << pail.int_val << endl;
	pail.double_val = 1.38;
	cout << pail.double_val;

	return 0;
}