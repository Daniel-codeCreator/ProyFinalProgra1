#ifndef USUARIOSERVICES_H
#define USUARIOSERVICES_H

#include "../Models/Usuarios.h"
#include "../DataBase/conexion.h"

using namespace  std;

class UsuarioServices {

public:

    void crearUsuario(Conexion &db, Usuarios u);

    bool iniciarSesion(Conexion &db, string usuario, string clave); // NUEVO


};





#endif