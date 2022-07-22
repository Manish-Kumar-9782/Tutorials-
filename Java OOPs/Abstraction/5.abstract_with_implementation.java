
/*-----------------------------------------------------------------------*/

/*
	The abstract class can also be used to provide some implementation of 
	the interface. In such case, the end user may not be forced to override
	all the methods of the interface.
*/

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
// first of all we will make an interface.

interface A{

	void a();
	void b();
	void c();
	void d();
}
/* Now we have created an interface which has abstract method.
Now we will make an class implementing the interface A*/
/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
// Creating the class B implementing Class A

abstract class B implements A{
	// In this class we will implement only two method of interface A
	public void a(){
		System.out.println("Class B implementation of method a");
	}

	public void c(){
		System.out.println("Class B implementation of method c");
	}
}
/* Note in this class only two methods a, c are implemented remaining
method will be implemented in another class.*/

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
// Now we will make another class C, this will extend the B
// In this class we will implement the method b and d.

class C extends B{

	public void b(){
		System.out.println("Class C implementation of method b");
	}

	public void d(){
		System.out.println("Class C implementation of method d");
	}
}
// Now we have implemented of all the method of interface of A.
// Since interface A methods are abstracted they will be reamin
// abstracted in class A since it is abstracted class as well.
// Now if we exnted the class B in C then we must implement the method.

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
// Now we will make the main class

class Main{
	
	public static void main(String args[]){

		// Now we will make a new  instance of class C and we will 
		// refer it by the interface A.

		A obj = new C();

		// Now we will call all the implemented methods.
		obj.a();
		obj.b();
		obj.c();
		obj.d();

		
	}
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Output:
	Class B implementation of method a                                                     
	Class C implementation of method b                                                     
	Class B implementation of method c                                                     
	Class C implementation of method d 

	Conclusion: as you can see that we have implemented all the abstracted method
	of interface A in two different clas B and class C.

	But we have accessed all the implementation refered by interface A.  
*/