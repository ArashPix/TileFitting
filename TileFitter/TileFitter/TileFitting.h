#pragma once
#include "Rectangle.h"

namespace tf {

	class TileFitting
	{
	public:
		TileFitting();
		TileFitting(int width, int height);
		Rectangle Insert(int width, int height);
		float Occupancy() const;
		~TileFitting();

	private:
		int binWidth;
		int binHeight;

		bool binAllowFlip;

		std::vector<Rectangle> usedRectangles;
		std::vector<Rectangle> freeRectangles;

		Rectangle ScoreRectangle(int width, int height, int &score1, int &score2) const;

		void PlaceRect(const Rectangle &node);

		int ContactPointScoreNode(int x, int y, int width, int height) const;

		Rectangle FindPositionForNewNodeBestShortSideFit(int width, int height, int &bestShortSideFit, int &bestLongSideFit) const;

		bool SplitFreeNode(Rectangle freeNode, const Rectangle &usedNode);

		void PruneFreeList();
	};
}


