/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package animales;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author user
 */


import herencia.Ave2;
import java.util.ArrayList;


public class Main3 {
    public static void main (String args[]){

        
        Ave2 aguila = new Ave2("Aquila chrysaetos","águila real",2900f);    
        //aguila.respiracion="aerobica";
        System.out.println("Informacion del Aguila:\n"+   aguila.toString());
        
         Ave3 halcon = new Ave3("Falco hypoleucos","Halcón gris",2200f);  
         System.out.println("Informacion del Halcon:\n"+   halcon.toString());
    }
}
