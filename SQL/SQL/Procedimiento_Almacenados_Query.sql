CREATE OR REPLACE PROCEDURE paginar_peliculas(
    p_fila_inicial IN NUMBER, 
    p_cantidad_registros IN NUMBER, 
    p_cursor OUT SYS_REFCURSOR) 
    AS
BEGIN
    OPEN p_cursor FOR
    SELECT * FROM Peliculas
    WHERE ROWNUM BETWEEN p_fila_inicial AND p_fila_inicial + p_cantidad_registros - 1;
END;
/


CREATE OR REPLACE PROCEDURE paginar_ratings (
    p_fila_inicial IN NUMBER,
    p_cantidad_registros IN NUMBER,
    p_cursor OUT SYS_REFCURSOR)
    AS
BEGIN
    OPEN p_cursor FOR
    SELECT * FROM RATING
    WHERE ROWNUM BETWEEN p_fila_inicial and p_fila_inicial + p_cantidad_registros -1;
END;
/

CREATE OR REPLACE PROCEDURE paginar_usuarios (
    p_fila_inicial IN NUMBER,
    p_cantidad_registros IN NUMBER,
    p_cursor OUT SYS_REFCURSOR)
    AS
BEGIN
    OPEN p_cursor FOR
    SELECT * FROM USUARIOS
    WHERE ROWNUM BETWEEN p_fila_inicial and p_fila_inicial + p_cantidad_registros -1;
END;
/


