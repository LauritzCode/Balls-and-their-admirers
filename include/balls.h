#pragma once

#include "../../../raylib//include/raylib.h"

typedef struct Ball {
  float posx, posy;
  float velx, vely;
  float radius;
  Color color;
  struct Ball *follows;
} Ball;

void balls_init(void);
void balls_update(void);
void balls_draw(void);