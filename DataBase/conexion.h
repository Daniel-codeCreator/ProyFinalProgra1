#ifndef CONEXION_H
#define CONEXION_H

#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOUSER
#include <windows.h>

#include <sqlext.h>
#include <iostream>

class Conexion {

private:

    SQLHENV env;
    SQLHDBC dbc;

public:

    Conexion();

    bool conectar();
    void desconectar();

    SQLHDBC getConnection();
};

#endif