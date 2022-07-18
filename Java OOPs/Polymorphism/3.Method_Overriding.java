/*
	In this section we will see that how runtime polymorphism is achieved by 
	overriding the method.
*/

class Vehicle{

	// Now if run this vehicle then it will show

	void run(){
		System.out.println("Vehicle is running!");
	}
}


// Now we will inherit the Vehicle and override the run method.

class Bike extends Vehicle{

	// overriding the run method of the Vehicle
	void run(){
		System.out.println("Bike is runnig!");
	}
}


// now we will test this overriden methods.

class Main{

	public static void main(String[] args) {
		
		//first we will run the vehicle

		Vehicle vh1 = new Vehicle();
		vh1.run();

		// Now we will run the bike
		Bike bike1 = new Bike();
		bike1.run();
	}
}

/*
	OutPut:
		Vehicle is running!                                                                    
		Bike is runnig!
	
	As you can see that we have overriden the run method to run the bike.
*/                                                                       
                      