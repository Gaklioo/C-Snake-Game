#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

#define ROWS 20
#define COLUMNS 20
#define nullptr NULL //i like the c++ version more than the C verison
#define GRASS 0
#define WALL 1
#define PLAYER 2

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

struct Map
{
	int map[ROWS][COLUMNS];
	int rows;
	int columns;
	int height;
	int width;
};

void InitMap(struct Map* m);
Vector2 InitPlayerPosition(struct Map* m);
void Draw(struct Map* m);