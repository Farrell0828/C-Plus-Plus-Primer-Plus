// tabtenn1.h -- a table-tennis base class
#ifndef TABTENN1_H_
#define TABTENN1_H_
#include <string>
using std::string;
// simple base class
class TableTennisPlayer
{
private:
	string firstname_;
	string lastname_;
	bool has_table_;
public:
	TableTennisPlayer(const string &fn = "none",
					  const string &ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return has_table_; }
	void ResetTable(bool v) { has_table_ = v; }
};

// simple derived class
class RatedPlayer : public TableTennisPlayer
{
private:
	unsigned int rating_;
public:
	RatedPlayer(unsigned int r = 0, const string &fn = "none",
				const string &ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
	unsigned int Rating() const { return rating_; }
	void ResetRating(unsigned int r) { rating_ = r; }
};
#endif