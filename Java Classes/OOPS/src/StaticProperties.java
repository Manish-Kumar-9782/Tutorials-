
class StudentX{
    private String name;
    private int age;
    private double height;
    private int rollNo;
    private String subject;
    private String section;


    public StudentX(String name, int age, double height, int rollNo, String subject,
            String section){
        this.name = name;
        this.age = age;
        this.height = height;
        this.rollNo  = rollNo;
        this.section = section;
        this.subject = subject;
    }

    public String toString(){
            return "Student {"
                    + "name: " + this.name + ", "
                    + "age: " + this.age + ", "
                    + "height: " + this.height + ", "
                    + "rollNo: " + this.rollNo + ", "
                    + "subject: " + this.subject+ ", "
                    + "section: " + this.section
                    +"}";
    }
}

// =====================

class School {

    static StudentX students[] =  new StudentX[10];
    static int count = 0;
    private String schoolName;

    School(String name){
        this.schoolName = name;
    }

    static void addStudent(String name, int age, double height, int rollNo, String subject,
                           String section){

        StudentX st = new StudentX(name, age, height, rollNo, subject, section);
        students[count++] = st;
    }

    static String showStudents(){

        String str = "";

        for(int i=0; i<School.count; i++){
            StudentX st = School.students[i];
            str += st + "\n";
        }
        str = "[\n" + str + "]";

        return str;
    }
}
