import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class ByteArrayOS {

    public static void main(String[] args) {

        // first we will make a try and catch block.

        try {
            FileOutputStream fout = new FileOutputStream("a copy.txt");
            FileOutputStream fout2 = new FileOutputStream("a copy 2.txt");

            // Now we will make an ByteArrayOutputStream object
            ByteArrayOutputStream baout = new ByteArrayOutputStream();

            byte data[] = "This data is written by ByteArrayOutputStream".getBytes();

            // Now we need to put this byte array data into the baout stream
            baout.write(data);

            // now we will write the data by using the writeTo method.
            baout.writeTo(fout);
            baout.writeTo(fout2);

            // now we will can flush the baout stream
            baout.flush();
            baout.close(); // closing the baout stream
            fout.close(); // closing the first FileOutputStream
            fout2.close(); // closing the second FileOutputStream

        } catch (FileNotFoundException e) {
            System.err.println("FileNotFoundException: Unable to read the file.");
        } catch (Exception e) {
            System.err.println("Exception: Undefined Exception occurred.");
        }

    }
}