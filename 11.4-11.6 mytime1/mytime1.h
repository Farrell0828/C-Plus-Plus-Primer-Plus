// mytime1.h -- Time class before operator voerloading
#ifndef MYTIME1_H_
#define MYTIME1_H_

class Time
{
private:
	int hours_;
	int minutes_;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void ReSet(int h = 0, int m = 0);
	Time operator+(const Time &t) const;
	void Show() const;
};
#endif