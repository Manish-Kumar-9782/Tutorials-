/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that  what are java pacakage and
	why are they useful.

	In this section we will see that how to create a java package and compile
	and run it.
	
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


// A simple Example of the Java package

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// To create a pakcage we need to follow below sytax;

/*------------------------------
syntax: package <<package name>>;
--------------------------------*/

package mypackage;

// Now we will make a simple class which will be public 
//so we can access from another file.
class Main{
	
	public static void main(String args[]){

		System.out.println("Hello to mypackage");
	
	}
}

// Now we need to compile this package and run this package.

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*--------------------------------------
compile command:

:compile package ---> javac -d <directory> <javafilename>
:run package -------> java <package Name>.<class Name>

:-d --> here -d switch specifies the destination where to put the generated 
	class file. 
:<package Name>.<class Name> --> we need to use the fully qualified name of
class to run that particular class.
--------------------------------------*/