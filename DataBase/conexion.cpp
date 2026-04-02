#include "Conexion.h"
#include <iostream>

Conexion::Conexion() {
    env = nullptr;
    dbc = nullptr;
}

bool Conexion::conectar() {

    SQLRETURN ret;
    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;

    // 1️⃣ Crear entorno
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);

    // 2️⃣ Crear conexión
    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);

    // 3️⃣ Conectar a SQL Server
    ret = SQLDriverConnect(
        dbc,
        NULL,
        (SQLCHAR*)"Driver={ODBC Driver 17 for SQL Server};Server=DANIEL\\SQLEXPRESS;Database=ProyFinalProgra1;Trusted_Connection=yes;",
        SQL_NTS,
        outstr,
        sizeof(outstr),
        &outstrlen,
        SQL_DRIVER_COMPLETE
    );

    if (SQL_SUCCEEDED(ret)) {
        std::cout << "Conexion exitosa a SQL Server\n";
        return true;
    } else {
        std::cout << "Error al conectar a SQL Server\n";
        return false;
    }
}

void Conexion::desconectar() {

    if (dbc != nullptr) {
        SQLDisconnect(dbc);
        SQLFreeHandle(SQL_HANDLE_DBC, dbc);
    }

    if (env != nullptr) {
        SQLFreeHandle(SQL_HANDLE_ENV, env);
    }

    std::cout << "Conexion cerrada\n";
}

SQLHDBC Conexion::getConnection() {
    return dbc;
}