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
public class Mamifero extends Animal {
    private int lactancia;

    public int getLactancia() {
        return lactancia;
    }

    public void setLactancia(int lactancia) {
        this.lactancia = lactancia;
    }
    
    public String toString (){
        return "Este es un "+super.getNombre()+" el cual es un Mamifero de la especie "+ super.getEspecie();
        
    }
    
    
}
