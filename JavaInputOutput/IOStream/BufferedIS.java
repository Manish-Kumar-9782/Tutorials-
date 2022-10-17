// package JavaInputOutput.IOStream;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class BufferedIS {

    public static void main(String[] args) {

        // here first we will make the try and catch block
        try {
            // Now here we need to make an instance of the FileInputStream
            FileInputStream fis = new FileInputStream("testE1.txt");

            // Now we will make an instance of the BufferedInputStream
            // Note this will take an InputStream object.
            BufferedInputStream bis = new BufferedInputStream(fis);

            // Now we we will read the file until the end of the file.
            int i = 0;

            while (i != -1) {
                i = bis.read();
                System.out.print((char) i);
            }

            bis.close();
            fis.close();

        } catch (FileNotFoundException e) {
            System.err.println("FileNotFoundException: File is not found..");
        } catch (Exception e) {
            System.err.println("Exception: Some exception occurred.");
        }
    }
}
