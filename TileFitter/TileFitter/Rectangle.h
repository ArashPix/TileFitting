#pragma once

#include <vector>
#include <cassert>
#include <cstdlib>


namespace tf {

	struct RectangleDimensiones
	{
		int width;
		int height;
	};


	class Rectangle
	{
	public:
		Rectangle();
		~Rectangle();

		int x;
		int y;
		int width;
		int height;

		int CompareRectShortSide(const Rectangle &a, const Rectangle &b);
		int NodeSortCmp(const Rectangle &a, const Rectangle &b);
		bool IsContainedIn(const Rectangle &a, const Rectangle &b);

		class DisjointRectCollection
		{
		public:
			std::vector<Rectangle> rects;

			bool Add(const Rectangle &r)
			{
				// Degenerate rectangles are ignored.
				if (r.width == 0 || r.height == 0)
					return true;

				if (!Disjoint(r))
					return false;
				rects.push_back(r);
				return true;
			}

			void Clear()
			{
				rects.clear();
			}

			bool Disjoint(const Rectangle &r) const
			{
				// Degenerate rectangles are ignored.
				if (r.width == 0 || r.height == 0)
					return true;

				for (size_t i = 0; i < rects.size(); ++i)
					if (!Disjoint(rects[i], r))
						return false;
				return true;
			}

			static bool Disjoint(const Rectangle &a, const Rectangle &b)
			{
				if (a.x + a.width <= b.x ||
					b.x + b.width <= a.x ||
					a.y + a.height <= b.y ||
					b.y + b.height <= a.y)
					return true;
				return false;
			}
		};

	};
}


