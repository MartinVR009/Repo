
package com.mycompany.javadb;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import static com.mycompany.javadb.Constants.PASS;
import static com.mycompany.javadb.Constants.URL_DATABASE;
import static com.mycompany.javadb.Constants.USER;
import java.text.ParseException;
import java.text.SimpleDateFormat;


public class CSVController {
        FileReader fReader = null;
        BufferedReader bReader = null;
        Pelicula pelicula = null;
        Rating rating = null;
        Usuario usuario = null;
        String archivo=null;
        String data[];
        String linea = " ";
        
       DBManager man = DBManager.getInstance();
    public CSVController(){
    }
    public void cargarPelicula() {
        boolean res = man.connect(URL_DATABASE, USER, PASS);
        if (res)
            System.out.println("SI");
        else
            System.out.println("NO");
           
           archivo = "C:\\Users\\marti\\OneDrive\\Documentos\\Python\\Programs\\CSV_Py\\nuevas_peliculas.csv";
           
            try {
                FileReader fReader = new FileReader(archivo);
                BufferedReader bReader = new BufferedReader(fReader);
                System.out.println("Sus peliculas estan cargando :) ...\n");
                   
                while((linea = bReader.readLine()) != null){
                    data = linea.split(","); 
                    pelicula = new Pelicula(data[0],data[1].trim(),data[2].trim(),data[3].trim(),data[4].trim(),data[5].trim(),data[6].trim());
                    man.insertPeliculas(pelicula);
                  System.out.println("Cargando pelicula: " + data[1]);
                }
                man.closeConnection();
            } catch (FileNotFoundException ex) {
                Logger.getLogger(CSVController.class.getName()).log(Level.SEVERE, null, ex);
            }catch(IOException e){
                System.out.print(e.getMessage());
            }
       }
    
       public void cargarRatings() {
           int fila=0;
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        
        boolean res = man.connect(URL_DATABASE, USER, PASS);
        if (res)
            System.out.println("SI");
        else
            System.out.println("NO");
           
           
           archivo = "C:\\Users\\marti\\OneDrive\\Documentos\\Python\\Programs\\CSV_Py\\rating_sql.csv";
            try {
                fReader = new FileReader(archivo);
                bReader = new BufferedReader(fReader);
                System.out.println("Sus Ratings  estan cargando :) ...\n");
                while((linea = bReader.readLine()) != null){
                    data = linea.split(",");
                    java.util.Date parsedDate = dateFormat.parse(data[2]);       
                    rating = new Rating(data[0],Float.parseFloat(data[1]) ,parsedDate,Integer.parseInt(data[3]));
                    System.out.println ("Fila " +(++fila));
                    man.insertarRating(rating);
                  System.out.println("Cargando Ratings: " + data[1]);
                }
                man.closeConnection();
            } catch (FileNotFoundException ex) {
                Logger.getLogger(CSVController.class.getName()).log(Level.SEVERE, null, ex);
            }catch(IOException e){
                System.out.print(e.getMessage());
            } catch (ParseException ex) {
                Logger.getLogger(CSVController.class.getName()).log(Level.SEVERE, null, ex);
            }
       }
       public void cargarUsuarios() {
        boolean res = man.connect(URL_DATABASE, USER, PASS);
        if (res)
            System.out.println("SI");
        else
            System.out.println("NO");
        
           archivo = "C:\\Users\\marti\\OneDrive\\Documentos\\Python\\Programs\\CSV_Py\\usuarios.csv";
            try {
                fReader = new FileReader(archivo);
                bReader = new BufferedReader(fReader);
                System.out.println("Sus usuarios estan cargando :) ...\n");
                while((linea = bReader.readLine()) != null){
                    data = linea.split(",");
                    usuario = new Usuario(data[0],data[1],Integer.parseInt(data[2]));
                    man.insertarUsuario(usuario);
                  System.out.println("Cargando Usuario: " + data[0]);
                }
                man.closeConnection();
            } catch (FileNotFoundException ex) {
                Logger.getLogger(CSVController.class.getName()).log(Level.SEVERE, null, ex);
            }catch(IOException e){
                System.out.print(e.getMessage());
            }
       }
}
