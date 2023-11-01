package human;

class Person {

    public String name;
    private int age;
    private double height;

    Person(String name, int age, double height){
        this.name = name;
        this.age = age;
        this.height = height;
        System.out.println("Person Constructor is called....");
    }

}
