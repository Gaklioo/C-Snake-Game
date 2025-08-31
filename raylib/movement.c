#include "map.h"
#include "movement.h"

struct PlayerInfo* plyBody[ROWS * COLUMNS];
static int LastMovement = -1;

void InitMovement()
{
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		plyBody[i] = NULL;
	}
}

void ResetMovement()
{
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		if (plyBody[i])
		{
			plyBody[i] = NULL;
		}
	}

	LastMovement = -1;
}

static _Bool shouldGameRun = false;
_Bool ShouldGameRun()
{
	return shouldGameRun;
}

void StartGame()
{
	shouldGameRun = true;
}

static void AddFood(struct PlayerInfo* ply, struct Map* map)
{
	int newIndex = ply->size;

	plyBody[newIndex] = malloc(sizeof(struct PlayerInfo));
	if (!plyBody[newIndex])
	{
		return;
	}

	plyBody[newIndex]->playerPos = ply->playerTail;
	plyBody[newIndex]->playerTail = ply->playerTail;
}

static void HandleMapChange(struct Map* map, struct PlayerInfo* ply, Vector2 LastPos)
{
	int plyX = (int)ply->playerPos.x;
	int plyY = (int)ply->playerPos.y;

	if (map->map[plyX][plyY] == FOOD)
	{
		ply->size++;
		AddFood(ply, map);
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (map->map[i][j] == PLAYER)
			{
				map->map[i][j] = GRASS;
			}
		}
	}

	map->map[plyX][plyY] = PLAYER;

	for (int i = 1; i <= ply->size; i++)
	{
		if (plyBody[i])
		{
			int x = (int)plyBody[i]->playerPos.x;
			int y = (int)plyBody[i]->playerPos.y;

			map->map[x][y] = PLAYER;
		}
	}
}

static void HandleBodyMovement(struct PlayerInfo* ply)
{
	if (ply->size == 0)
	{
		return;
	}

	for (int i = 1; i <= ply->size; i++)
	{
		if (plyBody[i] && plyBody[i - 1])
		{
			plyBody[i]->playerTail = plyBody[i]->playerPos;
			plyBody[i]->playerPos = plyBody[i - 1]->playerTail;
		}
	}
}

static void DoMovement(struct Map* map, struct PlayerInfo* ply)
{
	Vector2 lastPos = ply->playerPos;
	int plyX = (int)ply->playerPos.x;
	int plyY = (int)ply->playerPos.y;

	switch (LastMovement)
	{
	case UP:
		if (map->map[plyX][plyY - 1] == WALL)
		{
			shouldGameRun = false;
		}

		if (map->map[plyX][plyY - 1] == PLAYER)
		{
			break;
		}
		ply->playerPos.y--;
		break;
	case DOWN:
		if (map->map[plyX][plyY + 1] == WALL)
		{
			shouldGameRun = false;
		}

		if (map->map[plyX][plyY + 1] == PLAYER)
		{
			break;
		}
		ply->playerPos.y++;
		break;
	case LEFT:
		if (map->map[plyX - 1][plyY] == WALL)
		{
			shouldGameRun = false;
		}

		if (map->map[plyX - 1][plyY] == PLAYER)
		{
			break;
		}
		ply->playerPos.x--;
		break;
	case RIGHT:
		if (map->map[plyX + 1][plyY] == WALL)
		{
			shouldGameRun = false;
		}
		if (map->map[plyX + 1][plyY] == PLAYER)
		{
			break;
		}
		ply->playerPos.x++;
		break;
	default:
		break;
	}
	
	ply->playerTail = lastPos;
	if (LastMovement != -1)
	{
		HandleBodyMovement(ply);
	}
}

void HandleMovement(struct Map* map, struct PlayerInfo* ply)
{
	if (!ply || !map)
	{
		return;
	}

	plyBody[0] = ply;

	if (IsKeyPressed(KEY_S))
	{
		LastMovement = DOWN;
	}
	else if (IsKeyPressed(KEY_W))
	{
		LastMovement = UP;
	}
	else if (IsKeyPressed(KEY_A))
	{
		LastMovement = LEFT;
	}
	else if (IsKeyPressed(KEY_D))
	{
		LastMovement = RIGHT;
	}

	Vector2 lastPos = ply->playerPos;
	DoMovement(map, ply);
	HandleMapChange(map, ply, lastPos);
}