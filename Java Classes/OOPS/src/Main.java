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

        // Hierarchical Inheritance
        Car car = new Car();
        System.out.println("Car: " + car);

        // hyundai car
        HyundaiCar hcar = new HyundaiCar();
        System.out.println("Hyundai car: " + hcar);

        // bmw car
        BMWCar bcar = new BMWCar();
        System.out.println("BMW Car: " + bcar);
    }
}
