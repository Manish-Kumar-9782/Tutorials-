import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

// package JavaInputOutput.IOStream;

public class BufferedOS {

    public static void main(String[] args) {

        try {
            // first we will make an instance of the FileOutputStream

            FileOutputStream fout = new FileOutputStream("testE1.txt");

            // Now we will make one instance for the BufferedOutputStream
            // Note: this BufferedOutputStream constructor will take the instance
            // OutputStream instance
            BufferedOutputStream bout = new BufferedOutputStream(fout);

            // Now we will make a string object and convert it into the bytes array.

            byte b[] = "Hello this is BufferedOutputStream test".getBytes();

            // now we need to pass this byte array to the write method of bout.
            bout.write(b);

            // now we need to flush and close the bout
            bout.close();

            // Now we also need to close the fout stream
            fout.close();
        } catch (FileNotFoundException e) {
            System.err.println("FileNotFoundException: unable to write the data.");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
