import java.time.LocalDate;

public class Main {

    public static void main(String[] args) {
//        Person pr = new Person("bhanu", 21, 5.6);
//
//        Student st = new Student("kuldeep", 22, 5.6, 1234,
//                "Hindi", "B1");
//
//        // referring the Student as a Person object
//        System.out.println("Student is also instance of Person: " +
//                (st instanceof Person));
//
//        Person pr_st = new Student("Khursheed", 22, 5.7, 3243,
//                "English", "B2");

//        Employee emp = new Employee("Khursheed", 22, 5.7,
//                "English", 191, 26000, "Developer");
//
//        System.out.println("Employee is also is an instance of Person: " +
//                (emp instanceof Person));

        //============================================================

//        // Hierarchical Inheritance
//        Car car = new Car();
//        System.out.println("Car: " + car);
//
//        // hyundai car
//        HyundaiCar hcar = new HyundaiCar();
//        System.out.println("Hyundai car: " + hcar);
//
//        // bmw car
//        BMWCar bcar = new BMWCar();
//        System.out.println("BMW Car: " + bcar);

        //============================================================

//        PersonX pr = new PersonX(
//                "Bhanu",
//                LocalDate.of(2003,9,24),
//                new Address("plot no 20, vikas colony near station","Dausa","Dausa",
//                        "Rajasthan","Indian",303303),
//                Gender.Male,
//                new AadharNumber("4352-4567-4567") );
//
//        System.out.println("Person: \n" + pr);

        //=============================================================
        // Static method and Data members.

        School.addStudent("kuldeep", 21, 5.5,
                1234, "English", "B2");

        School.addStudent("bhanu", 19, 5.6,
                2341, "Hindi", "B1");

        School.addStudent("kursheed", 22, 5.7,
                1341, "Physics", "B4");

        School.addStudent("Kush", 23, 5.6,
                1321, "Chemistry", "B3");

        System.out.println("Students: " + School.showStudents());

    }
}
