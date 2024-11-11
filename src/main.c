#include "mainmenu.h"
#include <raylib.h>
#include <stdio.h>

static void init(void) {
    InitWindow(800, 450, "gimbalin");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(144);
    BBMainmenu *mainmenu = BBMainmenu_create();
    BBScene_swap(BB_SCENE(mainmenu));
}

static void update(void) {
    //
}

static void draw(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BBScene_draw(BBScene_current());
    EndDrawing();
}

int main(int argc, char **argv) {
    init();

    while(!WindowShouldClose()) {
        update();
        draw();
    }


    return 0;
}
