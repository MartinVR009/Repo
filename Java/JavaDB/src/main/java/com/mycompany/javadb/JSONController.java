
package com.mycompany.javadb;

import static com.mycompany.javadb.Constants.PASS;
import static com.mycompany.javadb.Constants.URL_DATABASE;
import static com.mycompany.javadb.Constants.USER;
import java.sql.CallableStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import oracle.jdbc.OracleTypes;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class JSONController {
    private CallableStatement callableStatement = null;
    private DBManager man = DBManager.getInstance();
    ResultSet resultSet = null;
    Pelicula pelicula = null;
    Rating rating = null;
    Usuario usuario = null;
    
    ArrayList<Pelicula> peliculas  = new ArrayList<>();
    ArrayList<Rating> ratings = new ArrayList<>();
    ArrayList<Usuario> usuarios = new ArrayList<>();
    
    public JSONController(){}
    public ArrayList<Pelicula> llamarPeliculas(int filaInicial, int cantidadRegistros) {
        try {
            boolean res = man.connect(URL_DATABASE, USER, PASS);
            if (res) {
                System.out.println("SI");
            } else {
                System.out.println("NO");
            }
            
            String sql = "{call paginar_peliculas(?, ?, ?)}";
            callableStatement = man.con.prepareCall(sql);
            callableStatement.setInt(1, filaInicial);
            callableStatement.setInt(2, cantidadRegistros);
            callableStatement.registerOutParameter(3, OracleTypes.CURSOR);

            callableStatement.execute();

            ResultSet resultSet = (ResultSet) callableStatement.getObject(3);
            
            while(resultSet.next()){
                pelicula = new Pelicula();
                pelicula.setMovie_Id(resultSet.getString("Movie_Id"));
                pelicula.setNameMovie(resultSet.getString("namemovie"));
                pelicula.setGuionistas(resultSet.getString("guionistas"));
                pelicula.setSubjects(resultSet.getString("subjects"));
                pelicula.setDirectores(resultSet.getString("directores"));
                pelicula.setActores(resultSet.getString("actores"));
                pelicula.setGeneros(resultSet.getString("generos"));
                peliculas.add(pelicula);
            }
            resultSet.close();
        } catch (SQLException e) {
            System.out.println("Fallo en el llamado");
               e.printStackTrace();
        }
        return peliculas;
    }
    
     public ArrayList<Rating> llamarRating(int filaInicial, int cantidadRegistros) {
        try {
            boolean res = man.connect(URL_DATABASE, USER, PASS);
            if (res) {
                System.out.println("SI");
            } else {
                System.out.println("NO");
            }
            
            String sql = "{call paginar_ratings(?, ?, ?)}";
            callableStatement = man.con.prepareCall(sql);
            callableStatement.setInt(1, filaInicial);
            callableStatement.setInt(2, cantidadRegistros);
            callableStatement.registerOutParameter(3, OracleTypes.CURSOR);

            callableStatement.execute();

            ResultSet resultSet = (ResultSet) callableStatement.getObject(3);
            
            while(resultSet.next()){
                rating = new Rating();
                rating.setmovieId(resultSet.getString("MOVIE_ID"));
                rating.setRating(resultSet.getInt("RATING"));
                rating.setFecha(resultSet.getDate("fecha"));
                rating.setUserId(resultSet.getInt("userid"));
                ratings.add(rating);
            }
            resultSet.close();
        } catch (SQLException e) {
            System.out.println("Fallo en el llamado");
               e.printStackTrace();
        }
        return ratings;
    }
     public ArrayList<Usuario> llamarUsuarios(int filaInicial, int cantidadRegistros) {
        try {
            boolean res = man.connect(URL_DATABASE, USER, PASS);
            if (res) {
                System.out.println("SI");
            } else {
                System.out.println("NO");
            }
            String sql = "{call paginar_usuarios(?, ?, ?)}";
            callableStatement = man.con.prepareCall(sql);
            callableStatement.setInt(1, filaInicial);
            callableStatement.setInt(2, cantidadRegistros);
            callableStatement.registerOutParameter(3, OracleTypes.CURSOR);

            callableStatement.execute();

            ResultSet resultSet = (ResultSet) callableStatement.getObject(3);
            
            while(resultSet.next()){
                usuario = new Usuario();
                usuario.setUserId(resultSet.getString("userid"));
                usuario.setNombre(resultSet.getString("nombre"));
                usuario.setEdad(resultSet.getInt("edad"));
                
                usuarios.add(usuario);
            }
            resultSet.close();
        } catch (SQLException e) {
            System.out.println("Fallo en el llamado");
               e.printStackTrace();
        }
        return usuarios;
    }
     public void cargarJSONP(ArrayList<Pelicula> p){
            Gson gson = new GsonBuilder().setPrettyPrinting().create();
            try (FileWriter writer = new FileWriter("C:\\Users\\marti\\OneDrive\\Documentos\\Python\\Programs\\CSV_Py\\peliculas.json")) {
            // Convertir la lista en formato JSON y escribirla en el archivo
            gson.toJson(p, writer);
            System.out.println("Lista convertida y guardada en peliculas.json.");
        } catch (IOException e) {
            e.printStackTrace();
        }
     }
     public void cargarJSONR(ArrayList<Rating> p){
            Gson gson = new GsonBuilder().setPrettyPrinting().create();
            try (FileWriter writer = new FileWriter("C:\\Users\\marti\\OneDrive\\Documentos\\Python\\Programs\\CSV_Py\\ratings.json")) {
            // Convertir la lista en formato JSON y escribirla en el archivo
            gson.toJson(p, writer);
            System.out.println("Lista convertida y guardada en ratings.json.");
        } catch (IOException e) {
            e.printStackTrace();
        }
     }
     
     public void cargarJSONU(ArrayList<Usuario> p){
            Gson gson = new GsonBuilder().setPrettyPrinting().create();
            try (FileWriter writer = new FileWriter("C:\\Users\\marti\\OneDrive\\Documentos\\Python\\Programs\\CSV_Py\\usuarios.json")) {
            // Convertir la lista en formato JSON y escribirla en el archivo
            gson.toJson(p, writer);
            System.out.println("Lista convertida y guardada en usuarios.json.");
        } catch (IOException e) {
            e.printStackTrace();
        }
     }
}
