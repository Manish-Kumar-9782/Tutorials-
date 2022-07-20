/*
	In this section we will see that how to use instanceof operator.

	instanceof operator: it is used ot test whether the object is an instance of the specified
	type (class or subclass or interface).


	The instanceof in java is also known as type comarison operator because it compares
	the instance with type. 

	it return either true or false. if we apply the instanceof operator with any variable that 
	has null value, it return false.
*/

// Now first we will make Animal class

class Animal{} // Animal class

// inherit the Animal class in the Dog class
class Dog extends Animal{}  // Now Dog instance will be instance of Dog as well as Animal.
 
class Main{

	public static void main(String[] args) {
		
		// Now we will  make Dog and Cat instance.

		Animal dog1 = new Dog();
		Dog dog2 = new Dog();

		// Now we test their classes.

		System.out.print("is dog1 instance of Dog: " );
		System.out.println(dog1 instanceof Dog);
		System.out.print("is dog1 instance of Animal: ");
		System.out.println(dog1 instanceof Animal);
		System.out.print("is dog2 instance of Dog: " );
		System.out.println(dog2 instanceof Dog);
		System.out.print("is dog2 instance of Animal: ");
		System.out.println( dog2 instanceof Animal);

	}
}

/*
	Output:
	is dog1 instance of Dog: true                                                          
	is dog1 instance of Animal: true                                                       
	is dog2 instance of Dog: true                                                          
	is dog2 instance of Animal: true   

	Note: Since there is a relation b/w the Dog and Animal thats why we will have the dog 
		as instanceof Dog as well as Animal.

	Note: if there is no relation b/w the two objects then there will be a compile
	time error.  
*/