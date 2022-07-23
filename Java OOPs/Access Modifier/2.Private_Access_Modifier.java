
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see about the Private access modifier 
		and we will see that how to use it.


	Private: The private access modifier is accessible only within the class.

	To access a private data member and a method we need to use the public
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
	// This class will have private data member and method.

	private int data = 80;

	private void printdata(){
		System.out.println("private data: " + data);
	}
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

		Test test = new Test();

		System.out.println(test.data); /// it will raise error.
		test.printdata(); // it will raise error.
	
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*
	Output:
	java:55: error: data has private access in Test              
                System.out.println(test.data); /// it will raise error.

	java:56: error: printdata() has private access in Test       
                test.printdata(); // it will raise error.
                
	Note: We cannot access the private data member or method , for that 
	we need to use the public methods.     
*/