#include "map.h"
#include "movement.h"

int GetCellWidth(int columns)
{
	return (SCREEN_WIDTH / columns);
}

int GetCellHeight(int rows)
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

	int randomX = (rand() % rows);
	int randomY = (rand() % columns);

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

void ResetPlayer(struct Map* m, struct PlayerInfo* ply)
{
	Vector2 newPlyPos = InitPlayerPosition(m);

	ply->playerPos = newPlyPos;
}

void Draw(struct Map* m)
{
	int cellWidth = GetCellWidth(m->columns);
	int cellHeight = GetCellHeight(m->rows);

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
			else if (m->map[i][j] == FOOD)
			{
				DrawRectangle((i * cellWidth), (j * cellHeight), cellWidth, cellHeight, RED);
			}
			else // WALL
			{
				DrawRectangle((i * cellWidth), (j * cellHeight), cellWidth, cellHeight, GREEN);
			}
		}
	}

	EndDrawing();
}