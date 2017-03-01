#pragma once
// coordin.h -- structure templates and function prototypes
// structure templates
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
	double distance;	// distance from origin
	double angle;		// direction from prigin
};

struct rect
{
	double x;		// horizontal distance from prigin
	double y;		// vertical distance from origin
};

// prototypes
polar rect_to_polar(rect);
void show_polar(polar);

#endif