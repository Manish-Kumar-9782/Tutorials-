/*
	In this section we will see that how to use instanceof operator to 
	perform the Downcasting.

	Downcasting: When subclass type refers to the object of parent class, it is known
		as downcasting. if we perform it directly, compiler gives compilation error.

		if you perform it by typecasting, ClassCastException is thorwn at runtime.
		but if we use instanceof operator, downcasting is possible

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
class Dog extends Animal{

	// In this we will perform the Downcasting Operation.
	// To perfrom the Downcasting we need to make ta static method so 
	// we can call it without making its instance.

	static void method(Animal a){

		if (a instanceof Dog){
			Dog d = (Dog)a;
		}
	}


}  // Now Dog instance will be instance of Dog as well as Animal.
 
class Main{

	public static void main(String[] args) {
		
		// if we create a new instance of Animal and refer it by Dog this will
		// lead to the downcasting operation which will give us compile time error.

		// Now here we will perform the downcasting by using the method
		Animal a = new Dog(); 
		// here a new dog is refered as Animal we need to downcast it.

		// call Dog.method(a)
		Dog.method(a); // this will downcast the a from animal to dog.

	}
}

/*
	Output:
	
	Note: in this we will not get any compileation error or runtime error.

	Note: Here we are refering a parent class instance by using the child class instance
	this will lead to the downcasting which cant be done implicitly.
*/