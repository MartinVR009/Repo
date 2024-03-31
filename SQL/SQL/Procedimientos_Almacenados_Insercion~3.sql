--Procedimiento insert Peliculas
CREATE OR REPLACE PROCEDURE InsertarPelicula(
    p_Movie_ID IN VARCHAR2,
    p_NameMovie IN VARCHAR2,
    p_guionistas IN VARCHAR2,
    p_subjects IN VARCHAR2,
    p_directores IN VARCHAR2,
    p_actores IN VARCHAR2,
    p_generos IN VARCHAR2
)
IS
BEGIN
    INSERT INTO Peliculas(Movie_ID, NameMovie, guionistas, subjects, directores, actores, generos)
    VALUES(p_Movie_ID, p_NameMovie, p_guionistas, p_subjects, p_directores, p_actores, p_generos);
    COMMIT;
END;
/
--Procedure insert Usuarios
CREATE OR REPLACE PROCEDURE InsertarUsuario(
    p_UserId IN VARCHAR2,
    p_nombre IN VARCHAR2,
    p_edad IN NUMBER
)
IS
BEGIN
    INSERT INTO USUARIOS(UserId, nombre, edad)
    VALUES(p_UserId, p_nombre, p_edad);
    COMMIT;
END;
/
--Procedure Insert Rating
CREATE OR REPLACE PROCEDURE InsertarRating(
    p_Movie_ID IN VARCHAR2,
    p_rating IN NUMBER,
    p_fecha IN DATE,
    p_userId IN NUMBER
)
IS
BEGIN
    INSERT INTO Rating(Movie_ID, rating, fecha, userId)
    VALUES(p_Movie_ID, p_rating, p_fecha, p_userId);
    COMMIT;
END;
/