/*
 * IS-A relationship (inheritance)
 * 
 * HAS-A relationship (aggregation)
 * 
 * super keyword
 */

class Address {

    int plot_no;
    String street;
    String town;
    String city;
    String state;
    String country;
    int pincode;

    Address(int pn, String street, String town, String city, String state, String country, int pincode) {
        this.plot_no = pn;
        this.street = street;
        this.town = town;
        this.city = city;
        this.state = state;
        this.country = country;
        this.pincode = pincode;
    }

    void display() {
        System.out.println(this.plot_no + ", " + this.street
                + ", " + this.town + ", " + this.city + ", " + this.state + ", " + this.country + ", " + this.pincode);
    }
}

class Student {

    String name;
    int age;
    double height;
    Address addrs; /* HAS-A relationship */

    Student(String name, int age, double height, Address address) {
        this.name = name;
        this.age = age;
        this.height = height;
        this.addrs = address;
    }

    void display() {

        // %[flag][width][type]
        System.out.println(String.format("%-15s: %-15s", "Name", this.name));
        System.out.println(String.format("%-15s: %-15s", "Age", this.age));
        System.out.println(String.format("%-15s: %-15s", "Height", this.height));
    }
}

class Employee extends Student {
    /* IS-A relationship */
    int empId;
    int salary;
    String department;

    Employee(String name, int age, double height,
            int empid, int salary, String department,
            Address address) {

        // super keyword
        super(name, age, height, address);
        this.empId = empid;
        this.salary = salary;
        this.department = department;
    }

    @Override
    void display() {
        super.display();
        System.out.println(String.format("%-15s: %-15s", "EmpId", this.empId));
        System.out.println(String.format("%-15s: %-15s", "Salary", this.salary));
        System.out.println(String.format("%-15s: %-15s", "Department", this.department));
    }
}

public class InheritanceIntro2 {

    public static void main(String[] args) {

        Address addrs = new Address(21, "gopalpura road", "gopalpura", "Jaipur", "Rajasthan", "India", 302030);
        Employee emp = new Employee("Yatharth", 26, 5.6, 1001, 30000, "Developer", addrs);
        System.out.println("\n------------------------------------------\n");
        emp.display();
        emp.addrs.display();
        System.out.println("\n------------------------------------------\n");

    }
}