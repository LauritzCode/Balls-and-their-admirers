#include "../../raylib//include/raylib.h"

int main(void) {
  InitWindow(1800, 900, "Raylib Test");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello", 900, 450, 20, BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
