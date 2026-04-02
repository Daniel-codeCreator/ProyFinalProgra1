#include "raylib.h"
#include "DataBase/conexion.h"
#include "Pantallas/Login.h"

int main() {

    InitWindow(800,600,"Arcade");

    Conexion db;

    if(!db.conectar()) return 1;

    pantallaLogin(db);

    db.desconectar();

    CloseWindow();

    return 0;
}