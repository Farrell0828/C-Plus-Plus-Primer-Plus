// dma.cpp -- dma class methods
#include <cstring>
#include "dma.h"

// BaseDMA methods
BaseDMA::BaseDMA(const char *l, int r)
{
	label_ = new char[std::strlen(l) + 1];
	std::strcpy(label_, l);
	rating_ = r;
}

BaseDMA::BaseDMA(const BaseDMA &rs)
{
	label_ = new char[std::strlen(rs.label_) + 1];
	std::strcpy(label_, rs.label_);
	rating_ = rs.rating_;
}

BaseDMA::~BaseDMA()
{
	delete[] label_;
}

BaseDMA & BaseDMA::operator=(const BaseDMA &rs)
{
	if (this == &rs)
		return *this;
	delete[] label_;
	label_ = new char[std::strlen(rs.label_) + 1];
	std::strcpy(label_, rs.label_);
	rating_ = rs.rating_;
	return *this;
}

std::ostream & operator<<(std::ostream &os, const BaseDMA &rs)
{
	os << "Label: " << rs.label_ << std::endl;
	os << "Rating: " << rs.rating_ << std::endl;
	return os;
}

// LacksDMA methods
LacksDMA::LacksDMA(const char *c, const char *l, int r)
	: BaseDMA(l, r)
{
	std::strncpy(color_, c, COL_LEN - 1);
	color_[COL_LEN - 1] = '\0';
}

LacksDMA::LacksDMA(const char *c, const BaseDMA &rs)
	: BaseDMA(rs)
{
	std::strncpy(color_, c, COL_LEN - 1);
	color_[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream &os, const LacksDMA &ls)
{
	os << (BaseDMA &)ls;
	os << "Color: " << ls.color_ << std::endl;
	return os;
}

// HasDMA methods
HasDMA::HasDMA(const char *s, const char *l, int r)
	: BaseDMA(l, r)
{
	style_ = new char[strlen(s) + 1];
	strcpy(style_, s);
}

HasDMA::HasDMA(const char *s, const BaseDMA &rs)
	: BaseDMA(rs)
{
	style_ = new char[strlen(s) + 1];
	strcpy(style_, s);
}

HasDMA::HasDMA(const HasDMA &hs)
	: BaseDMA(hs)		// invoke base class copy constructor
{
	style_ = new char[std::strlen(hs.style_) + 1];
	strcpy(style_, hs.style_);
}

HasDMA::~HasDMA()
{
	delete[] style_;
}

HasDMA & HasDMA::operator=(const HasDMA &hs)
{
	if (this == &hs)
		return *this;
	BaseDMA::operator=(hs);	// copy base portion
	delete[] style_;		// prepare for new style
	style_ = new char[std::strlen(hs.style_) + 1];
	strcpy(style_, hs.style_);
	return *this;
}

std::ostream & operator<<(std::ostream &os, const HasDMA &hs)
{
	os << (BaseDMA &)hs;
	os << "Style: " << hs.style_ << std::endl;
	return os;
}