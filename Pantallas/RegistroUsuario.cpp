#include "raylib.h"
#include "RegistroUsuario.h"
#include "../Text/text.h"
#include "../Models/Usuarios.h"
#include "../Services/UsuarioServices.h"


void pantallaRegistro(Conexion &db)
{

    UsuarioServices usuarioService;

    TextBox nombre(250,150,300,40);
    TextBox apellido(250,220,300,40);
    TextBox correo(250,290,300,40);
    TextBox clave(250,360,300,40);

    string usuarioCreado = "";
    bool creado = false;

    while (!WindowShouldClose())
    {
        nombre.update();
        apellido.update();
        correo.update();
        clave.update();

        BeginDrawing();
        ClearBackground(DARKBLUE);

        DrawText("Crear Usuario",300,50,30,YELLOW);

        DrawText("Nombre",250,130,20,BLACK);
        nombre.draw();

        DrawText("Apellido",250,200,20,BLACK);
        apellido.draw();

        DrawText("Correo",250,270,20,BLACK);
        correo.draw();

        DrawText("Clave",250,340,20,BLACK);
        clave.draw();

        Rectangle boton = {300,450,200,50};

        DrawRectangleRec(boton,DARKGREEN);
        DrawText("Crear Usuario",320,465,20,WHITE);

        if (creado)
        {
            DrawText("Usuario creado correctamente", 250, 500, 20, GREEN);

            DrawText(
            TextFormat("Usuario generado: %s", usuarioCreado.c_str()),
                250,
                530,
                20,
                YELLOW
            );

            DrawText("Se acreditaron 10 token por ser nuevo usuario", 250, 550, 20, GREEN);
        }

        if (CheckCollisionPointRec(GetMousePosition(), boton) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            Usuarios u;

            u.nombre = nombre.getText();
            u.apellido = apellido.getText();
            u.correo = correo.getText();
            u.clave = clave.getText();

            // usuarioService.crearUsuario(db, u);

            usuarioCreado = usuarioService.crearUsuario(db, u);
            creado = true;
        }

        EndDrawing();
    }
}