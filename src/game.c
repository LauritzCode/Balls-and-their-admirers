#include "game.h"

const Color COLORS[] = {
    // COOL SPACE BLUES
    (Color){90, 140, 255, 255},  // soft bright blue
    (Color){70, 110, 210, 255},  // deep sky blue
    (Color){50, 85, 160, 255},   // muted space blue
    (Color){30, 60, 120, 255},   // navy-tinted blue
    (Color){110, 180, 255, 255}, // pastel blue highlight

    // PURPLES & VIOLETS
    (Color){150, 120, 255, 255}, // gentle violet
    (Color){120, 90, 210, 255},  // soft deep violet
    (Color){100, 70, 180, 255},  // nebula purple
    (Color){170, 140, 255, 255}, // pastel purple
    (Color){80, 60, 140, 255},   // dark space purple

    // MAGENTA / COSMIC PINK
    (Color){210, 130, 255, 255}, // pastel magenta
    (Color){190, 100, 200, 255}, // muted magenta
    (Color){160, 70, 170, 255},  // deep cosmic magenta
    (Color){230, 160, 255, 255}, // bright nebula pink (still muted)

    // TEALS / CYANS
    (Color){80, 200, 220, 255},  // cyan-ish but soft
    (Color){60, 160, 175, 255},  // ocean teal
    (Color){40, 120, 130, 255},  // deep teal (good contrast)
    (Color){100, 220, 235, 255}, // pastel cyan

    // SOFT ORANGES (star accents)
    (Color){255, 150, 80, 255}, // warm star orange
    (Color){220, 120, 70, 255}, // muted orange/red
    (Color){200, 100, 60, 255}, // dark orange

    // REDS (subtle, not neon)
    (Color){180, 60, 70, 255},  // cosmic muted red
    (Color){150, 40, 50, 255},  // deep red
    (Color){210, 90, 100, 255}, // pastel red/pink mix

    // DUSTY SPACE TONES
    (Color){120, 120, 160, 255}, // dusty twilight purple
    (Color){100, 100, 130, 255}, // muted space grey-purple
    (Color){80, 80, 110, 255},   // dark desaturated indigo
};

const int COLORS_COUNT = sizeof(COLORS) / sizeof(COLORS[0]);

static Texture2D bg;

void game_init(void) {
  //
  bg = LoadTexture("resources/background.jpg");
}

void game_update(void) {}
void game_draw(void) {
  Rectangle src = {0, 0, (float)bg.width, (float)bg.height};
  Rectangle dest = {0, 0, (float)WIDTH, (float)HEIGHT};
  Vector2 org = {0, 0};
  DrawTexturePro(bg, src, dest, org, 0.0f, WHITE);
}
