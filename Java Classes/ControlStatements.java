import java.util.Scanner;

class CStatements {

    static void if_else_statement(String color) {

        // color: r, g, y for traffic system

        if (color == "green") {
            System.out.println("Signal is Green, You can Go...");
        } else if (color == "red") {
            System.out.println("Signal is red, Please Stop...!");
        } else if (color == "orange") {
            System.out.println("Signal is orange, Please Careful...!");
        } else {
            System.out.println("Traffic System is Failed, Yor are now free to go anywhere");
        }

    }

    static void switch_statment(char ch) {

        switch (ch) {
            case 'r':
                System.out.println("Signal is red, Please Stop...!");
                break;

            case 'g':
                System.out.println("Signal is Green, You can Go...");
                break;

            case 'o':
                System.out.println("Signal is orange, Please Careful...!");
                break;

            default:
                System.out.println("Traffic System is Failed, Yor are now free to go anywhere");
                break;
        }
    }

};

public class ControlStatements {

    public static void main(String[] args) {
        System.out.print("\033[H\033[2J");
        // System.out.flush();
        CStatements.if_else_statement("red");
        CStatements.if_else_statement("green");
        CStatements.if_else_statement("orange");
        CStatements.if_else_statement("blue");

        System.out.println("\n--------------------------------\n");

        CStatements.switch_statment('r');
        CStatements.switch_statment('g');
        CStatements.switch_statment('o');
        CStatements.switch_statment('b');
        CStatements.switch_statment('s');

    }
}
