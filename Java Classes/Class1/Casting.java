
/*
 * DownCasting: When subclass type refers to the object of 
 * parent class, it is known as DownCasting.
 */

interface GetAnimal {

    public Object getObject();
}

class Animal {

    void display() {
        System.out.println("I am a wild animal...!");
    }
}

class Dog extends Animal implements GetAnimal {

    void display() {
        System.out.println("I am a wild dog...!");
    }

    public Object getObject() {
        return this;
    }
}

class Cat extends Animal {
    void display() {
        System.out.println("I am a beauty cat meow...!");
    }

    public Object getObject() {
        return this;
    }
}

public class Casting {

    public static void main(String[] args) {

        // DownCasting
        // Dog dog = (Dog) new Animal();

        // UpCasting
        Animal animal = new Dog();
        Animal animal2 = new Cat();
        Cat cat = new Cat();
        Dog dog = new Dog();

        System.out.println("is, dog is an animal: " + (dog instanceof Animal));
        System.out.println("is, cat is an animal: " + (cat instanceof Animal));
        System.out.println("is, Dog is an Object: " + (cat instanceof Object));
        System.out.println("is, cat is an Object: " + (dog instanceof Object));

        System.out.println("get dog object: " + dog.getObject());
        System.out.println("get cat object: " + cat.getObject());

    }
}