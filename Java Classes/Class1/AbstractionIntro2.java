
abstract class Automobile {

    String engine;
    String type;
    String handlingSystem;
    int numberOfWheels;
    String breakingSystem;
    int numberOfSeats;

    abstract void setEngine();

    abstract void setHandlingSystem();

    abstract void setType();

    abstract void setWheels();

    void start() {
        System.out.println("Vehicle is starting.");
    }

    void move() {
        this.start();
        System.out.println("Vehicle is moving.");
    }

    void stop() {
        this.move();
        System.out.println("Vehicle is stopping.");
    }

}

class Car extends Automobile {

    Car() {
        this.setEngine();
        this.setHandlingSystem();
        this.setType();
        this.setWheels();
    }

    @Override // annotation
    void setEngine() {
        this.engine = "feat";
    }

    @Override
    void setHandlingSystem() {
        this.handlingSystem = "steering Wheel";
    }

    @Override
    void setType() {
        this.type = "four Wheeler Sedan";
    }

    @Override
    void setWheels() {
        this.numberOfWheels = 4;
    }

    void displayInfo() {
        System.out.println("Engine: " + this.engine);
        System.out.println("Handling: " + this.handlingSystem);
        System.out.println("Vehicle Type: " + this.type);
        System.out.println("Wheels: " + this.numberOfWheels);
    }
}

public class AbstractionIntro2 {

    public static void main(String[] args) {
        Car car = new Car();
        System.out.println("\n-----------------------------------\n");
        car.displayInfo();
        car.start();
        car.move();
        car.stop();
        System.out.println("\n-----------------------------------\n");
    }
}
