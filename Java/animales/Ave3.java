/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package animales;

import herencia.Ave2;

/**
 *
 * @author user
 */
public class Ave3 extends Ave2{
   
     public Ave3(){
         
     }
    
     public Ave3(String especie, String nombre, float peso){
        this.setEspecie(especie);
        this.setPeso(peso);
        this.setNombre(nombre);
        super.setNombre(nombre);
        
        
    }
    
    
    public void setRespiracion(String respiracion){
        super.respiracion=respiracion;
    }
    
        
    @Override
    public String toString (){
        return "Este es un "+super.getNombre()+" " +this.getNombre()+" el cual es un Ave de la especie "+ super.getEspecie()+" su peso es  "+super.getPeso() +" en Kg o "+this.getPeso() +" en gramos"      ;
    }
    
}
