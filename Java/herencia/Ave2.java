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
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author user
 */
public class Ave2 extends Animal{
     
    private float peso;
    
    public Ave2(){
        
    }
    public Ave2(String especie, String nombre, float peso){
        this.setEspecie(especie);
        this.setPeso(peso);
        this.setNombre(nombre);
    }
    
    @Override
    public void setPeso(float peso){
        this.peso =peso;
        super.setPeso(peso/1000);
    }
    
    /*
    public float  getPeso(){
        return super.getPeso()*1000f;
    }
    */
    
    
    @Override
    public String toString (){
        return "Este es un "+super.getNombre()+" el cual es un Ave de la especie "+ super.getEspecie()+" su peso es  "+super.getPeso() +" en Kg o "+this.peso+" en gramos"      ;
    }
    
    
}
