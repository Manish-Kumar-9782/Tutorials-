/*
	In this section we will see that how runtime polymorphism is achieved by 
	overriding the method.

	In this section we will override the method by changing the return type.
*/

class Vehicle {

	// Now if run this vehicle then it will show

	void run() {
		System.out.println("Vehicle is running!");
	}

	// return the vehicle
	Vehicle get() {
		return this;
	}
}

// Now we will inherit the Vehicle and override the run method.

class Bike extends Vehicle {

	// overriding the run method of the Vehicle
	void run() {
		System.out.println("Bike is running!");
	}

	// Now here we will override the get method and we will return the bike.
	Bike get() {
		return this;
	}
}

// now we will test this overridden methods.

class Main {

	public static void main(String[] args) {

		// first we will run the vehicle

		Vehicle vh1 = new Vehicle();
		System.out.println("this is: " + vh1.get());

		// Now we will run the bike
		Bike bike1 = new Bike();
		System.out.println("this is: " + bike1.get());
	}
}

/*
 * OutPut:
 * this is: Vehicle@30f39991
 * this is: Bike@4a574795
 * 
 * As you can see that we have overridden the get method to get the current
 * class
 * object.
 * 
 * Note: To explicitly return the current class data type then we need to use
 * the Covariant type of avoid the
 * improper casting in multilevel inheritance.
 * 
 * 
 * Note: In this Program we don't need to do explicit typecasting is needed as
 * the return type. Since we are not using the explicit typecasting there would
 * be no confusion regarding the return type of the methods.
 */
