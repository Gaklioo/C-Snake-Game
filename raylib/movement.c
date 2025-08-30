#include "map.h"
#include "movement.h"

static void handleMapChange(struct Map* map, struct PlayerInfo* ply, Vector2 LastPos)
{
	if (ply->size == 0)
	{
		ply->playerTail = ply->playerPos;
		map->map[(int)LastPos.x][(int)LastPos.y] = GRASS;
		map->map[(int)ply->playerPos.x][(int)ply->playerPos.y] = PLAYER;
	}
	else
	{ 
		map->map[(int)ply->playerPos.x][(int)ply->playerPos.y] = PLAYER;
	}
}

void HandleMovement(struct Map* map, struct PlayerInfo* ply)
{
	if (!ply || !map)
	{
		return;
	}

	Vector2 LastPos = ply->playerPos;

	//No error checking yet, soon
	if (IsKeyPressed(KEY_S))
	{
		ply->playerPos.y++;
	}

	if (IsKeyPressed(KEY_W))
	{
		ply->playerPos.y--;
	}

	if (IsKeyPressed(KEY_A))
	{
		ply->playerPos.x--;
	}

	if (IsKeyPressed(KEY_D))
	{
		ply->playerPos.x++;
	}

	handleMapChange(map, ply, LastPos);
}