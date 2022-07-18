/*
	In this section we will use the super keywrod to invoke the parent class constructor.

	In this section we will make HondaBike by using the Vehicle and Bike class.

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

	Bike(int wheels, String engineType, int engineCylinders){
		this.wheels = wheels;
		this.engineType = engineType;
		this.engineCylinders = engineCylinders;
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


// Now we will make a new HondaBike from Bike class

class HondaBike extends Bike{

	String color;

	// Now we will make a constructor in from which we will call the Bike class constructor.

	HondaBike(int wheels, String engineType, int engineCylinders,String color){
		super(wheels, engineType, engineCylinders);  // invoking the immediate parent class (Bike) constructor 
		this.color = color;
	}

	void display(){
		System.out.println("Properties of: "+ this);
		System.out.println("wheels: " + this.wheels);
		System.out.println("engineType: "+ this.engineType);
		System.out.println("engineCylinders: "+ this.engineCylinders);
		System.out.println("color: "+ this.color);
		System.out.println("\n");
	}

}



// now we will test this overriden methods.

class Main{

	public static void main(String[] args) {
		

		// Now we will make a new bike
		HondaBike bike1 = new HondaBike(2,"v-cylinder",1,"black");
		bike1.display();		// this will show the HondaBike properties

	}
}

/*
	OutPut:
		Properties of: HondaBike@4a574795                                                      
		wheels: 2                                                                              
		engineType: v-cylinder                                                                       
		engineCylinders: 1                                                                     
		color: black      
	
	As you can see that from the output we can clearly see that from HodaBike class
	we have invoked the constructor of the Bike class by using the super keyword and assigned the
	Bike attributes.
*/                                                                       
                      