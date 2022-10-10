
/*-----------------------------------------------------------------------*/

/*
	An interface in Java is a blueprint of a class. it has static constancts 
	and abstrat methods.

	The interface in Java is a mechanasim to achieve abstraction. There can 
	only abstract methods in the java interface, not method body. it is used 
	to achieve abstraction and multiple inheritance in java.

	In other words, you can say that interfaces methods and variables. it cannot
	have a method body.

	* Java interface also represents the IS-A relationship
	* it cannot be instantiated just like the abstract class.
	* Since Java 8, we have default and static method in an interface.
	* Since Java 9, we have private methods in an interface.

	* Note: The Since Java 8, The Java compiler adds public and abstract
	kywords before the interface method. Moreover, it adds public static 
	and final keywords byfore data members.  
*/

// There are mainly three reasons to use interface. 
/*
	* it is used to acieve abstraction.
	* By interface, we can support the functionality of multiple inheritance.
	* It can be used to achieve loose coupling.	
*/

/*-----------------------------------------
	Syntax:

	interface <interface_name>{
	
		// declare constant fields
		// declare methods that abstract.
		// by default
	}
------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make an example of the interface.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// Creating an interface of Printable

interface Printable{

	// by default we will have public and abstract method 
	// so we don't have to explicitly mention them as public and abstract.

	void print(); 
	// Now above method is converted in.
	// abstract public void print();
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make a class in which we will implement our printable interface.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// Class Test 

class Test implements Printable{

	// here we will implement the defination of the Printable method.
	public void print(){
		System.out.println("Hello World!");
	}
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make our Main class in which we will instantiate this.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// here we will make instance of the Test class 

		Test test = new Test();

		// Now we will test it.
		test.print();	
	}
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	OutPut:
		

*/