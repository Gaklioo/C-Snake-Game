#pragma once

struct PlayerInfo
{
	Vector2 playerPos;
	Vector2 playerTail;
	int size;
};

void HandleMovement(struct Map* map, struct PlayerInfo* ply);
