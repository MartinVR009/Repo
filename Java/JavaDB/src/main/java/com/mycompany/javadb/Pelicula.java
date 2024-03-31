
package com.mycompany.javadb;

public class Pelicula {
    private String Movie_Id;
    private String nameMovie;
    private String guionistas;
    private String subjects;
    private String directores;
    private String actores;
    private String generos;
    
    public Pelicula(){
        this.Movie_Id = "98809";
        this.nameMovie = "Hobbit: An Unexpected Journey| The (2012)";
        this.guionistas = "Guillermo del Toro| Fran Walsh| J.R.R. Tolkien| Philippa Boyens";
        this.subjects = " ";
        this.directores = "Peter Jackson'";
        this.actores = "Ian McKellen| Martin Freeman| Andy Serkis| Richard Armitage ";
        this.generos = "Adventure";
    }
    //98809','Hobbit: An Unexpected Journey| The (2012)','Guillermo del Toro| Fran Walsh| J.R.R. Tolkien| Philippa Boyens','','Peter Jackson','Ian McKellen| Martin Freeman| Andy Serkis| Richard Armitage',''
    
   public Pelicula(String movie_id, String namemovie,String guionistas,String subjects,String directores,String actores,String generos){
       this.Movie_Id = movie_id;
       this.nameMovie = namemovie;
       this.guionistas = guionistas;
       this.subjects = subjects;
       this.directores = directores;
       this.actores = actores;
       this.generos = generos;
   }
    //Metodos
    public String getMovie_Id() {
        return Movie_Id;
    }

    public void setMovie_Id(String Movie_Id) {
        this.Movie_Id = Movie_Id;
    }

    public String getNameMovie() {
        return nameMovie;
    }

    public void setNameMovie(String nameMovie) {
        this.nameMovie = nameMovie;
    }  
    public String getGuionistas(){
        return guionistas;
    }

    public void setGuionistas(String guionistas) {
        this.guionistas = guionistas;
    }
    
    public String getSubjects() {
        return subjects;
    }

    public void setSubjects(String subjects) {
        this.subjects = subjects;
    }

    public String getDirectores() {
        return directores;
    }

    public void setDirectores(String directores) {
        this.directores = directores;
    }

    public String getActores() {
        return actores;
    }

    public void setActores(String actores) {
        this.actores = actores;
    }

    public String getGeneros() {
        return generos;
    }

    public void setGeneros(String generos) {
        this.generos = generos;
    }
}
