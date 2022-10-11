/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how to define an static
	method in an interface and use it in other classes.

	Note: Since Java 8, we can have static method in interface.

*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/* Now we will make an interface in which we will define a body of a method
and we will make it default.
*/
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// printable interface 
interface Drawable{  
	void draw();

	static int square(int x){return x*x;}
}  



/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will implement the Printable interface in a class

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Test implements Drawable{

	// Now here we will implement/define both interface methods.
	public void draw(){
		System.out.println("Drawing Rectangle!");
	}

}


/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


// Now we will make an instance of this Test class and we will
// refer it by Drawable interface.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// Here we will make our instance of Test

		Drawable test = new Test();

		test.draw();
		
		// Now we will access the static method 
		System.out.println("square of 8: " + Drawable.square(8));
	
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*
	OutPut:
	Drawing Rectangle!                                                                     
	square of 8: 64                                                                      
                                                                                                  
     
    Note: As we can see that we have defiend a static method in an interface
    and used it in our user-defined classes

*/