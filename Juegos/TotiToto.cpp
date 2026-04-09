#include "TotiToto.h"
#include "raylib.h"
#include "ctime"
#include <cstdlib>

char tablero [3][3];

char jugador;
char pc;

bool turnoJugador = true;

void reinciarTablero()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tablero[i][j] = ' ';
}

void movimientosPC()
{
    WaitTime(0.5);

    int fila, col;

    do
    {
        fila = rand() % 3;  // número entre 0 y 2
        col = rand() % 3;   // número entre 0 y 2
    }
    while (tablero[fila][col] != ' '); // repetir si está ocu   pado

    tablero[fila][col] = pc;
}

void dibujarTablero()
{
    int iniciarX = 250;
    int iniciarY = 150;

    int size = 100;

    for (int i = 1; i < 3; i++)
    {
        DrawLine(iniciarX, iniciarY + i*size, iniciarX+300, iniciarY + i*size, BLACK);
        DrawLine(iniciarX + i*size, iniciarY, iniciarX + i*size, iniciarY+300, BLACK);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char chr = tablero[i][j];

            if (chr != ' ')
            {
                DrawText(TextFormat("%c", chr),
                iniciarX + j*size + 40,
                iniciarY + i*size + 30,
                40, BLUE
                );
            }
        }
    }
}

void clickJugador()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        int iniciarX = 250;
        int iniciarY = 150;
        int size = 100;

        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        int cola = (mouseX - iniciarX) / size;
        int fila = (mouseY - iniciarY) / size;

        if (fila >= 0 && fila < 3 && cola >= 0 && cola < 3)
        {
            if (tablero[fila][cola] == ' ')
            {
                tablero[fila][cola] = jugador;
                turnoJugador = false;
            }
        }
    }
}

char verificarGanador()
{
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1]
            && tablero[i][1] == tablero[i][2])
            return tablero[i][0];
    }

    for (int j = 0; j < 3; j++)
    {
        if (tablero[j][0] != ' ' && tablero[j][0] == tablero[j][1]
            && tablero[j][1] == tablero[j][2])
            return tablero[j][0];
    }

    //diagonal 1
    if (tablero[0][0] != ' ' &&
       tablero[0][0] == tablero[1][1] &&
       tablero[1][1] == tablero[2][2])
        return tablero[0][0];

    // diagonal 2
    if (tablero[0][2] != ' ' &&
        tablero[0][2] == tablero[1][1] &&
        tablero[1][1] == tablero[2][0])
        return tablero[0][2];

    return ' ';
}

bool empate()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tablero[i][j] == ' ')
                return false;

    return true;
}

void iniciarTotiToto()
{
    const int ancho = 800;
    const int altura = 600;

    InitWindow(ancho, altura, "Totito");

    SetTargetFPS(60);

    srand(time(NULL));

    reinciarTablero();

    int intEstado = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);

        if (intEstado == 0)
        {
            DrawText("Elejir Figura", 300, 150, 30, WHITE);

            DrawRectangle(300, 250, 80, 50, LIGHTGRAY);
            DrawText("X", 300, 260, 30, WHITE);

            DrawRectangle(420, 250, 80, 50, LIGHTGRAY);
            DrawText("O", 450, 260, 30, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 m =  GetMousePosition();

                if (CheckCollisionPointRec(m,(Rectangle){300, 250, 80, 50}))
                {
                    jugador = 'X';
                    pc = 'O';
                    turnoJugador = true;
                    intEstado = 1;
                }

                if (CheckCollisionPointRec(m,(Rectangle){420, 250, 80, 50}))
                {
                    jugador = 'O';
                    pc = 'X';
                    turnoJugador = false;
                    intEstado = 1;
                }
            }
        }

        else if (intEstado == 1)
        {
            if (turnoJugador)

                DrawText("Empieza Jugador", 300, 250, 30, WHITE);
            else
                DrawText("Empieza PC", 320, 250, 30, WHITE);

            DrawText("Click para continuar", 270, 350, 20, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_ENTER))
                intEstado = 2;
        }

        // else if (intEstado == 2)
        // {
        //     dibujarTablero();
        //
        //     if (turnoJugador)
        //         clickJugador();
        //     else
        //     {
        //         movimientosPC();
        //         turnoJugador = true;
        //     }
        // }

        else if (intEstado == 2)
        {
            dibujarTablero();

            char ganador = verificarGanador();

            if (ganador == jugador)
            {
                DrawText("GANASTE", 320, 400, 30, GREEN);
            }
            else if (ganador == pc)
            {
                DrawText("PERDITE", 320, 400, 30, RED);
            }
            else if (empate())
            {
                DrawText("EMPATe", 320, 400, 30, YELLOW);
            }
            else
            {
                if (turnoJugador)
                    clickJugador();
                else
                {
                    movimientosPC();
                    turnoJugador = true;
                }
            }

        }

        EndDrawing();
    }

    CloseWindow();
}