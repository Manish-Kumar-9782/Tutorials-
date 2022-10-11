/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see a default method in an interface.
	We will see how to define and declare it in an interface and how to 
	use it in another interface or in a class.

	Note: Since Java 8, we can have method body in interface. But we need 
	to make it default method.

*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/* Now we will make an interface in which we will define a body of a method
and we will make it default.
*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// printable interface 
interface Printable{  
	void print();

	default void message(){
		System.out.println("This is default message!");
	}  
}  



/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will implement the Printable interface in a class

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Test implements Printable{

	// Now here we will implement/define both interface methods.
	public void print(){
		System.out.println("Hello World!");
	}

}


/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


// Now we will make an instance of this Test class and we will
// refer it by Printable interface.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// Here we will make our instance of Test

		Printable test = new Test();

		test.print();
		test.message();
	
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*
	OutPut:
	Hello World!                                                                           
	This is default message!                                                               
                                                                                                  
     
    Note: As we can see that we have accessed both print and default method
    from the test instance.

    Conclusion: We can define a default method and all the child interface 
    implemented class can access it. We can also override it and define our
    own implementation for that default method.
*/