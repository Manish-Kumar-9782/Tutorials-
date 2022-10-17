package JavaInputOutput.IOStream;
// package JavaInputOutput.FileOutputStream;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

/*
 * In this section we will write some byte to a file by using the FileOutputStream class
 */

/*
* constructors:
* 
*   public FileOutputStream(String name) throws FileNotFoundException

    public FileOutputStream(String name,boolean append)
                 throws FileNotFoundException

    public FileOutputStream(File file)
                 throws FileNotFoundException

    public FileOutputStream(File file,boolean append)
                 throws FileNotFoundException

    public FileOutputStream(FileDescriptor fdObj)
*/
public class writebyte {

    // static void write_without_Exception() {

    // // Note here we will not use any Exception handling.
    // // Note FileNotFoundException may be raised due to some file output error.
    // // if file is not able to be created or write.

    // // here first we will create an object of the FileOutputStream class object.
    // FileOutputStream fout = new FileOutputStream("test.txt");

    // // Now we will encode our text message into the Bytes by using the getBytes()
    // // method.
    // byte output[] = "Hello world".getBytes();
    // fout.write(output);
    // fout.close();
    // }

    // Note here we need to throws the error as well, other wise we will ge the
    // compile error about exception
    static void write_with_Exception() throws FileNotFoundException {

        // here we will use the exception handling, we will use the try and catch block.

        try {
            FileOutputStream fout = new FileOutputStream("testE.txt");

            // Now we will encode our text message into the Bytes by using the getBytes()
            // method.
            byte output[] = "Hello world with Exception".getBytes();
            fout.write(output);
            fout.close();
        } catch (Exception e) {
            System.err.println(e);
            System.err.println("Error: unable to write the file...!");
        }
    }

    public static void main(String[] args) {
        // write_without_Exception();
        /*
         * unreported exception FileNotFoundException; must be caught
         * or declared to be thrown
         */

        try {
            write_with_Exception();
        } catch (Exception e) {
            System.err.println("Some Exception occured.");
        }
    }
}
