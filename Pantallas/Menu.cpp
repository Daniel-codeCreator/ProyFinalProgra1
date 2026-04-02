#include "raylib.h"
#include "Menu.h"

void pantallaMenu()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);

        DrawText("Bienvenido al Arcade", 220, 250, 40, YELLOW);

        EndDrawing();
    }
}