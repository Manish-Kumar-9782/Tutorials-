
class Student {

    // static class data membersl
    // 1. countStudent;
    // 2. studentDatabase;
    // 3. primaryKey;

    static int countStudent;
    static int primaryKey;
    static Student studentDatabase[];

    // static initializer block
    static {
        Student.countStudent = 0;
        Student.primaryKey = 1000;
        Student.studentDatabase = new Student[10]; // making the size of the array as 10;
    }

    String name;
    int age;
    double height;
    int primarykey;

    Student(String name, int age, double height) {

        this.name = name;
        this.age = age;
        this.height = height;
        // adding primary key
        this.primarykey = Student.primaryKey;

        // Now we need to maintain the static variable.
        Student.studentDatabase[Student.countStudent] = this; // assigning the next student into the array.
        Student.countStudent++; // increasing the countStudent numbers
        Student.primaryKey++; // increasing the primary key values.
    }

    void display() {

        System.out.println("PrimaryKey:\t\t");
        System.out.println("Name:\t\t" + this.name);
        System.out.println("Age:\t\t" + this.age);
        System.out.println("Height:\t\t" + this.height);
    }

    void inline_display() {
        System.out.println(this.primarykey + "\t\t" + this.name + "\t\t" + this.age + "\t\t" + this.height);
    }

    static void student_heading() {
        System.out.println("primarykey" + "\t\t" + "name" + "\t\t" + "age" + "\t\t" + "height");
    }

    static void showDatabase() {
        // first we will show the heading
        System.out.println("\n=======================================================================\n");
        Student.student_heading();
        System.out.println("----------------------------------------------------------------------------");

        // now we need to show all the student information
        for (int i = 0; i < Student.countStudent; i++) {
            Student.studentDatabase[i].inline_display();
        }

        System.out.println("\n=======================================================================\n");

    }

};

public class StudentTest {

    public static void main(String[] args) {
        new Student("Yatharth", 26, 5.6);
        new Student("Kushal", 21, 5.5);
        new Student("Ravi", 22, 5.7);
        new Student("Manish", 26, 5.6);
        new Student("Abhishek", 20, 5.7);
        new Student("Komal", 21, 5.5);
        new Student("Saloni", 21, 5.6);

        // now displaying the database
        Student.showDatabase();
    }
}