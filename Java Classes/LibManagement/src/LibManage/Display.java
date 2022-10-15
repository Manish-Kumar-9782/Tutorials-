package LibManage;

public class Display {
    static void printSep(int len) {
        for (int i = 0; i < len; i++) {
            System.out.print("-");
        }
        System.out.print("\n");
    }

    static void clScreen() {
        /*
         * ANSI Code
         * \033[H: It moves the cursor at the top left corner of the screen or console.
         * \033[2J: It clears the screen from the cursor to the end of the screen.
         */
        System.out.print("\033[H\033[2J");
        System.out.flush(); // to reset the cursor position at the top of the console screen
    }

    static void sectionHeading(String str){
        System.out.println(String.format("%40s %s", " ", str));
    }
}
