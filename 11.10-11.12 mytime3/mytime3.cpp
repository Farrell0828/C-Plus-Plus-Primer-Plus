// mytime3.cpp -- implementing Time methods
#include "mytime3.h"

Time::Time()
{
	hours_ = minutes_ = 0;
}

Time::Time(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

void Time::AddMin(int m)
{
	minutes_ += m;
	hours_ += minutes_ / 60;
	minutes_ %= 60;
}

void Time::AddHr(int h)
{
	hours_ += h;
}

void Time::ReSet(int h, int m)
{
	hours_ = h;
	minutes_ = m;
}

Time Time::operator+(const Time &t) const
{
	Time sum;
	sum.minutes_ = minutes_ + t.minutes_;
	sum.hours_ = hours_ + t.hours_ + sum.minutes_ / 60;
	sum.minutes_ %= 60;
	return sum;
}

Time Time::operator-(const Time &t) const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes_ + 60 * t.hours_;
	tot2 = minutes_ + 60 * hours_;
	diff.minutes_ = (tot2 - tot1) % 60;
	diff.hours_ = (tot2 - tot1) / 60;
	return diff;
}

Time Time::operator*(const double mult) const
{
	Time result;
	long total = hours_ * mult * 60 + minutes_ * mult;
	result.minutes_ = total % 60;
	result.hours_ = total / 60;
	return result;
}

std::ostream & operator<<(std::ostream &os, const Time &t)
{
	os << t.hours_ << " hours, " << t.minutes_ << " minutes";
	return os;
}