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
public class Ave extends Animal{
    
    public void setPeso(float peso){
        super.setPeso(peso / 1000);
        
    }
    
    /*
    public void getPeso(){
        return super.getPeso()*1000f;
    }
    */
   
    public String toString (){
        return "Este es un "+super.getNombre()+" el cual es un Ave de la especie "+ super.getEspecie()+" su peso es  "+super.getPeso();
    }
    
    
}
