// tabtenn0.cpp -- simple base-class methods
#include <iostream>
#include "tabtenn0.h"

TableTennisPlayer::TableTennisPlayer(const string &fn,
	const string &ln, bool ht) : firstname_(fn),
	lastname_(ln), has_table_(ht) {}

void TableTennisPlayer::Name() const
{
	std::cout << lastname_ << ", " << firstname_;
}