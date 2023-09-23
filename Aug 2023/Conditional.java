import java.util.Scanner;

public class Conditional {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        while (true) {

            System.out.print("Signal: ");
            String signal = scan.nextLine();

            if (signal.equals("red")) {
                System.out.println("Signal is red please stop: " + signal);
            } else if (signal.equals("green")) {
                System.out.println("Signal is green you can go: " + signal);
            } else if (signal.equals("orange")) {
                System.out.println("Signal is orange please slow down: " + signal);
            } else {
                System.out.println("Traffic System is failed..");
                break;
            }

            System.out.println("============================================");
        }

    }
}
