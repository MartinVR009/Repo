package herencia;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author user
 */
public class Animal {
    
    public String nombre;
    private String especie;    
    private float  peso; 
    protected String respiracion;  //Diapositiva 15
    
    
    private void metodoPrivado(String args){
        System.out.println("Un metodo privado");
    }
    
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getEspecie() {
        return especie;
    }

    public void setEspecie(String especie) {
        this.especie = especie;
    }

    public final float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public String getRespiracion() {
        return respiracion;
    }

    public void setRespiracion(String respiracion) {
        this.respiracion = respiracion;
    }
    
    @Override
    public String toString (){
        return "Este es un "+nombre+" el cual es un Animal de la especie "+ this.especie;
    }
    
}
