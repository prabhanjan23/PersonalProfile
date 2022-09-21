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
public class BMW extends Car {
    public boolean headlight;

    public BMW(int gear, int speed, boolean headlight) {
        super(gear, speed);
        this.headlight = headlight;
    }
    
    public void turnon(boolean headlight){
        this.headlight = headlight;
    }
    
    public void turnoff(boolean headlight){
        this.headlight = headlight;
    }

    @Override
    public String toString() {
        return super.toString() + "\nheadlight= " + headlight;
    }
       
    
}
