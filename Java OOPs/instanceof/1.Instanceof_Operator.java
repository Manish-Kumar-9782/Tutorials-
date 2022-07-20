/*
	In this section we will see that how to use instanceof operator.

	instanceof operator: it is used ot test whether the object is an instance of the specified
	type (class or subclass or interface).


	The instanceof in java is also known as type comarison operator because it compares
	the instance with type. 

	it return either true or false. if we apply the instanceof operator with any variable that 
	has null value, it return false.
*/

// Now in this section we will compare two instance.

class Dog{}  // Dog class
 
class Cat{} // Cat class

class Main{

	public static void main(String[] args) {
		
		// Now we will  make Dog and Cat instance.

		Dog dog = new Dog();
		Cat cat = new Cat();

		// Now we test their classes.

		System.out.print("is dog instance of Dog: ");
		System.out.println(dog instanceof Dog);
		System.out.print("is cat instance of Cat: ");
		System.out.println(cat instanceof Cat);
		// System.out.print("is cat instance of Dog: ");
		// System.out.println(cat instanceof Dog);  // error
		// System.out.print("is dog instance of Cat: ");
		// System.out.println(dog instanceof Cat);  // error

	}
}

/*
	Output:
	is dog instance of Dog: true                                                           
	is cat instance of Cat: true

	Note: if there is no relation b/w the two objects then there will be a compile
	time error.  
*/