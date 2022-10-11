
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see the Protected Access Modifier and
	we will see how and when to use it.

	
	Protected : The protected access modifer is accessible within and outside
		the package but through inheritance only.

	The protected access modifier can applied on the data member, method and
	constructor. it can't be applied on the class.

	it provide more accessibility than the default modifier.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/* Now we will make Simple class in which we will make a data member of
	and method which will be protected. 
*/

package AnimalTest;

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// we need to make the class public so we can access it in other package.
public class Animal{
	// Here we will make a protected data member and .

	protected String type = "Unknown";

	protected void animal_type(){
		System.out.println("Animal Type: " + type);
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make another subclass of the Animal as Dog.
// and we will override them..

//Note: protected data member or method can only be accessed by sub classes.
// outside the its own package.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Dog extends Animal{

	Dog(){
		// now we will override the type value
		this.type = "Dog"; // accessing the type from subclass
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a Main class in which we will test our Dog and Animal 
// class with it's protected members..

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// Now we will make an instance of the Dog and refer it as Animal
		Animal a = new Dog();
		Animal b = new Animal();

		a.animal_type();
		b.animal_type();  
		// access the protected data member within its own package. 
	
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*
	Output:
	test data: 80                                                                          
	data: 80 
	Note: Copy all the code and reame the file as Animal 
*/