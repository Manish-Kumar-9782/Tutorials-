package JavaInputOutput.IOStream;

// package JavaInputOutput.FileIOStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class readbytes {
    // here we will use a function to read a all character form the file.
    static void readFile() {
        try {
            FileInputStream fin = new FileInputStream("testE.txt");
            int i = 0;

            // read the bytes until don't read at the end of the file.
            while (i != -1) {
                i = fin.read();
                System.out.print((char) i);
            }

            fin.close();

        } catch (FileNotFoundException e) {
            System.err.println("FileNotFoundException: File Not found can't read any data...``");
        } catch (Exception e) {
            System.err.println("Exception: exception occurred...");
        }
    }

    public static void main(String[] args) {

        // Note here we need to use the exception handling like output stream. otherwise
        // it will

        try {
            FileInputStream fin = new FileInputStream("testE.txt");
            int i = fin.read();

            System.out.println((char) i); // reading a single byte

            fin.close(); // closing the fin stream object

        } catch (Exception e) {
            // Exception will catch all kind of exceptions.
            System.err.println("Error: File reading error.");
        }

        // read all bytes

        System.out.println("Reading all bytes form file..");
        readFile();

    }
}
