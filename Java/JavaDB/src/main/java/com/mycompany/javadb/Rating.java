
package com.mycompany.javadb;

import java.util.Date;

public class Rating {
    private String movieId;
    private float rating;
    private Date fecha;
    private int userId;
    
    public Rating()
    {
    }
    public Rating(String movieId, float rating, Date fecha, int userId) {
            this.movieId = movieId;
            this.rating = rating;
            this.fecha = fecha;
            this.userId = userId;
    }
    
    
    //Metodos
    public String getmovieId() {
        return movieId;
    }

    public void setmovieId(String movieId) {
        this.movieId = movieId;
    }

    public float getRating() {
        return rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }

    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }
}
