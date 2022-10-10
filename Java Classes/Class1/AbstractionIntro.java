
/*
 * Method Overriding: a method which is declared/defined in parent class redefined in 
 * subclass is called Overriding. 
 * 
 * Method Overloading: 
 */

abstract class Animal {

    abstract void walk();

    abstract void run();

    abstract void jump();
}

abstract class Dog extends Animal {
    @Override
    void run() {
        System.out.println("Dog is running...");
    }

    @Override
    void walk() {
        System.out.println("Dog is walking...");
    }
}

class GermanShepherdDog extends Dog {
    @Override
    void jump() {
        System.out.println("Dog is jumping at 5feet+ height...");
    }
}

public class AbstractionIntro {

    public static void main(String[] args) {

        GermanShepherdDog dog = new GermanShepherdDog();
        dog.walk();
        dog.run();
        dog.jump();
    }

}
