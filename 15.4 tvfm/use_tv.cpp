// use_tv.cpp -- uaing the Tv and Remote classes
#include <iostream>
#include "tvfm.h"

int main()
{
	using std::cout;
	Tv s42;
	cout << "Intial settings for 42\" TV:\n";
	s42.Settings();
	s42.OnOff();
	s42.ChanUp();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.ChanUp();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.Settings();
	Remote grey;
	grey.SetChan(s42, 10);
	grey.VolUp(s42);
	grey.VolUp(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.Settings();
	Tv s58(Tv::On);
	s58.SetMode();
	grey.SetChan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.Settings();
	return 0;
}