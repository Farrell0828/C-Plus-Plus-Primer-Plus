// mytime0.cpp -- implementing Time methods
#include <iostream>
#include "mytime1.h"

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

void Time::Show() const
{
	std::cout << hours_ << " hours, " << minutes_ << " minutes";
}