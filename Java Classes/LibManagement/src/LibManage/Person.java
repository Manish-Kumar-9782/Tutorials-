package LibManage;

public class Person {

    String name;
    int age;
    double height;
    Address adrs;

    static String tableFormat = "%20s %8s %8s";

    Person(String name, int age, double height, Address adrs){
        this.age =age;
        this.name = name;
        this.height = height;
        this.adrs = adrs;
    }

    void inline_display(){
        System.out.println(String.format(Person.tableFormat, this.name, this.age,  this.height));
    }

    void showAddress(){
        System.out.println(this.name + " " + "Address:\n");
        adrs.display();
    }

    static void showHeading(){
        System.out.println(String.format(Person.tableFormat, "Name", "Age", "Height"));
    }

}
