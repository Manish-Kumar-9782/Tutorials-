import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.SequenceInputStream;

/*
 * In this section we will learn about the SequenceInputStreams, in which we will read 
 * two different InputStreams in a sequence. 
 */
public class SequenceIS {

    // first we will make a try and catch block

    public static void main(String[] args) {
        try {
            // first we will make tow input streams

            FileInputStream fin1 = new FileInputStream("testE.txt");
            FileInputStream fin2 = new FileInputStream("testE1.txt");

            // Now we will make a SequenceInputStream
            SequenceInputStream sin = new SequenceInputStream(fin1, fin2);

            // now we will read data from the SequenceInputStream\
            int i = 0;

            while ((i = sin.read()) != -1) {
                System.out.print((char) i);
            }

            // after reading all data we need to close the input streams
            sin.close();
            fin1.close();
            fin2.close();

        } catch (FileNotFoundException e1) {
            System.err.println("FileNotFoundException: Unable to read the file");
        } catch (Exception e) {
            System.err.println("Exception: undefined exception..");
        }
    }

}
