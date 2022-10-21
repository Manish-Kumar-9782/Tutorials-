package projects.LibManagement;

class Display {

    static private char escCode = 0x1B;
    static private int lineNumber = 0;

    static void printSeprator(int num) {
        for (int i = 0; i < num; i++) {
            System.out.print("-");
        }
    }

}

public class Utilities {
    public static void main(String[] args) {

    }
}
