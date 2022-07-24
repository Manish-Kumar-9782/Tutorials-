/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how to use the javadoc
	tool to create the documentation. 

	Documentation: we can create document api in java by the heip of
	javadoc tool. In the java file, we must use the documentation comment
	to post information for the calss, method, constructor, fields etc. 

	Note: to create a documentation public or protected method or class or 
	interface should me mentioned.	
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will create a class in which we will make a simple document.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
public class Javadoc_Tool{
	// Now here we will create the docs

	/** This is the documentation Syntax in this block of we can write
	 the documentation about any pakcaage, file, class, method, constructor.

	 We can define the alogirthm process, application, purpose etc.*/

	 // Now we will make method and will make a doc for that.

	 /** This method takes a and b argument as integer and print their 
	  addition */

	 public static void add(int a, int b){
	 	System.out.println(a+b);
	 }
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


// Note run: javadoc TestDocTool.java to create the documentation 
// on the command line (terminal).