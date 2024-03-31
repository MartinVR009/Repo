
package com.mycompany.javadb;

public interface IMethodsDB {
    public boolean printPeliculas();
    public boolean printRatings();
    public boolean printUsuarios();
    public int insertPeliculas(Pelicula data);
    public int deleteRegistro(int id);
    public int insertarRating(Rating data);
    public int insertarUsuario(Usuario data);
    public void  eliminarPelicula(String movieId);
    public int actualizarRating(int userId, String movieid, int rating);
}


