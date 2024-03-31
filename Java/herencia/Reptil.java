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
public class Reptil extends Animal {
    private int huevos;

    public int getHuevos() {
        return huevos;
    }

    public void setHuevos(int huevos) {
        this.huevos = huevos;
    }
    
    public String toString (){
        return "Este es un "+getNombre()+" el cual es un Reptil de la especie "+ super.getEspecie();
    }
    
}
