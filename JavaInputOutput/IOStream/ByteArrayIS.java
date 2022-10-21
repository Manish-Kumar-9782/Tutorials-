import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class ByteArrayIS {

    // first we will make the main method
    public static void main(String[] args) {
        // now we need to make a try and catch block
        try {
            // here we will make an object of the ByteArrayInputstream since this
            // takes a byte array so we will get the byte array form the FileInputStream

            ByteArrayInputStream bais = new ByteArrayInputStream(new FileInputStream("a copy.txt").readAllBytes());

            // Now we will get each byte by using the ByteArrayInputStream.

            int i = 0;

            // reading each byte
            while ((i = bais.read()) != -1) {
                System.out.print((char) i);
            }

        } catch (FileNotFoundException e) {
            System.err.println("FileNotFoundException: unable to read the data..");
        } catch (Exception e) {
            System.err.println("Exception: Undefined exception occurred..");
        }
    }
}
