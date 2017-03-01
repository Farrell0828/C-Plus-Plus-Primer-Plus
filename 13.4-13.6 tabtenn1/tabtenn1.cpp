// tabtenn1.cpp -- simple base-class methods
#include <iostream>
#include "tabtenn1.h"

TableTennisPlayer::TableTennisPlayer(const string &fn,
	const string &ln, bool ht) : firstname_(fn),
	lastname_(ln), has_table_(ht) {}

void TableTennisPlayer::Name() const
{
	std::cout << lastname_ << ", " << firstname_;
}

// RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r, const string &fn,
	const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
	rating_ = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
	: TableTennisPlayer(tp), rating_(r) {}