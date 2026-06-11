#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "raylib.h"

int main() {
    InitWindow(800, 450, "raylib + raygui example");
    SetTargetFPS(60);

    bool showWindow = true;
    char name[64] = "World";

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (GuiWindowBox((Rectangle) { 100, 100, 300, 200 }, "Hello")) {
            showWindow = false;
        }

        GuiLabel((Rectangle) { 120, 150, 100, 20 }, "Enter name:");
        GuiTextBox((Rectangle) { 220, 150, 140, 20 }, name, 64, true);
        GuiButton((Rectangle) { 200, 190, 100, 30 }, "OK");

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
