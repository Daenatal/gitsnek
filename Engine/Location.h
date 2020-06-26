#pragma once

class Location //since it is starting to have behaviors we are changing from a struct to a class
{
public:
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	//there is another data type specifier called a struct, what is the difference?
	bool operator==(const Location& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y; // we are not making these private because, for this simple data time, idea of lumping 2 values together, it is necessary to encapsulate
};