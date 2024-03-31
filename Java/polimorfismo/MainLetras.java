/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package polimorfismo;

/**
 *
 * @author user
 */
public class MainLetras {
    public static void main(String args[]){
        A l1 = new C();
        l1.dummyA();    
      
        ((B)l1).dummyB();        
        ((C)l1).dummyC();
        
        
        l1.la=0;
        
        ((B)l1).lb=1;
        ((C)l1).lc=2;
        
        B l2 = new C();
        l2.dummyA();
        l2.dummyB();
        ((C)l2).dummyC();
        l2.la=0;
        l2.lb=1;
        ((C)l2).lc=2;
        
        /**/
        
        
    }
}
