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
public class MainHerencia {
    public static void main (String args[]){
        Animal animal = new Animal();
        
        Mamifero perro =  new Mamifero();
        
        Reptil cocodrilo= new Reptil();
        Ave aguila=  new Ave();
        
        //No es posible lo siguiente
        /*
        Mamifero m = new Mamifero();
        Reptil r  = new Reptil();
        r=m;
        */    
       
        
        
        animal.setEspecie("Bubo africanus");
        animal.setNombre("Búho manchado");
        animal.setPeso(0.490f);
        System.out.println("Informacion del buho:\n"+   animal.toString());
        
        perro.setEspecie("Cánidos");
        perro.setNombre("Perros pastores");
        perro.setPeso(40f);
        perro.setLactancia(5);
        System.out.println("Informacion del Perro:\n"+   perro.toString());
        
        cocodrilo.setEspecie("saurópsidos arcosaurios");
        cocodrilo.setNombre("Cocodrilo");
        cocodrilo.setPeso(730f);
        System.out.println("Informacion del cocodrilo:\n"+   cocodrilo.toString());
     
        
        aguila.setEspecie("Aquila chrysaetos");
        aguila.setNombre("águila real");
        aguila.setPeso(2900f);
        aguila.respiracion="aerobica";
        System.out.println("Informacion del Aguila:\n"+   aguila.toString());
        
        Animal mamifero2 = new Mamifero();
        Mamifero mamifero3 =  new Mamifero();
        
        Animal reptil2=  new Reptil();
        
        
        if (mamifero2 instanceof Mamifero ){
            System.out.println ("Mamifero2  extiende de Mamifer");
            
            mamifero3.setLactancia(0);
                        //mamifero2.setLactancia(1); No se puede hacer esto sin casteo
            ((Mamifero)mamifero2).setLactancia(1);
            
            System.out.println("La lactancia del mamifero2 es " +((Mamifero)mamifero2).getLactancia());
            mamifero2.setNombre("caballo");
            mamifero2.setEspecie("equino");
            System.out.println("ToString de mamifero2:" +mamifero2.toString());
            System.out.println("ToString de mamifero2:" +((Mamifero)mamifero2).toString());
        }
        reptil2.setEspecie("cocodrilo");
        ((Reptil)reptil2).setHuevos(2);
        mamifero2= reptil2;
        ((Reptil)mamifero2).setHuevos(5);
        System.out.println ("La especie de mamifero2 es "+ mamifero2.getEspecie());
        System.out.println ("El numero de huevos que coloca mamifero2 es "+ ((Reptil)mamifero2).getHuevos());
        System.out.println ("El numero de huevos que coloca reptil2 es "+ ((Reptil)reptil2).getHuevos());
        
        
        
    }
        
        
        
        
    
    }
    
    

