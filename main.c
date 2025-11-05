#include "../../raylib//include/raylib.h"
#include "balls.h"
#include "defines.h"
#include "game.h"

int main(void) {
  InitWindow(WIDTH, HEIGHT, TITLE);
  SetTargetFPS(FPS);

  game_init();
  balls_init();

  while (!WindowShouldClose()) {

    game_update();
    balls_update();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    game_draw();
    balls_draw();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
