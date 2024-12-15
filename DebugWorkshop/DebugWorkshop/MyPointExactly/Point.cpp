#include "Point.h"
#include <iostream>

Point::Point()
{
	_coord = new int[2];
	_coord[0] = _coord[1] = 0;
}

Point::Point(int x, int y)
{
	_coord = new int[2];
	_coord[0] = x;
	_coord[1] = y;
}

Point::Point(const Point& other)
{
	delete _coord;
	*this = other;
}

Point::~Point()
{
	if (this->_coord != nullptr)
	{
		delete _coord;
	}
	this->_coord = nullptr;
}

Point& Point::operator=(const Point& other)
{
	int array[] = { other.getX(), other.getY() };
	int i = 0;
	delete _coord;
	this->_coord = new int[2];
	
	for (i = 0; i < 2; i++)
	{
		this->_coord[i] = array[i];
	}
	return *this;
}

int Point::getX() const 
{ 
	return _coord[0]; 
}

int Point::getY() const
{ 
	return _coord[1]; 
}


std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p._coord[0] << "," << p._coord[1] << ")";
	return os;
}
