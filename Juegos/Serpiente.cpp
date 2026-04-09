#include "Serpiente.h"
#include "raylib.h"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct segmento
{
    int x;
    int y;
};

void iniciarSerpiente()
{
    const int intAnchoPantalla = 800;
    const int intAlturaPantalla = 600;
    const int intTamañoCelda = 20;

    int intPuntajeGanadores = 50;

    //para que el mapa no aparezca sonbre el titulo
    const int intAlturaHUD = 80;

    int intAnchoMapa = intAnchoPantalla / intTamañoCelda;
    int intAltoMapa = (intAlturaPantalla - intAlturaHUD) / intTamañoCelda;

    InitWindow(intAnchoPantalla, intAlturaPantalla, "Juego Serpiente");

    vector<segmento> serpiente;

    serpiente.push_back({10, 10});
    serpiente.push_back({9, 10});
    serpiente.push_back({8, 10});

    int intDireccionX = 1;
    int intDireccionY = 0;

    segmento comida;

    srand(time(NULL));

    // generar comida SOLO en el mapa
    comida.x = rand() % intAnchoMapa;
    comida.y = rand() % intAltoMapa;

    float temporizadorMovimiento = 0;
    float velocidad = 0.15f;

    bool juegoTerminado = false;

    int puntaje = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (!juegoTerminado)
        {
            if (IsKeyPressed(KEY_UP) && intDireccionY != 1)
            {
                intDireccionX = 0;
                intDireccionY = -1;
            }

            if (IsKeyPressed(KEY_DOWN) && intDireccionY != -1)
            {
                intDireccionX = 0;
                intDireccionY = 1;
            }

            if (IsKeyPressed(KEY_LEFT) && intDireccionX != 1)
            {
                intDireccionX = -1;
                intDireccionY = 0;
            }

            if (IsKeyPressed(KEY_RIGHT) && intDireccionX != -1)
            {
                intDireccionX = 1;
                intDireccionY = 0;
            }

            temporizadorMovimiento += GetFrameTime();

            if (temporizadorMovimiento >= velocidad)
            {
                temporizadorMovimiento = 0;

                segmento nuevaCabeza = serpiente[0];

                nuevaCabeza.x += intDireccionX;
                nuevaCabeza.y += intDireccionY;

                serpiente.insert(serpiente.begin(), nuevaCabeza);

                if (nuevaCabeza.x == comida.x && nuevaCabeza.y == comida.y)
                {
                    puntaje++;

                    if (puntaje % 10 == 0 && velocidad > 0.05f)
                    {
                        velocidad -= 0.02f;
                    }

                    bool posicionValida = false;

                    while (!posicionValida)
                    {
                        posicionValida = true;

                        comida.x = rand() % intAnchoMapa;
                        comida.y = rand() % intAltoMapa;

                        for (segmento s : serpiente)
                        {
                            if (s.x == comida.x && s.y == comida.y)
                            {
                                posicionValida = false;
                            }
                        }
                    }
                }
                else
                {
                    serpiente.pop_back();
                }

                // choque con bordes (mapa real)
                if (nuevaCabeza.x < 0 || nuevaCabeza.y < 0
                    || nuevaCabeza.x >= intAnchoMapa
                    || nuevaCabeza.y >= intAltoMapa)
                {
                    juegoTerminado = true;
                }

                // choque con cuerpo
                for (int i = 1; i < serpiente.size(); i++)
                {
                    if (serpiente[i].x == nuevaCabeza.x &&
                        serpiente[i].y == nuevaCabeza.y)
                    {
                        juegoTerminado = true;
                    }
                }

                if (puntaje >= intPuntajeGanadores)
                {
                    juegoTerminado = true;
                }
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // dibujar cuadricula SOLO en el mapa
        for (int x = 0; x < intAnchoMapa; x++)
        {
            for (int y = 0; y < intAltoMapa; y++)
            {
                DrawRectangleLines(
                    x * intTamañoCelda,
                    y * intTamañoCelda + intAlturaHUD,
                    intTamañoCelda,
                    intTamañoCelda,
                    DARKGRAY
                );
            }
        }

        // dibujar serpiente
        for (segmento seg : serpiente)
        {
            DrawRectangle(
                seg.x * intTamañoCelda,
                seg.y * intTamañoCelda + intAlturaHUD,
                intTamañoCelda,
                intTamañoCelda,
                GREEN
            );
        }

        // dibujar comida
        DrawRectangle(
            comida.x * intTamañoCelda,
            comida.y * intTamañoCelda + intAlturaHUD,
            intTamañoCelda,
            intTamañoCelda,
            RED
        );

        DrawText("Juego Serpiente", 300, 20, 30, YELLOW);

        DrawText(TextFormat("Puntaje: %i", puntaje), 20, 20, 20, WHITE);

        if (juegoTerminado)
        {
            if (puntaje >= intPuntajeGanadores)
            {
                DrawText("GANASTE!", 350, 520, 30, GREEN);
            }
            else
            {
                DrawText("GAME OVER", 330, 520, 30, RED);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}