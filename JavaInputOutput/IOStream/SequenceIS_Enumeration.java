import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.SequenceInputStream;
import java.util.Enumeration;
import java.util.Vector;

/*
 * In this section we will create a Enumeration object which will contains n-number of 
 * InputStream object which will be passed to the SequenceInputStream constructor.
 * 
 * by using Enumeration object we can make a sequence of n-number of SequenceInputStream.
 * 
 */

public class SequenceIS_Enumeration {

    public static void main(String[] args) {

        // first we will make the try and catch block

        try {

            // now we will make some File Input stream
            FileInputStream fin1 = new FileInputStream("a copy.txt");
            FileInputStream fin2 = new FileInputStream("a copy 2.txt");
            FileInputStream fin3 = new FileInputStream("a copy 3.txt");
            FileInputStream fin4 = new FileInputStream("a copy 4.txt");

            // Now we need to make an enumeration object in which we will place all
            // FileInputStream object

            /*
             * since we will use the Enumeration<E> interface so we need to use a
             * class which implements the Enumeration<E>
             * 
             * For now we will use the vector class to make the Enumeration object
             * 
             * Note: vector allows us to store the values dynamically.
             */

            // first we will create an object of the vector,
            Vector<FileInputStream> list = new Vector<>();
            // here we need to define the generic type for the vector.
            list.add(fin1);
            list.add(fin2);
            list.add(fin3);
            list.add(fin4);

            // Now we will get the all elements from the vector and store them
            // by using the reference of the Enumeration object.

            // here by defining the type parameter we will will ensure that
            // enum_io will have only FileInputStream only.
            // by using this we won't have to use explicit type casting.
            Enumeration<FileInputStream> enum_io = list.elements();
            // it return an object of Enumeration type

            // Now we will pass this Enumeration type to the SequenceInputStream
            // constructor

            SequenceInputStream sin = new SequenceInputStream(enum_io);

            // Now we will get the each byte form the input stream then we will
            // print each character

            int i = 0;

            while ((i = sin.read()) != -1) {
                System.out.print((char) i);
            }

            // now
            sin.close();

            for (FileInputStream el : list) {
                System.out.println("\nclosing InputStream: " + el);
                el.close();
            }

        } catch (FileNotFoundException e) {
            System.err.println("FileNotFoundException: Unable to read file" + e);
        }

        catch (Exception e) {
            System.err.println("Exception: Undefined error happened" + e);
        }

    }

}
