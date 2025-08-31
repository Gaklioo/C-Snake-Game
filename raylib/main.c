#include "map.h"
#include "movement.h"
#include "math.h"
#include "food.h"

static _Bool shouldReset = false;

int main(void)
{
	srand(time(NULL));
	struct Map map;
	struct PlayerInfo Player;

	InitMap(&map);
	InitMovement();
	Player.playerPos = InitPlayerPosition(&map);
	Player.size = 0;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test");
	SetTargetFPS(20);

	while (!WindowShouldClose())
	{
		if (ShouldGameRun())
		{
			if (shouldReset)
			{
				shouldReset = false;
				ResetMovement();

				InitMap(&map);
				InitMovement();
				Player.playerPos = InitPlayerPosition(&map);
				Player.size = 0;
			}

			Draw(&map);
			HandleMovement(&map, &Player);
			ShouldSpawnFood(&map);
		}
		else
		{
			shouldReset = true;
			DrawMenu();
		}
	}

	CloseWindow();

	return 0;
}