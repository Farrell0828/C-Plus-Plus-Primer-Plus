// tabtenn0.h -- a table-tennis base class
#ifndef TABTENN0_H_
#define TABTENN0_H_
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
	void RestTable(bool v) { has_table_ = v; }
};
#endif