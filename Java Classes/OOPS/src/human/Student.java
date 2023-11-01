package human;

class Student extends Person {
    private int rollNo;
    private String subject;
    private String section;

    Student(String name, int age, double height, int rollNo, String subject,
            String section){

        super(name,age,height); // running Person constructor
//        super.name;

        this.rollNo  = rollNo;
        this.section = section;
        this.subject = subject;

        System.out.println("Student constructor is called....");
    }

    final void show(){
        System.out.println("person data");
    }

    final void show(String x){
        System.out.println(x + "! \t" + "Perosn Data");
    }
}
