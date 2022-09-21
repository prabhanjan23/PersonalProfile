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
public class Car {
    public int gear;
    public int speed;

    public Car(int gear, int speed) {
        this.gear = gear;
        this.speed = speed;
    }
    
    public void increasegear(int gear){
        gear+= 1;
    }
    
    public void decreasegear(int gear){
        gear-=1;
    }

    @Override
    public String toString() {
        return "gear=" + gear + "\nspeed=" + speed;
    }
    
    
    
    
    
}
