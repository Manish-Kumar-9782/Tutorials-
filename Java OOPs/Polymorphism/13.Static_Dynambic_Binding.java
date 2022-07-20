
/*
	In this section we will learn about the static and dynamic binding.

	1. Static binding (also known as the Early binding);
	2. Dynamic Binding (also known as the Late Binding);


	1. Static Binding: When type of the object is determined at the compiled time (by the compiler), it is known as the static binding.

	2. Dynamic Binding: When type of the object is determined at run-time, it is known as dynamic binding;
*/


// to understand this we will make Animal class
class Animal{
	
	void eat(){
		System.out.println("Animal is eating!");
	}
}


// Now we will make another class which will inherite the Animal class
class Dog extends Animal{

	void eat(){
		System.out.println("Dog is eating!");
	}
}


// Now we will make the Main class

class Main{

	public static void main(String[] args) {
		
		// Now we will make two intance of Dog
		// One refered by animal class and Other is refered as Animal class

		Dog dog1 = new Dog();  // case 1: static binding.
		Animal dog2 = new Dog();  // case 2: dynamic binding.

		dog1.eat();
		dog2.eat();

	}
}

/*
	Case1: In case1 here explicitly defined at compile time that the Dog is an instance of class Dog.
	Case2: In case2 here we didn't defined explicitly at compile time that the Dog is an instance of class Dog or Animal.
		because right now it is an intance of both Animal and Dog classes.

*/