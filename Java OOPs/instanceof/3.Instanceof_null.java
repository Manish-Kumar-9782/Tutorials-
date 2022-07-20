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
		Dog dog2 = null;

		// Now we test the Dog with the null type.
		System.out.print("is dog2 instanceof : ");
		System.out.println(dog2 instanceof Dog);

	

	}
}

/*
	Output:
	is dog2 instanceof Dog: false     

	Note: Since dog2 has the null value since it does not have any values or instance of the Dog .
	Note: if there is no relation b/w the two objects then there will be a compile
	time error.  
*/