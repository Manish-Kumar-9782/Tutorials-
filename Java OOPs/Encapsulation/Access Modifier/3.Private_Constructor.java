
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how to make restriction 
		on creating an instance on an class. 

	
	Private Constructor: if we make a constructor as private then it will
	not create any instance outside the class. we need to create all the
	instance inside the class and we need to access them with that class
	method.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/* Now we will make Simple class in which we will make a data member of
	and method which will be private. 
*/

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Test{
	// Here we will make a private constructor.

	private Test(){}; // private constructor.
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a Main class in which we will test our Test class
// with it'r private data member and method.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// Now we will make an instance of the Test class

		Test test = new Test(); // raise an error.
	
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*
	Output:
	java:47: error: Test() has private access in Test                
                Test test = new Test(); // raise an error. 
	
	Note: We cannot access the private data member or method or Constructor, 
	for that we need to use the public methods.     
*/