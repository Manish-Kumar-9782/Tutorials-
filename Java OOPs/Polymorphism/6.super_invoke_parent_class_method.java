/*
	In this section we will use the super keyword to inovke the parent class methods.

*/

// Now first we will make a Vehicle, it has some attribute
class Vehicle{

	int wheels = 0;
	String engineType = "None";
	int engineCylinders = 0; 

	// Now if run this vehicle then it will show

	void run(){
		System.out.println("Vehicle is running!");
	}

	// return the vehicle 
	Vehicle get(){return this;}


	// Now here we will make a display method which will display the vehicle information.
	void display(){
		System.out.println("Properties of: "+ this);
		System.out.println("wheels: " + this.wheels);
		System.out.println("engineType: "+ this.engineType);
		System.out.println("engineCylinders: "+ this.engineCylinders);
	}
}


// Now we will inherit the Vehicle and will make a bike.
// Bike will update its attributes by using the super keywrod.
class Bike extends Vehicle{

	int wheels;
	String engineType;
	int engineCylinders;
 
 	// Note here we override the attributes of the Vehicle class attribute.

	Bike(){
		this.wheels = 2;
		this.engineType = "V-type";
		this.engineCylinders = 1;
	}

	// overriding the run method of the Vehicle
	void run(){
		System.out.println("Bike is runnig!");
	}

	// Now here we will override the get method and we will return the bike.
	Bike get(){return this;}


	// Now we will override the display method.
	void display(){
		System.out.println("Properties of: "+ this);
		System.out.println("wheels: " + this.wheels);
		System.out.println("engineType: "+ this.engineType);
		System.out.println("engineCylinders: "+ this.engineCylinders);
		System.out.println("\n");
	}


	void displaySuper(){
		// Now we will call the parent class display method by using the super keyword.
		super.display();
	}
}




// now we will test this overriden methods.

class Main{

	public static void main(String[] args) {
		

		// Now we will make a new bike
		Bike bike1 = new Bike();
		bike1.display();		// this will show the bike properties
		bike1.displaySuper(); 		// this will show the bike immediate parent class properties.
	}
}

/*
	OutPut:
		Properties of: Bike@452b3a41                                                           
		wheels: 2                                                                              
		engineType: V-type                                                                     
		engineCylinders: 1                                                                     
		                                                                                       
		                                                                                       
		Properties of: Bike@452b3a41                                                           
		wheels: 0                                                                              
		engineType: None                                                                       
		engineCylinders: 0      
	
	As you can see that we have access attributes from both class after overriding the Vehicle
	class attribute in Bike class. they act like completly different attribute with super keywrod.
*/                                                                       
                      