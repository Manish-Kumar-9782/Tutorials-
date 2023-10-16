class Employee extends Student {

    private int id;
    private double salary;
    private String post;

    Employee(String name, int age, double height,String subject,
             int empId, double salary, String post) {

        super(name, age, height, 0, subject, null);

        this.id= empId;
        this.salary = salary;
        this.post = post;

        System.out.println("Employee Constructor is called...");
    }
}
