import  java.util.InputMismatchException;
class Person_x{
    private String name;

    Person_x(String name){
        this.setName(name);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {

        if (name.length() <= 3){
            throw new InputMismatchException("Value is too short...");
        }
        else if(name.length() >=30){
            throw new InputMismatchException("Value is too long...");
        }

        this.name = name;
    }

}


class ExceptionHandling {

    static double division(double a, double b){

        if(b==0){
            throw new ArithmeticException("Division by zero");
        }
        return a/b;
    }

    public static void main(String[] args) {


        int a = 20;
        int b = 10;

        try{
            double x = division(a,b);
            System.out.println("result: " + x);

//            Person_x pr = new Person_x("hello my name is kuldeep and i am a student");
            Person_x pr = new Person_x("Kuldeep Singh");

            System.out.println("new Person: " + pr.getName());
        }
        catch (ArithmeticException e){
            System.out.println("Arithmetic Error: "+ e.getMessage());
        }
        catch (InputMismatchException e){
            System.out.println("ValueError: " + e.getMessage());
        }
        catch (Exception e){
            System.out.println("UnknownException:");
            e.printStackTrace();
        }
        finally {
            System.out.println("===================================");
            System.out.println("\nProgram has been ended.\n");
            System.out.println("===================================");
        }

    }
}
