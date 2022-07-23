/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how to access a package which
	is already defined and compiled in other file.

	There are three way to access the package from outside the package.

		1. import package.*;
		2. import package.classname;
		3. full qualified
	
*/

/*
	Java Pakcage:

		A Java package is group of similar types of classes, interfaces
		and subpackages.

		Package in java can be categroized in tow form, buit-in package
		and user-defined package.

	Advantage of Java Package:

		1. Java package is used to categorize the classes and interfaces so
		that they can be easily maintained.

		2. Java package provides access protecton.

		3. Java package removes naming collision.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

package mypackage;

/*--------------------------------------------*/
	/* Now we will import the package built in package by using all 
	three method.*/

// first we will import all util
import java.lang.*; // now we have imported all util class, interface.
import java.text.NumberFormat; // now we have imported the NumberFormat.

// Note we will use the Testpack package by using fully qualified name
// for that we don't need to import it.
/*-------------------------------------------*/


// A simple Example of the Java package

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// To create a pakcage we need to follow below sytax;

/*------------------------------
syntax: package <<package name>>;
--------------------------------*/



// Now we will make a simple class which will be public 
//so we can access from another file.
class Main{
	
	public static void main(String args[]){

		System.out.println("Hello to mypackage");

		System.out.println("Accessing the util package classes.");

		// Math class has static method.
		System.out.println("power of 2^5 "+ Math.pow(2,5));

		System.out.println("Accessing NumberFormat");
		NumberFormat Formatting = NumberFormat.getCurrencyInstance(java.util.Locale.US);
		// Note her we have used a full qualified name to use US
		// as java.util.Locale.US
		System.out.println("Currancy: " + Formatting.format(100000));

	
	}
}

// Now we need to compile this package and run this package.

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*
	Output:
	Hello to mypackage                                                                       
	Accessing the util package classes.                                                      
	power of 2^5 32.0                                                                        
	Accessing NumberFormat                                                                   
	Currancy: $100,000.00  

	Conclusion:
	1. first we import all classes, interface and subpackage from the java.lang
		and we use Math class from that.

	2. second we just import a particular class called NumberFormat to fromatting
		the number, in this other classes from java.text package are not imported.

	3. Third We have used the fully qualified name to use the Locale.US by using
	'java.util.Locale.US'	
*/


/*--------------------------------------
compile command:

:compile package ---> javac -d <directory> <javafilename>
:run package -------> java <package Name>.<class Name>

:-d --> here -d switch specifies the destination where to put the generated 
	class file. 
:<package Name>.<class Name> --> we need to use the fully qualified name of
class to run that particular class.
--------------------------------------*/