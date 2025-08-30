#include "map.h"
#include "movement.h"
#include "math.h"

int main(void)
{
	struct Map map;
	struct PlayerInfo Player;

	InitMap(&map);
	Player.playerPos = InitPlayerPosition(&map);
	Player.size = 0;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		Draw(&map);
		HandleMovement(&map, &Player);
	}

	CloseWindow();

	return 0;
}