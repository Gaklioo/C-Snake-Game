#pragma once

#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3

struct PlayerInfo
{
	Vector2 playerPos;
	Vector2 playerTail;
	int size;
};

void InitMovement();
void HandleMovement(struct Map* map, struct PlayerInfo* ply);
_Bool ShouldGameRun();
void StartGame();
void ResetMovement();
