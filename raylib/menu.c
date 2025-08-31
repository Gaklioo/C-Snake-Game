#include "menu.h"
#include "map.h"
#include "movement.h"

static int fontSize = 24;
static const char* welcomeMsg = "Welcome to my snake game";

void DrawMenu()
{
	int textWidth = MeasureText(welcomeMsg, fontSize);
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText(welcomeMsg, (SCREEN_WIDTH / 2) - (textWidth / 2), SCREEN_HEIGHT * 0.05, 24, BLACK);

	Rectangle start = { SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.3, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.3 };
	DrawRectangleRec(start, RED);

	const char* startMessage = "Start";
	int startWidth = MeasureText(startMessage, fontSize);
	int startHeight = fontSize;
	int posX = start.x + (start.width - startWidth) / 2;
	int posY = start.y + (start.height - startHeight) / 2;
	DrawText(startMessage, posX, posY, fontSize, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), start) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		StartGame();
	}

	EndDrawing();
}