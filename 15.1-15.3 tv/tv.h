// tv.h -- Tv and Remote classes
#ifndef TV_H_
#define TV_H_

class Tv
{
private:
	int state_;				// on or off
	int volume_;			// assumed to be digitized
	int max_channel_;		// maximum number of channels
	int channel_;			// current channel setting
	int mode_;				// broadcast or cable
	int input_;
public:
	friend class Remote;	// Remote can access Tv private parts
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Tv(int s = Off, int mc = 125) : state_(s), volume_(5),
		max_channel_(mc), channel_(2), mode_(Cable), input_(TV) {}
	void OnOff() { state_ = (state_ == On) ? Off : On; }
	bool IsOn() const { return state_ == On; }
	bool VolUp();
	bool VolDown();
	void ChanUp();
	void ChanDown();
	void SetMode() { mode_ = (mode_ == Antenna) ? Cable : Antenna; }
	void SetInput() { input_ = (input_ == TV) ? DVD : TV; }
	void Settings() const;	// display all settings
};

class Remote
{
private:
	int mode_;				// controls TV or DVD
public:
	Remote(int m = Tv::TV) : mode_(m) {}
	bool VolUp(Tv &t) { return t.VolUp(); }
	bool VolDown(Tv &t) { return t.VolDown(); }
	void OnOff(Tv &t) { t.OnOff(); }
	void ChanUp(Tv &t) { t.ChanUp(); }
	void ChanDown(Tv &t) { t.ChanDown(); }
	void SetChan(Tv &t, int c) { t.channel_ = c; }
	void SetMode(Tv &t) { t.SetMode(); }
	void SetInput(Tv &t) { t.SetInput(); }
};

#endif