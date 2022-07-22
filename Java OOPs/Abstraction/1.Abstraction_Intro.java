/*	
	In this section we will learn what is abstraction and what are abstract classe
	in java.

	Abstraction: abstraction is a process of hiding the implementation details and showing
	only funcionality to the user.

	In Another Word, it shows only essential things to the user and hides the internal details, 
	for example, sending SMS, where you type the text and send the message. You don't know the internal
	processing about the message delivery.

*/

/*
	Abstract Class: A class which is declared with the abstract keyword in known
	 as an abstract class in Java. It can have abstract and non-abstract methods.
	 (method with the body).


	 A class which is declared as abstract is known as an abstract class. 
	 it can have abstract and non-abstract methods. it need to be extended and its method implemented. 
	 it cannot be instantiated.
*/


/*
	Pointes to Remember:
		1. An abstract class must be declared with an abstract keyword.
		2. it can have abstract and non-abstract methods.
		3. it cannot be instantiate.
		4. it can have constructors and static methods also.
		5. it can have methods which will force the subclass 
			not to change the body of the method.
*/

/*-----------------------------------------------------------------------*/

// Example of the abstract class and methods.

// Creating a abstract class by using the abstract keywrod.

abstract class Bike{

	/* Now this class is an abstract class now this class can have abstract 
		and non-abstract methods.
	*/

	void speedup();   	// non-abstract method.
	abstract void run(); // abstract method.
}

/*-----------------------------------------------------------------------*/

// Now we will extend this class in the HondaBike class.

class HondaBike extends Bike{

	/* Now this class inherit the all the abstract and non-abstract methods.

		Note: abstract method must be defined in the child class, so we need to 
		define the run method in this class.

		Note: speedup(), is non-abstract method so we don't need to define here
			we can use the parent class defination in our class, if we want or we 
			can override it.
		*/

	void run(){System.out.println("running Honda Bike Safely!");}
} 

/*-----------------------------------------------------------------------*/

// Now we will make make an instance of the HondaBike.
// And also we will try to make an instance of the abstract class.

class Main{

	public static void main(String[] args) {
		
		// Now here we will make the instance of the HondaBike

	 	HondaBike hbike = new HondaBike();
	 	// we are able to mke the hondabike instance.

	 	hbike.run();  // hbike can access the run method 


	 	// now if we want ot create an instance of the Bike method then it will give
	 	// compile time error.

	 	Bike new_bike = new Bike();
	}
}


/*-----------------------------------------------------------------------*/

/*
	Output:
	cannot be instantiated           
        Bike new_bike = new Bike();

	Note: we can not instantiated the abstract clas.                                         
*/