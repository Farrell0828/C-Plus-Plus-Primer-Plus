// getinfo.cpp : �������̨Ӧ�ó������ڵ㡣

#include "iostream"

int main()
{
	using namespace std;

	int carrots;

	cout << "How many carrots do you have?\n";
	cin >> carrots;
	carrots = carrots + 2;
	cout << "Here are two more. " << "Now you have " << carrots << " carrots." << endl;
	return 0;
}