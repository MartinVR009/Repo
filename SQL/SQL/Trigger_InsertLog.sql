create or replace TRIGGER TR_LOG_RATINGS
BEFORE UPDATE ON RATING
FOR EACH ROW
BEGIN
    INSERT INTO LOG_RATINGS (
        log_id, 
        movie_id, 
        rating_antiguo, 
        rating_nuevo, 
        fecha_antigua, 
        fecha_nueva, 
        usuario_calificacion, 
        usuario_actualizacion, 
        fecha_actualizacion
    ) VALUES (
        log_id_seq.NEXTVAL, 
        :OLD.Movie_ID, 
        :OLD.rating, 
        :NEW.rating, 
        :OLD.fecha, 
        :NEW.fecha, 
        :OLD.userId, 
        :NEW.userId, 
        CURRENT_TIMESTAMP
    );
END;
/