
package com.mycompany.javadb;

public class Usuario {
    private String userId;
    private String nombre;
    private int edad;
    
    public Usuario(){}
    
    public Usuario(String userId, String nombre, int edad) {
        this.userId = userId;
        this.nombre = nombre;
        this.edad = edad;
    }
    //Metodos
    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    // Getter y Setter para nombre
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    // Getter y Setter para edad
    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }
}
