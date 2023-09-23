public class Pattern {

    public static void main(String[] args) {

        // outer loop to handle each row
        for (int i = 0; i < 10; i++) {

            // inner loop to handle each column
            for (int j = 0; j < i; j++) {
                System.out.print(j);
            }
            System.out.print("\n");
        }

    }
}
