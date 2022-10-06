/*
 * In this section we will learn about the inheritance, inheritance is the concept of getting 
 * all the functionality from the parent class, and use them in the sub/child-class.
 * 
 * Note: java does not support the multiple inheritance.
 */

class Animal {
    int legs;
    int hands;
    int eyes;
    double runSpeed;
    double walkSpeed;
    double height;
    double weight;

    void walk() {
        System.out.println("animal waking!");
    }

    void run() {
        System.out.println("animal running!");
    }

}

// Now we will inherit this Animal class into the Dog class.

class Dog extends Animal {

    Dog() {
        this.legs = 4;
        this.hands = 0;
        this.eyes = 2;
    }

    void walk() {
        System.out.println("Dog is waking!");
    }

    void run() {
        System.out.println("Dog is running!");
    }

    void speak() {
        System.out.println("Dog is barking!");
    }
}

class HoundDog extends Dog {

    HoundDog() {
        /*
         * double runSpeed;
         * double walkSpeed;
         * double height;
         * double weight;
         * 
         */

        this.walkSpeed = 5; // 5km/hr
        this.runSpeed = 35; // 35/hr
        this.height = 3.5; // feet
        this.weight = 25; // kg

    }

    void walk() {
        System.out.println("HoundDog is waking at " + this.walkSpeed + " km/hr speed!");
    }

    void run() {
        System.out.println("HoundDog is running at" + this.runSpeed + " km/hr speed!");
    }

    void speak() {
        System.out.println("HoundDog is barking!");
    }
}

public class InheritanceIntro {

    public static void main(String[] args) {

        Animal animal = new Animal();
        Dog dog = new Dog();
        HoundDog hounddog = new HoundDog();

        animal.walk();
        dog.walk();
        hounddog.walk();
    }
}
