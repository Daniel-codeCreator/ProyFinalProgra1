#include "raylib.h"
#include "Menu.h"
#include "../Juegos/Ahorcados.h"
#include "../Juegos/Serpiente.h"
#include "../Juegos/TotiToto.h"
#include "../Juegos/RompeBloques.h"

enum Pantalla
{
    MENU,
    AHORCADO,
    Serpiente,
    TotiToto,
    RompeBloque
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
            if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2))
            {
                pantallaActual = Serpiente;
            }
            if (IsKeyPressed(KEY_THREE) || IsKeyPressed(KEY_KP_3))
            {
                pantallaActual = TotiToto;
            }
            if (IsKeyPressed(KEY_FOUR) || IsKeyPressed(KEY_KP_4))
            {
                pantallaActual = RompeBloque;
            }
        }

        BeginDrawing();
        ClearBackground(DARKBLUE);

        if (pantallaActual == MENU)
        {
            DrawText("Bienvenido al Arcade", 220, 50, 40, YELLOW);
            DrawText("Presiona 1 para jugar Ahorcado", 200, 100, 25, WHITE);
            DrawText("Presiona 2 para jugar Serpiente", 200,200,25, WHITE);
            DrawText("Presiona 3 para jugar Toti", 200,300,25, WHITE);
            DrawText("Presiona 4 para jugar Rompe Bloques", 200,400,25, WHITE);

        }

        if (pantallaActual == AHORCADO)
        {
            iniciarAhorcados();
        }
        if (pantallaActual == Serpiente)
        {
            iniciarSerpiente();
        }
        if (pantallaActual == TotiToto)
        {
            iniciarTotiToto();
        }
        if (pantallaActual == RompeBloque)
        {
            iniciarRompeBloque();
        }

        EndDrawing();
    }
}