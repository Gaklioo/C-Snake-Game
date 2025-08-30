#pragma once

struct boxDimensions
{
	int x;
	int y;
	int w;
	int h;
};

_Bool isTouching(struct boxDimensions a, struct boxDimensions b)
{
	int aMinX = (a.x - (a.w / 2));
	int aMaxX = (a.x + (a.w / 2));
	int aMinY = (a.y - (a.h / 2));
	int aMaxY = (a.y + (a.h / 2));

	int bMinX = (b.x - (b.w / 2));
	int bMaxX = (b.x + (b.w / 2));
	int bMinY = (b.y - (b.h / 2));
	int bMaxY = (b.y + (b.h / 2));

	return(
		aMinX <= bMaxX &&
		aMaxX >= bMinX &&
		aMinY <= bMaxY &&
		aMaxY >= bMinY
		);
}