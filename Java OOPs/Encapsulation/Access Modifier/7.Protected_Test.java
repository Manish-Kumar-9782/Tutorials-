
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will test the protected data member which
	are defined in other package. 

	Protected : The protected access modifer is accessible within and outside
		the package but through inheritance only.

	The protected access modifier can applied on the data member, method and
	constructor. it can't be applied on the class.

	it provide more accessibility than the default modifier.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


import AnimalTest.Animal;
// import AnimalTest.Dog;

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// here we will extend the imported Animal class in Cat class
class Cat extends Animal{

	Cat(){
		// now we will override the type value
		this.type = "Cat"; // accessing the type from subclass
	}

	void own_animal_type(){
		System.out.println("Animal type: " + this.type);
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a Main class in which we will test our Dog, Cat and  
// Animal class with it's protected members..

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// Now we will make an instance of the Dog and refer it as Animal
		
		/*------------------------------------*/
		// Animal animal = new Animal();  
		// Animal dog = new Dog();
		// Animal cat = new Cat();

		// animal.animal_type();
		// dog.animal_type();
		// cat.animal_type();  
		/*------------------------------------*/
		// if we uncomment the above line they cause error
		// because they are accessing the protected data member.

		Cat own_cat  = new Cat();

		own_cat.own_animal_type();
		// access the protected data member within outside the its package. 
	
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*
	Output if we uncomment the commented statements:
	Dog is not public in AnimalTest; cannot be accessed from outside package                                                                     
                Animal dog = new Dog();                                                
                                 ^                                                     
	7.Protected_Test.java:54: error: animal_type() has protected access in Animal          
	                animal.animal_type();                                                  
	                      ^                                                                
	7.Protected_Test.java:55: error: animal_type() has protected access in Animal          
	                dog.animal_type();                                                     
	                   ^                                                                   
	7.Protected_Test.java:56: error: animal_type() has protected access in Animal          
	                cat.animal_type();
	

	OutPut:
	Animal type: Cat 


	Note: We can see that we can access the protected member within its own
	package, outside the package we cannot access them directly. for that we 
	need make a subclass or use another its subclass.   
*/