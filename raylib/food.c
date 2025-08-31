#include "food.h"
#include "map.h"

void SpawnFood(struct Map* map)
{
	int rows = map->rows;
	int columns = map->columns;

	int randX = (rand() % rows);
	int randY = (rand() % columns);

	while (map->map[randX][randY] != GRASS)
	{
		randX = (rand() % rows);
		randY = (rand() % columns);
	}

	map->map[randX][randY] = FOOD;
}

void ShouldSpawnFood(struct Map* map)
{
	double curTime = GetTime();
	static double endTime = 0.0f;

	if (curTime > endTime)
	{
		SpawnFood(map);
		endTime = curTime + FOOD_DELAY;
	}
}