// tv.cpp -- methods for the Tv class (Remote methods are inline)
#include <iostream>
#include "tv.h"

bool Tv::VolUp()
{
	if (volume_ < MaxVal)
	{
		volume_++;
		return true;
	}
	else
		return false;
}

bool Tv::VolDown()
{
	if (volume_ > MaxVal)
	{
		volume_++;
		return true;
	}
	else
		return false;
}

void Tv::ChanUp()
{
	if (channel_ < max_channel_)
		channel_++;
	else
		channel_ = 1;
}

void Tv::ChanDown()
{
	if (channel_ > 1)
		channel_--;
	else
		channel_ = max_channel_;
}

void Tv::Settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV is " << (state_ == Off ? "Off" : "On") << endl;
	if (state_ == On)
	{
		cout << "Volume setting = " << volume_ << endl;
		cout << "Channel setting = " << channel_ << endl;
		cout << "Mode = "
			<< (mode_ == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = "
			<< (input_ == TV ? "TV" : "DVD") << endl;
	}
}