cmake_minimum_required(VERSION 3.20)
project(ProyFinalProgra1)

set(CMAKE_CXX_STANDARD 17)

# Ruta de Raylib dentro del proyecto
set(RAYLIB_PATH ${CMAKE_SOURCE_DIR}/raylib-5.5_win64_mingw-w64)

include_directories(${RAYLIB_PATH}/include)
link_directories(${RAYLIB_PATH}/lib)

add_executable(ProyFinalProgra1 main.cpp
        DataBase/conexion.cpp
        DataBase/conexion.h
        Models/Usuarios.cpp
        Models/Usuarios.h
        Models/Juego.cpp
        Models/Juego.h
        Models/Partida.cpp
        Models/Partida.h
        Services/UsuarioServices.cpp
        Services/UsuarioServices.h
        Pantallas/Login.cpp
        Pantallas/Login.h
        Pantallas/Menu.cpp
        Pantallas/Menu.h
        Text/text.cpp
        Text/text.h
        Pantallas/RegistroUsuario.cpp
        Pantallas/RegistroUsuario.h
        Services/JuegosServices.cpp
        Services/JuegosServices.h
        Services/PartidasServices.cpp
        Services/PartidasServices.h
        Juegos/Ahorcados.cpp
        Juegos/Ahorcados.h)

target_link_libraries(ProyFinalProgra1
        raylib
        opengl32
        gdi32
        winmm
        odbc32
)