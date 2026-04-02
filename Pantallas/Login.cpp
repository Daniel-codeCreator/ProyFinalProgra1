#include "raylib.h"
#include "Login.h"
#include "../Text/text.h"
#include "../Services/UsuarioServices.h"
#include "RegistroUsuario.h"
#include "Menu.h"

void pantallaLogin(Conexion &db)
{

    UsuarioServices usuarioService;

    TextBox Usuario(250,200,300,40);
    TextBox clave(250,280,300,40);

    while (!WindowShouldClose())
    {

        Usuario.update();
        clave.update();

        BeginDrawing();
        ClearBackground(DARKBLUE);

        DrawText("Iniciar Sesion",300,100,30,YELLOW);

        DrawText("Usuario",250,180,20,BLACK);
        Usuario.draw();

        DrawText("Clave",250,260,20,BLACK);
        clave.draw();

        Rectangle botonLogin = {250,350,140,50};
        Rectangle botonRegistro = {420,350,140,50};

        DrawRectangleRec(botonLogin, DARKGREEN);
        DrawText("Login",290,365,20,WHITE);

        DrawRectangleRec(botonRegistro, BLUE);
        DrawText("Crear Usuario",425,365,20,WHITE);

        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, botonLogin) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            bool valido = usuarioService.iniciarSesion(
                db,
                Usuario.getText(),
                clave.getText()
            );
            // si el usuario es valido ingresa
            if(valido)
            {
                pantallaMenu();
                return;
            }
            else
            {
                DrawText("Usuario incorrecto",270,450,20,RED);
            }
        }

        if (CheckCollisionPointRec(mouse, botonRegistro) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            pantallaRegistro(db);
        }

        EndDrawing();
    }
}