/*
 	In this section we will see that how to use the inheritance 
 	to increase the new class functionality witout making new methods 
 	and attributes.

 	Inheritance: Inheritance is the methodology of the OOPs programming in which
 		we get all the accessible methods and attributes from other class which will
 		be called as the parent class, and new derived class will be called as the child 
 		class. 
 */


// Now we will make the a aniamal class to introduce the top concept of the animal class.

class Animal{

	// In this class we will declare the common properties for all the animals.

	int legs;
	int eyes;
	boolean isFly;
	boolean isWalk;


	// Now we will define a method for action/activity, because all the 
	void move(String action){
		System.out.println(action);
	}

	void eatfood(String action){
		System.out.println(action);
	}
}

// Now we will make two different class for different kind of animal classes.

class Mammals extends Animal{
	// here we have used the extends keyword to inherite the Animal class.
	// Now Mammals have all the attributes and method of the Animal class.

	// Now here we will define the some properites of the Mammals


	Mammals(){
		// Now we will assign the common properties of the Mammals
		this.eyes = 2; 
		this.legs = 4;
		this.isWalk = true;
	}

	// Now Mammals will have the additional methods 

	void walk(){
		this.move("Mammals are walking");
	}

	void run(){
		this.move("Mammals are running");
	}

	void jump(){
		this.move("Mammals are jumping;");
	}

	void eat(){
		this.eatfood("Mammals eats all kind of food which are compatible to their ecosystem.");
	}
}

class Birds extends Animal{


	Birds(){
		// NOw we will assign the common properties of the Birds.
		this.eyes = 2;
		this.legs = 2;
		this.isWalk = true;
		this.isFly = true;
	}

	void fly(){
		this.move("Birds are flying.");
	}

	void walk(){
		this.move("Birds are walking on two legs");
	}

	void eat(){
		this.eatfood("Birds eats insects!");
	}
}

/* Now from the above code we can see that haven't declared any property in the Birds
	and Mammals class but they use them, because both classes inherits the Animals class
	in result they have all the accessible attributes.


	Note: this is an example of simple inheritance and simple hierarchy inheritance.
*/

// Now we will make the Main class and will Make the some instance of Mammals and birs.

class Main{

	public static void main(String args[]){

		// Now we will make a mammals and a birs.

		Mammals mammal1 = new Mammals();
		Birds bird1 = new Birds();


		// Now we will test them

		mammal1.walk();
		mammal1.run();
		mammal1.jump();
		mammal1.eat();

		// Now we will test the bird.
		bird1.walk();
		bird1.fly();
		bird1.eat();
	}
}

/*
 OutPut:
 	Mammals are walking                                                                    
	Mammals are running                                                                    
	Mammals are jumping;                                                                   
	Mammals eats all kind of food which are compatible to their ecosystem.                 
	Birds are walking on two legs                                                          
	Birds are flying.                                                                      
	Birds eats insects!  

	Note: as you can see that both the mammals have all the accessible attributes and method.
	and also they have their own mehtods and attributes.
*/