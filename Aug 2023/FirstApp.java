import java.util.Scanner;

public class FirstApp {

    public static void main(String args[]) {

        Scanner scan = new Scanner(System.in);

        System.out.println("Enter you name: ");
        String name = scan.nextLine();

        System.out.print("Enter a number: ");
        int number = scan.nextInt();

        System.out.print("Enter a float value: ");
        float height = scan.nextFloat();

        System.out.println("Enter a pi value: ");
        double PI = scan.nextDouble();

        System.out.println("================================================================");
        System.out.println("Your Number is: " + number);
        System.out.println("Your height is: " + height);
        System.out.println("Your PI Value is: " + PI);
        System.out.println("Your Name is: " + name);

    }
}