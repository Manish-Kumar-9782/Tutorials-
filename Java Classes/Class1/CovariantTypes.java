
class Animal {

    void display() {
        System.out.println("I am a wild animal...!");
    }

    Animal getAnimal() {
        return this;
    }
}

class Dog extends Animal {

    void display() {
        System.out.println("I am a wild dog...!");
    }

    public Object getObject() {
        return this;
    }

    @Override
    Dog getAnimal() {
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

    @Override
    Cat getAnimal() {
        return this;
    }
}

public class CovariantTypes {

    public static void main(String[] args) {

        Animal animal = new Animal();
        Cat cat = new Cat();
        Dog dog = new Dog();
        System.out.println("\n-------------------------------------\n");
        System.out.println("Animal: " + animal.getAnimal());
        System.out.println("Dog: " + dog.getAnimal());
        System.out.println("Cat: " + cat.getAnimal());
        System.out.println("\n-------------------------------------\n");
    }
}
