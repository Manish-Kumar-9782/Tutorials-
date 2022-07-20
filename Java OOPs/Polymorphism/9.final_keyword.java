/*
	In this section we will see that what is final keyword and what is the 
	use of the final keyword.
*/


/*
	Final keyword:
		The final keyword in java is used to restrict the user. The final keyword can be 
		used in many context.

		1. variable
		2. method
		3. class

	* The final keywrod can be applied with the variables, a final variable that
	have no value it is called blank final varaible or uninitialized final variable.

	* It can be initialized in the condtructor only.

	* The blank final varaible can be static also which will be initialized in the 
	static block only.

*/

// Now we will make a Bike class
class Bike{

	// a bike has a speed limit;

	final int speed_limit = 90; // final variable/ constant variable.

	// Now we will run the bike
	void run(){
		// now if we increase the bike speedlimit, compiler will raise the compile time error.

		speed_limit = 120;
	}
}

class Main{

	public static void main(String[] args) {
		
		// here we will make the bike instance
		Bike bike = new Bike();
	}
}

/*

	Output:
	cannot assign a value to final variable speed_limit

	Note: a final value canot be changed after being initialized.	
*/