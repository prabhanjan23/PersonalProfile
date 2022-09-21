/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testing_1;

/**
 *
 * @author PrabhanjanPiwalatkar
 */
public class Testing_1 {

    
    public static void main(String[] args) {
        BMW b = new BMW(2, 40, false);
        BMW c = new BMW(2, 40, true);
        System.out.println(b.toString());
        System.out.println("\n"+c.toString());
    }
    
}
