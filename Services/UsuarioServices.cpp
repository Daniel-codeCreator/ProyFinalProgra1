#include "UsuarioServices.h"
#include <sqlext.h>
#include <iostream>

using namespace  std;

string UsuarioServices::crearUsuario(Conexion &db, Usuarios u)
{

    SQLHSTMT stmt;

    SQLAllocHandle(SQL_HANDLE_STMT, db.getConnection(), &stmt);

    string query =
        "EXEC CrearUsuario '" +
        u.nombre + "','" +
        u.apellido + "','" +
        u.correo + "','" +
        u.clave + "'";

    SQLExecDirect(stmt, (SQLCHAR*)query.c_str(), SQL_NTS);

    SQLCHAR usuarioGenerado[50];

    string usuario = "";

    if (SQLFetch(stmt) == SQL_SUCCESS)
    {
        SQLGetData(stmt, 1, SQL_C_CHAR, usuarioGenerado, sizeof(usuarioGenerado), NULL);

        usuario = (char*)usuarioGenerado;
    }


    SQLFreeHandle(SQL_HANDLE_STMT, stmt);

    cout << "Usuario creado correctamente\n";

    return usuario;
}

bool UsuarioServices::iniciarSesion(Conexion& db, string usuaio, string clave)
{
    SQLHSTMT stmt;

    SQLAllocHandle(SQL_HANDLE_STMT, db.getConnection(), &stmt);

    string query =
        "select COUNT(*) FROM Usuarios WHERE usuario='" +
        usuaio + "' and clave='" + clave + "'";

    SQLExecDirect(stmt, (SQLCHAR*)query.c_str(), SQL_NTS);

    SQLINTEGER cout = 0;

    SQLBindCol(stmt, 1, SQL_C_SLONG, &cout, 0, NULL);
    SQLFetch(stmt);

    SQLFreeHandle(SQL_HANDLE_STMT, stmt);

    return cout > 0;
}
