// vector.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace vector
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
		//  RECT for rectangular, POL for Polar modes
	private:
		double x_;		// horizontal value
		double y_;		// vertical value
		double mag_;		// length of vector
		double ang_;		// direction of vector in degrees
		Mode mode_;		// RECT or POL
		// private methods for setting values
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void Reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double x_val() const { return x_; }		// report x value
		double y_val() const { return y_; }		// report y value
		double mag_val() const { return mag_; }	// report magnitude
		double ang_val() const { return ang_; }	// report angle
		void PolarMode();		// set mode to POL
		void RectMode();		// set mode to RECT
		// operator overloading
		Vector operator+(const Vector &b) const;
		Vector operator-(const Vector &b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// friend
		friend Vector operator*(double n, const Vector &a);
		friend std::ostream & operator<<(std::ostream &os, const Vector &v);
	};
}	// end namespace vector
#endif