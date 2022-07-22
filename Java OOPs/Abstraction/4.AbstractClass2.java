/*-----------------------------------------------------------------------*/

/* Abstract class: In this section we will see how to make an abstract class with having a 
constructor, data members and methos.

Note: An abstract class can have a data member, abstract method, non-abstract method
	constructor and even main() method.
*/

/*-----------------------------------------------------------------------*/

// Now we will make an abstract class

abstract class Bike{

	// Bike class Constructor
	Bike() {System.out.println("New Bike is created!");}
  
  	// an abstract method to run the Bike
	abstract void run();  

	// A ChnageGear method body  
	void changeGear(){
		System.out.println("Bike Gear is Changed!");
	}
}

/*-----------------------------------------------------------------------*/

// Now we will make a new Honda Bike

class HondaBike extends Bike{

	// Now Here we must defined the run implementation.
	void run(){
		System.out.println("Runnin HondaBike safely!");
	}
}

/*-----------------------------------------------------------------------*/

// Now we will make the Main class which will hold the 

class Main{
	
	public static void main(String args[]){

		// Now we will create a new honda bike

		Bike bike = new HondaBike();

		// now we will run the bike
		bike.run();
		bike.changeGear();
		
	}
}
/*-----------------------------------------------------------------------*/

/*
	Output:
		New Bike is created!                                                                   
		Runnin HondaBike safely!                                                               
		Bike Gear is Changed!

	Note: if you are extending an abstract class that has an abstract method, 
	you must either provide the implementation of the method or make this class 
	abstract.                                                                                           
*/