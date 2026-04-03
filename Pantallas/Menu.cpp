#include "raylib.h"
#include "Menu.h"
#include "../Juegos/Ahorcados.h"

enum Pantalla
{
    MENU,
    AHORCADO
};

Pantalla pantallaActual = MENU;

void pantallaMenu()
{
    while (!WindowShouldClose())
    {
        if (pantallaActual == MENU)
        {
            if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1))
            {
                pantallaActual = AHORCADO;
            }
        }

        BeginDrawing();
        ClearBackground(DARKBLUE);

        if (pantallaActual == MENU)
        {
            DrawText("Bienvenido al Arcade", 220, 200, 40, YELLOW);
            DrawText("Presiona 1 para jugar Ahorcado", 200, 300, 25, WHITE);
        }

        if (pantallaActual == AHORCADO)
        {
            iniciarAhorcados();
        }

        EndDrawing();
    }
}