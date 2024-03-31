package com.mycompany.javadb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.*;

public class DBManager implements IMethodsDB{

    public static DBManager instance = null;
    public static Connection con = null;

    public DBManager() {

    }

    public static DBManager getInstance() {
        if (instance == null) {
            instance = new DBManager();
        }
        return instance;
    }

    public boolean connect(String url, String user, String pass) {
        //step1 load the driver class
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
            //step2 create  the connection object
            con = DriverManager.getConnection(url, user, pass);
            return true;
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean closeConnection() {
        try {
            con.close();
            return true;
        } catch (SQLException throwables) {
            throwables.printStackTrace();
            return false;
        }
    }

    @Override
   public boolean printPeliculas() {
    try {
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT * FROM PELICULAS");
        while (rs.next()) {
            System.out.println(
                "Movie_ID: " + rs.getString("Movie_ID") + " | " +
                "NameMovie: " + rs.getString("NameMovie") + " | " +
                "Guionistas: " + rs.getString("guionistas") + " | " +
                "Subjects: " + rs.getString("subjects") + " | " +
                "Directores: " + rs.getString("directores") + " | " +
                "Actores: " + rs.getString("actores") + " | " +
                "Generos: " + rs.getString("generos")
            );
        }
        return true;
    } catch (SQLException e) {
        System.err.println(e.getMessage());
        return false;
    }
}
   @Override
public boolean printRatings() {
    try {
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT * FROM RATING");
        while (rs.next()) {
            System.out.println(
                "Movie_ID: " + rs.getString("Movie_ID") + " | " +
                "Rating: " + rs.getInt("rating") + " | " +
                "Fecha: " + rs.getDate("fecha") + " | " +
                "UserId: " + rs.getInt("userId"));
        }
        return true;
    } catch (SQLException e) {
        System.err.println(e.getMessage());
        return false;
    }
}

    @Override
    public boolean printUsuarios() {
    try {
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT * FROM USUARIOS");
        while (rs.next()) {
            System.out.println(
                "UserId: " + rs.getString("UserId") + " | " +
                "Nombre: " + rs.getString("Nombre") + " | " +
                "Edad: " + rs.getString("Edad"));
        }
        return true;
    } catch (SQLException e) {
        System.err.println(e.getMessage());
        return false;
    }
}


    @Override
    public int insertPeliculas(Pelicula data) {
        String sql = "INSERT INTO PELICULAS(movie_id,namemovie,guionistas,subjects,directores,actores,generos) VALUES(?,?,?,?,?,?,? )";
        try {
            PreparedStatement stmt = con.prepareStatement(sql);

            stmt.setString(1, data.getMovie_Id());
            stmt.setString(2, data.getNameMovie());
            stmt.setString(3, data.getGuionistas());
            stmt.setString(4, data.getSubjects());
            stmt.setString(5, data.getDirectores());
            stmt.setString(6, data.getActores());
            stmt.setString(7, data.getGeneros());
            int result = stmt.executeUpdate();

            System.out.println("Database updated successfully ");
            stmt.close();
            return result;
        } catch (SQLException e) {
            e.printStackTrace();
            return -1;
        }
    }

    @Override
    public void eliminarPelicula(String movieId) {
        try {
            String sql = "DELETE FROM PELICULAS WHERE Movie_ID = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setString(1, movieId);
            int filasAfectadas = stmt.executeUpdate();

            if (filasAfectadas > 0) {
                System.out.println("Registro borrado exitosamente.");
            } else {
                System.out.println("Ningún registro fue borrado.");
            }
        } catch (SQLException e) {
            System.err.println("Error al borrar el registro: " + e.getMessage());
        }
    }

    @Override
       public int insertarRating(Rating data) {
        String sql = "INSERT INTO RATING(movie_id, rating, fecha, userid) VALUES(?,?,?,?)";
        try {
            PreparedStatement cs = con.prepareStatement(sql);

            cs.setString(1, data.getmovieId());
            cs.setFloat(2, data.getRating());

            java.sql.Date sqlDate = new java.sql.Date(data.getFecha().getTime());
            cs.setDate(3, sqlDate);
            cs.setInt(4, data.getUserId());
            cs.execute();
            cs.close();
            return 0;

        } catch (SQLException throwables) {
            throwables.printStackTrace();
            return -1;
        }
    }

    @Override
    public int insertarUsuario(Usuario data) {
        String sql = "INSERT INTO USUARIOS(UserId, nombre, edad) VALUES(?,?,?)";
        try {
            PreparedStatement ps = con.prepareStatement(sql);

            ps.setString(1, data.getUserId());
            ps.setString(2, data.getNombre());
            ps.setInt(3, data.getEdad());
            ps.execute();
            ps.close();
            return 0;

        } catch (SQLException throwables) { 
            throwables.printStackTrace();
            return -1;
        }
    }

    @Override
    public int actualizarRating(int userId, String movieId, int rating) {
        String sql = "UPDATE RATING SET RATING = ? WHERE MOVIE_ID = ? AND USERID = ?";
        try {
            PreparedStatement ps = con.prepareStatement(sql);

            ps.setInt(1, userId);
            ps.setString(2, movieId);
            ps.setInt(3, rating);
            ps.execute();
            ps.close();
            return 0;

        } catch (SQLException throwables) { 
            throwables.printStackTrace();
            return -1;
        }
    }

    @Override
    public int deleteRegistro(int id) {
        return 0;
    }
}
