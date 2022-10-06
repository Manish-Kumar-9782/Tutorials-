public class FirstJavaProgram {

    /*
     * String[] args is the array os string whose values received by using the CLI
     * interface.
     * 
     * for example: java FirstJavaProgram command1 command2 command2 ... commandN
     * 
     * Now our command will be stored in our args array like
     * 
     * args[command1,command2,command2, ... ,commandN]
     */
    public static void main(String[] args) {
        // statements

        // printing the received all additional commands from the CLI
        // Command Line Interface
        print_array(args);

    }

    /*
     * A static function to print a String type array.
     */
    static void print_array(String[] arr) {

        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }

}
