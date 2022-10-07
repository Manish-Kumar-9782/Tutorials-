
/*
 * access specifier:
 * 
 * byte, short, long, double, float, int, String, char.
 * 
 *
 * private: 
 * protected:
 * default:
 * public: 
 * 
 * In java we don't have multiple and hybrid inheritance
 * 
 * supported inheritance: single, multilevel, hierarchal.
 * 
 * 
 */

class Animal {

    int legs;
    int eyes;
    int ears;
    String sound;
    double height;
    double length;
    boolean isFly;
    double walkSpeed;
    double runSpeed;

    void walk() {
        System.out.println("Animal is waking!");
    }

    void run() {
        System.out.println("Animal is running!");
    }
}

class Dog extends Animal {

    String color;
    String type;

    Dog() {
        this.legs = 4;
        this.ears = 2;
        this.eyes = 2;
        this.isFly = false;
    }

    void walk() {
        System.out.println("Dog is waking!");
    }

    void run() {
        System.out.println("Dog is running!");
    }

}

class Cat extends Animal {

    String color;
    String type;

    Cat() {
        this.legs = 4;
        this.ears = 2;
        this.eyes = 2;
        this.isFly = false;
    }

    void walk() {
        System.out.println("Cat is waking!");

    }

    void run() {
        System.out.println("Cat is running!");
    }

}

public class InheritanceIntro1 {

    public static void main(String[] args) {
        Dog dog = new Dog();
        Cat cat = new Cat();

        // now we will walk and run both cat and dog
        dog.walk();
        cat.walk();

        dog.run();
        cat.run();
    }
}
