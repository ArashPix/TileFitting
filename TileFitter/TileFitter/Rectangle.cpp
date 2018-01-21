#include "Rectangle.h"

namespace tf {
	Rectangle::Rectangle()
	{
	}


	Rectangle::~Rectangle()
	{
	}

	bool Rectangle::IsContainedIn(const Rectangle &a, const Rectangle &b)
	{
		return a.x >= b.x && a.y >= b.y
			&& a.x + a.width <= b.x + b.width
			&& a.y + a.height <= b.y + b.height;
	}
}
