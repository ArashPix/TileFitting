#include "TileFitting.h"


namespace tf {

	TileFitting::TileFitting()
	{
	}

	TileFitting::TileFitting(int width, int height)
	{
	}

	Rectangle TileFitting::Insert(int width, int height)
	{
		Rectangle newNode;
		// Unused in this function. We don't need to know the score after finding the position.
		int score1 = std::numeric_limits<int>::max();
		int score2 = std::numeric_limits<int>::max();

		newNode = FindPositionForNewNodeBestShortSideFit(width, height, score1, score2); break;

		if (newNode.height == 0)
			return newNode;

		size_t numRectanglesToProcess = freeRectangles.size();
		for (size_t i = 0; i < numRectanglesToProcess; ++i)
		{
			if (SplitFreeNode(freeRectangles[i], newNode))
			{
				freeRectangles.erase(freeRectangles.begin() + i);
				--i;
				--numRectanglesToProcess;
			}
		}

		PruneFreeList();

		usedRectangles.push_back(newNode);
		return newNode;
	}

	float TileFitting::Occupancy() const
	{
		return 0.0f;
	}


	TileFitting::~TileFitting()
	{
	}

	Rectangle TileFitting::ScoreRectangle(int width, int height, int & score1, int & score2) const
	{
		return Rectangle();
	}

	void TileFitting::PlaceRect(const Rectangle & node)
	{
	}

	int TileFitting::ContactPointScoreNode(int x, int y, int width, int height) const
	{
		return 0;
	}

	Rectangle TileFitting::FindPositionForNewNodeBestShortSideFit(int width, int height, int & bestShortSideFit, int & bestLongSideFit) const
	{
		return Rectangle();
	}

	bool TileFitting::SplitFreeNode(Rectangle freeNode, const Rectangle & usedNode)
	{
		return false;
	}

	void TileFitting::PruneFreeList()
	{
	}
}

