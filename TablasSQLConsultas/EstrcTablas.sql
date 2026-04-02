create table Usuarios (id int  identity(1,1) primary key, Nombre varchar(50), Apellido varchar(50), Usuario varchar(50) unique, Clave varchar(50), Correo_Electronico varchar(50), Tokens int default 10)


create table Juegos (id_Juegos int identity(1,1) primary key, NombreJuego varchar(50), CostoTokens int)

INSERT INTO Juegos VALUES
('Snake',2),
('Pacman',3),
('Tetris',2);


create table Partidas(id_Partidas int identity(1,1) primary key, idUsuario int, idJuego int, Puntaje int, Fecha datetime default getdate(),
						foreign key (idUsuario) references Usuarios(id),
						foreign key (IdJuego) references Juegos(id_Juegos)
						)


create table Movimientos (idMovimientos int identity(1,1) primary key, idUsuario int, TipoMovimiento varchar(50), Tokens int, fecha datetime default getdate(),
							foreign key(idUsuario) references Usuarios(id)
						)