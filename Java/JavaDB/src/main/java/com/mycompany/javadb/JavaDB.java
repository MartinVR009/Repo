package com.mycompany.javadb;

import static com.mycompany.javadb.Constants.PASS;
import static com.mycompany.javadb.Constants.URL_DATABASE;
import static com.mycompany.javadb.Constants.USER;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Set;

public class JavaDB {
    public static void main(String[] args) {
        /*
        System.out.println("Hello world!");
        CSVController csv = new CSVController();
        DBManager man = DBManager.getInstance();
        boolean res = man.connect(URL_DATABASE, USER, PASS);
        try{
            if (res)
                System.out.println("SI");
            else
                System.out.println("NO");
            }catch(Exception e) {
                e.getMessage();
        }
        Scanner scanner = new Scanner(System.in);

        System.out.println("Ingresa el nombre de la película: ");
        String idPelicula= scanner.nextLine();

        System.out.println("Ingresa el nombre de usuario: ");
        int nombreUsuario = scanner.nextInt();

        System.out.println("Ingresa la nueva calificación: ");
        int nuevaCalificacion = scanner.nextInt();
        
        int verificar = man.actualizarRating(nombreUsuario, idPelicula, nuevaCalificacion);
        if(verificar == -1){
            System.out.println("Error actualizando");
        }else{
            System.out.println("Actualizacion exitosa");
        }*/
        
      
        
        
        //Este codigo crea los archivos JSON de pelicula, rating y usuarios
        JSONController jsc = new JSONController();
        ArrayList<Pelicula> peliculas =jsc.llamarPeliculas(1, 100);
        ArrayList<Rating> ratings =jsc.llamarRating(1, 100);
        ArrayList<Usuario> usuarios =jsc.llamarUsuarios(1, 100);
        
        /*
        jsc.cargarJSONP(peliculas);
        jsc.cargarJSONR(ratings);
        jsc.cargarJSONU(usuarios);
        */
        
        int i = 1;
        //Este sirve para comprobar que los objetos se crearon y se guardaron en los ArrayList
        for( Pelicula p: peliculas){
            System.out.println("Pelicula #:" + i++ + " " + p.getMovie_Id());
        }
        i = 1;
        for( Rating p: ratings){
            System.out.println("Rating#:" + i++ + " " + p.getmovieId());
        }
        i = 1;
        for( Usuario p: usuarios){
            System.out.println("Usuario#:" + i++ + " " + p.getUserId());
        }
        
        
        //man.printUsuarios();
        //man.printRatings();
        //man.printPeliculas();
        //man.eliminarPelicula("1101");  //Este ejemplo borra la pelicula Top Gun
        // csv.cargarPelicula();
        //csv.cargarRatings();
        //csv.cargarUsuarios();

    }
}
