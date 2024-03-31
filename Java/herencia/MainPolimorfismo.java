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
public class MainPolimorfismo {
    public static void main (String args[]){
        Animal animal = new Animal();
        Animal perro =  new Mamifero();
        Animal cocodrilo= new Reptil();
        
        /*Esto si se puede
        Animal m = new Mamifero();
        Animal r  = new Reptil();
        r=m;
        */
        
        cocodrilo.setEspecie("saurópsidos arcosaurios");
        cocodrilo.setNombre("Cocodrilo");
        cocodrilo.setPeso(730f);
        
        if (cocodrilo instanceof Reptil){
            System.out.println("El cocodrilo extiende del Reptil");
            //cocodrilo).setHuevos(2);
            ((Reptil) cocodrilo).setHuevos(12);   
            
            System.out.println ("Una mamá cocodrilo coloca maximo "+ ((Reptil) cocodrilo).getHuevos()+" huevos a la vez!!");
            System.out.println ("Info del cocodrilo "+ ((Reptil) cocodrilo).toString());
            System.out.println ("Info del cocodrilo "+ cocodrilo.toString()); //Igual que en la linea anterior
            
            /*
            ((Mamifero) cocodrilo).setLactancia(3);
             System.out.println ("Lactancia del cocodrilo "+ ((Mamifero)cocodrilo).getLactancia());
            */
        }
        if (perro instanceof Ave)
            System.out.println("El perro extiende deL Ave");
        else
            System.out.println("El perro NO extiende del Ave");

        
        /*Si es posible */
        Animal m = new Mamifero();
        m.setEspecie("Felis silvestris catus");
        m.setNombre("Gato");
        m.setPeso(5f);
        Animal r  = new Reptil();
        Animal r2 = new Reptil();
        r=m;
        System.out.println("Letrero de reptil a mamifero:"+r.toString());
        
        r2.setEspecie("saurópsidos arcosaurios");
        r2.setNombre("Cocodrilo");
        r2.setPeso(730f);
        System.out.println("Informacion del cocodrilo:\n"+   r2.toString());
     
        Ave2 aguila = new Ave2("Aquila chrysaetos","águila real",2900f);        
        System.out.println("Informacion del Aguila:\n"+   aguila.toString());
    }
    
    
}
