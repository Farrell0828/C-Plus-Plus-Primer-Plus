// tvfm.h -- Tv and Remote classes
#ifndef TVFM_H_
#define TVFM_H_

class Tv;

class Remote
{
private:
	int mode_;				// controls TV or DVD
public:
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Remote(int m = TV) : mode_(m) {}
	bool VolUp(Tv &t);		// prototype only
	bool VolDown(Tv &t);
	void OnOff(Tv &t);
	void ChanUp(Tv &t);
	void ChanDown(Tv &t);
	void SetMode(Tv &t);
	void SetInput(Tv &t);
	void SetChan(Tv &t, int c);
};

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
	friend void Remote::SetChan(Tv &t, int c);
	enum State { Off, On };
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

// Remote methodsa as inline functions
inline bool Remote::VolUp(Tv &t) { return t.VolUp(); }
inline bool Remote::VolDown(Tv &t) { return t.VolDown(); }
inline void Remote::OnOff(Tv &t) { t.OnOff(); }
inline void Remote::ChanUp(Tv &t) { t.ChanUp(); }
inline void Remote::ChanDown(Tv &t) { t.ChanDown(); }
inline void Remote::SetChan(Tv &t, int c) { t.channel_ = c; }
inline void Remote::SetMode(Tv &t) { t.SetMode(); }
inline void Remote::SetInput(Tv &t) { t.SetInput(); }

#endif