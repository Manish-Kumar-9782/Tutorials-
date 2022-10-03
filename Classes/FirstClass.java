
class Student {

    public static int countStudent;
    public static Student StudentDataBase[];
    public static int PrimaryKey;

    String name;
    int age;
    double height;

    static {

        Student.countStudent = 0;
        Student.StudentDataBase = new Student[10];
        Student.PrimaryKey = 1000;
    }

    Student(String name, int age, double height) {

        this.name = name;
        this.age = age;
        this.height = height;

        Student.StudentDataBase[countStudent] = this;
        Student.PrimaryKey++;
        Student.countStudent++;
    }

    void inline_display() {
        System.out.println(String.format("%-15s %-10s %-10s", this.name, this.age, this.height));

    }

    public static void ShowDataBase() {
        System.out.println(String.format("%-15s %-10s %-10s", "Name", "Age", "Height"));

        for (int i = 0; i < Student.countStudent; i++) {
            Student.StudentDataBase[i].inline_display();
        }
    }
}

public class FirstClass {

    public static void main(String[] args) {
        System.out.println("Student Record");

        new Student("Manish", 26, 5.7);
        new Student("Rahul", 21, 5.8);
        new Student("Abhishek", 21, 5.7);
        new Student("Kushal", 20, 5.5);
        new Student("Ravi", 20, 5.5);

        Student.ShowDataBase();
    }

}