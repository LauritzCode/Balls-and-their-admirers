#include "balls.h"
#include "defines.h"
#include "game.h"
#include <stddef.h>
#include <stdlib.h>

static Ball balls[BALL_COUNT];
static float global_time = 0.0f;

void balls_init(void) {
  for (size_t i = 0; i < BALL_COUNT; i++) {
    balls[i].posx = GetRandomValue(0, WIDTH - 50);
    balls[i].posy = GetRandomValue(0, HEIGHT - 50);
    balls[i].radius = GetRandomValue(RADIUS_MIN, RADIUS_MAX);
    size_t color_index = GetRandomValue(0, COLORS_COUNT - 1);
    balls[i].color = COLORS[color_index];
    balls[i].velx = GetRandomValue(-20, 20) / 10.0f;
    balls[i].vely = GetRandomValue(-20, 20) / 10.0f;

    size_t leader;

    do {
      leader = GetRandomValue(0, BALL_COUNT - 1);
    } while (leader == i);

    balls[i].follows = &balls[leader];
  }
}
void balls_update(void) {
  float dt = GetFrameTime();
  global_time += dt * 0.2f; // controls fade speed
  if (global_time > 1.0f)
    global_time = 1.0f;

  const float sep = 12.0f;  // min separation in px
  const float krep = 20.0f; // repulsion strengh

  for (size_t i = 0; i < BALL_COUNT; i++) {
    balls[i].posx += balls[i].velx;
    balls[i].posy += balls[i].vely;

    float tx = balls[i].follows->posx - balls[i].posx;
    float ty = balls[i].follows->posy - balls[i].posy;

    float follow_strengh = 0.005f;
    balls[i].velx += tx * follow_strengh * dt;
    balls[i].vely += ty * follow_strengh * dt;

    float damping = 0.988f;

    balls[i].velx *= damping;
    balls[i].vely *= damping;

    if (balls[i].posx < balls[i].radius) {
      balls[i].posx = balls[i].radius;
      balls[i].velx = -balls[i].velx;
    } else if (balls[i].posx > WIDTH - balls[i].radius) {
      balls[i].posx = WIDTH - balls[i].radius;
      balls[i].velx = -balls[i].velx;
    }

    if (balls[i].posy < balls[i].radius) {
      balls[i].posy = balls[i].radius;
      balls[i].vely = -balls[i].vely;
    } else if (balls[i].posy > HEIGHT - balls[i].radius) {
      balls[i].posy = HEIGHT - balls[i].radius;
      balls[i].vely = -balls[i].vely;
    }
  }
}

static void draw_ball_with_glow(const Ball *b) {

  for (int k = 3; k >= 1; --k) {
    float scale = 1.0f + 0.5f * k;
    float alpha = 0.02f * k;
    DrawCircle((int)b->posx, (int)b->posy, b->radius * scale,
               Fade(b->color, alpha));
  }
  // core
  DrawCircle((int)b->posx, (int)b->posy, b->radius, b->color);
}

void balls_draw(void) {

  for (size_t i = 0; i < BALL_COUNT; i++) {
    draw_ball_with_glow(&balls[i]);
  }
}