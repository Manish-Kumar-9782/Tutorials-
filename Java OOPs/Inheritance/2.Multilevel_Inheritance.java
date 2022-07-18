/*
 	In this section we will see that how to make and use the multilevel inheritance.


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
	int height;
	int width;
	int color;

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

	void properties(){

		System.out.println("legs: "+ this.legs);
		System.out.println("Eyes: "+ this.eyes);
	}

}

class Birds extends Animal{

	int primaryFeathers;
	int secondryFeathers; 
	int coverts;

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

// =============================================================//
// Now we will make Dog and Cat which will inherit the Mammals class
class Dog extends Mammals{

	// Now Dog will have the all attributes and metods of Mammals.
	int guard;
	boolean loyal;


	// addition method.

	void bark(){
		System.out.println("Dogs Barks!");
	}

	void walk(){
		this.move("dog is walking!");
	}

	void run(){
		this.move("dog is running!");
	}

	void properties(){

		// System.out.println("fear: " + this.fearfullness);
		// System.out.println("wild: "+ this.wildness);
		// System.out.println("playfull: "+ this.playfullness);
		System.out.println("legs: " + this.legs);
		System.out.println("eyes: "+ this.eyes);
		
	}

}

class Cat extends Mammals{

	int fearfullness;
	int playfullness;
	int wildness;

	Cat(){

		this.fearfullness = 7;
		this.playfullness= 9;
		this.wildness = 8;
	}

	void moew(){
		System.out.println("Cat is mowing!");
	} 

	void walk(){
		this.move("cat is walking!");
	}

	void run(){
		this.move("cat is running!");
	}

	void properties(){

		System.out.println("fear: " + this.fearfullness);
		System.out.println("wild: "+ this.wildness);
		System.out.println("playfull: "+ this.playfullness);
		System.out.println("legs: " + this.legs);
		System.out.println("eyes: "+ this.eyes);
		
	}
}

//================================================================= //

// Now we will make a carrot and pegion class

class Pegion extends Birds{

	int fearfullness;
	int humble;
	int friendly;
	boolean vagitarian;

	Pegion(){

		this.fearfullness = 4;
		this.humble  = 8;
		this.friendly = 8;
		this.vagitarian = true;
	}

	void walk(){
		this.move("Pegion is walking");
	}

	void fly(){
		this.move("Pegion is flying");
	}

	void properties(){

		System.out.println("fear: " + this.fearfullness);
		System.out.println("wild: "+ this.humble);
		System.out.println("friendly: "+ this.friendly);
		this.properties();
	}
}


class Peacock extends Birds{

	int fearfullness;
	int humble;
	int friendly;
	boolean vagitarian;

	Peacock(){

		this.fearfullness = 6;
		this.humble  = 6;
		this.friendly = 7;
		this.vagitarian = false;
	}

	void walk(){
		this.move("Peacock is walking");
	}

	void fly(){
		this.move("Peacock is flying");
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

		// Now we will make Dog and Cats instance.

		Dog dog1 = new Dog();
		Cat cat1 = new Cat();

		dog1.walk();
		dog1.properties();

		cat1.walk();
		cat1.properties();



		
	}
}

/*
 OutPut:
 	dog is walking!                                                                        
	legs: 4                                                                                
	eyes: 2                                                                                
	cat is walking!                                                                        
	fear: 7                                                                                
	wild: 8                                                                                
	playfull: 9                                                                            
	legs: 4                                                                                
	eyes: 2    

	Note: as you can see that both the mammals have all the accessible attributes and method.
	and also they have their own mehtods and attributes.
*/