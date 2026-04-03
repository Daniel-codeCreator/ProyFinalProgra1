#include "Ahorcados.h"
#include "raylib.h"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace  std;

struct Palabra
{
    string strTexto;
};

void dibujarAhorcados(int intErrores)
{
    DrawLine(200, 500, 350, 500, BLACK);
    DrawLine(275, 500, 275, 200, BLACK);
    DrawLine(275, 200, 400, 200, BLACK);
    DrawLine(400, 200, 400, 230, BLACK);

    if (intErrores >= 1)
        DrawCircle(400, 260, 30, BLACK);
    if (intErrores >= 2 )
        DrawLine(400, 290, 400, 360, BLACK);
    if (intErrores >= 3 )
        DrawLine(400, 310, 360, 340, BLACK);
    if (intErrores >= 4 )
        DrawLine(400, 310, 440, 340, BLACK);
    if (intErrores >= 5 )
        DrawLine(400, 360, 360, 400, BLACK);
    if (intErrores >= 6 )
        DrawLine(400, 360, 440, 400, BLACK);
}


void iniciarAhorcados()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Ahorcados");

    srand(time(NULL));

    Palabra palabras[] = {
        {"PROGRAMACION"}, {"COMPUTADORA"}, {"ALGORITMO"},
        {"VARIABLE"}, {"PROCESADOR"}, {"DESARROLLO"},
        {"RAYLIB"}, {"MESSI"}
    };

    int totalPalabras = sizeof(palabras) / sizeof(palabras[0]);

    int intIndice = rand() % totalPalabras;

    string palabra = palabras[intIndice].strTexto;

    string progreso = "";

    for (int i = 0; i < palabra.length(); i++)
        progreso += "_";

    vector<char> letrasUsadas;

    int intErrores = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        int key = GetKeyPressed();

        if (key >= 65 && key <= 90)
        {
            char letra = (char)key;

            bool letraYAUsada = false;

            for (char l : letrasUsadas)
            {
                if (l == letra)
                {
                    letraYAUsada = true;
                    break;
                }
            }

            if (!letraYAUsada)
            {
                letrasUsadas.push_back(letra);

                bool aciertos = false;

                for (int i = 0; i < palabra.length(); i++)
                {
                    if (palabra[i] == letra)
                    {
                        progreso[i] = letra;
                        aciertos = true;
                    }
                }
                if (!aciertos)
                    intErrores++;
            }
        }
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("JUEGO DE AHORCADO", 300, 30, 30, BLACK);
        DrawText("Adivina la Palabra", 350, 100, 20, DARKGRAY);

        DrawText(progreso.c_str(), 380, 150, 40, DARKBLUE);
        DrawText(TextFormat("Errores: %i / 6", intErrores), 700, 40, 20, RED);

        dibujarAhorcados(intErrores);

        DrawText("Letras Usadas", 650, 120, 20, BLACK);

        int y = 150;

        for (char l : letrasUsadas)
        {
            DrawText(TextFormat("%c", l), 650, y, 20, DARKGRAY);
            y += 25;
        }

        if (progreso == palabra)
        {
            DrawText("Ganaste", 380,520,30, GREEN);
        }

        if (intErrores >= 6)
        {
            DrawText("Perdiste", 380, 520, 30, RED);
            DrawText(TextFormat("La palabra era: %s", palabra.c_str()), 330, 560, 20, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();
}