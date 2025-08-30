#include "map.h"

int getCellWidth(int columns)
{
	return (SCREEN_WIDTH / columns);
}

int getCellHeight(int rows)
{
	return (SCREEN_HEIGHT / rows);
}

void InitMap(struct Map* m)
{
	m->rows = ROWS;
	m->columns = COLUMNS;

	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->columns; j++)
		{
			if (i == 0 || i == (m->rows - 1) || j == 0 || j == (m->columns - 1))
			{
				m->map[i][j] = WALL;
			}
			else
			{
				m->map[i][j] = GRASS;
			}
		}
	}


}

Vector2 InitPlayerPosition(struct Map* m)
{
	int rows = m->rows;
	int columns = m->columns;
	srand(time(NULL));

	int randomX = (rand() % rows) + 1;
	int randomY = (rand() % columns) + 1;

	if (randomX == 0)
	{
		randomX++;
	}
	else if (randomX == (m->rows - 1))
	{
		randomX--;
	}

	if (randomY == 0)
	{
		randomY++;
	}

	else if (randomY == (m->columns - 1))
	{
		randomY--;
	}

	Vector2 pos;
	pos.x = randomX;
	pos.y = randomY;

	m->map[randomX][randomY] = PLAYER;

	return pos;
}

void Draw(struct Map* m)
{
	int cellWidth = getCellWidth(m->columns);
	int cellHeight = getCellHeight(m->rows);

	BeginDrawing();

	ClearBackground(RAYWHITE);

	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->columns; j++)
		{
			if (m->map[i][j] == GRASS)
			{
				DrawRectangle((i * cellWidth), (j * cellHeight), cellWidth, cellHeight, BROWN);
			}
			else if (m->map[i][j] == PLAYER)
			{
				DrawRectangle((i * cellWidth), (j * cellHeight), cellWidth, cellHeight, ORANGE);
			}
			else
			{
				DrawRectangle((i * cellWidth), (j * cellHeight), cellWidth, cellHeight, GREEN);
			}
		}
	}

	EndDrawing();
}