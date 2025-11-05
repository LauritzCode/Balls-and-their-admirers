#pragma once
#include "../../../raylib//include/raylib.h"
#include "defines.h"

extern const Color COLORS[];
extern const int COLORS_COUNT;

void game_init(void);
void game_update(void);
void game_draw(void);