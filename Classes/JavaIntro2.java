import java.util.Scanner;

class Student {

    String name;
    int age;
    double height;

    Student(String name, int age, double height) {
        this.name = name;
        this.age = age;
        this.height = height;
    }

    void display() {
        System.out.println("Name:\t" + this.name);
        System.out.println("Age:\t" + this.age);
        System.out.println("Height:\t" + this.height);
    }
}

public class JavaIntro2 {

    public static void main(String[] args) {
        // statement

        // creating the Scanner object
        Scanner read = new Scanner(System.in);

        System.out.print("Enter Student Name: ");
        String name = read.nextLine();

        System.out.print("Enter Student Age: ");
        int age = read.nextInt();

        System.out.print("Enter Student Height: ");
        double height = read.nextDouble();

        System.out.println("\n--------------------------------\n");
        Student st = new Student(name, age, height);
        st.display();
        System.out.println("\n--------------------------------\n");
    }
}
