/*
	In this section we will see the instance initializer block.

	Initializer block: instance initializer block is used to initialize.

	Note: The initializer block copied in the constructor and during creation
	of the instance it will be called from the constructor.
*/

/*

Rules of the initializer block:
	
	1. The instance initializer block is created when instance of the class is created.
	2. The instance initializer block is invoked after the parent class constructor
		is invoked.
	3. The instance initializer block comes in the order in which they appear.
*/

class One {

	One() {

		System.out.println("One class constructor is calls");
	}

	// Here we will make an initializer block
	{
		System.out.println("This is initializer block inside the One!");
	}
}

class Two extends One {

	Two() {
		super(); // calling the One class constructor.

		System.out.println("Two class constructor is called");
	}
	// Now here we will outside the constructor we will make the initializer block.

	{
		System.out.println("This is initializer block inside Two!");
	}
}

// Now we will make the Main class

class Main {

	public static void main(String[] args) {

		// Here we will make the class Two method.
		Two two = new Two();
	}
}

/*
 * 
 * Output:
 * This is initializer block inside the One!
 * One class constructor is calls
 * This is initializer block inside Two!
 * Two class constructor is called
 * 
 * Note: Process of the above output
 * 1. initializer block is copied inside the constructor at the top of all the
 * statement.
 * 2. One class print statement is executed after executing the initializer
 * block
 */