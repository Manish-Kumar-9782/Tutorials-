/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how to implement the multiple
	inheritance, by using the multiple interfaces.

	In this section we will make two interface which will be implemented
	by other class together.
*/

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make An interface

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Drawable interface

interface Drawable{

	// all the methods are public and abstract by default.
	void draw();
	// it's implementation in each class will be different.
} 

interface Colorable{
	void color();
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make a circle class and we will implement
// both interface Drawable and Colorable.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// Circle class

class Circle implements Drawable, Colorable{

	public void draw(){
		System.out.println("Drawing Circle!");
	}

	// Now here we will Change the color
	public void color(){
		System.out.println("Drawing red Circle");
	}

}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make a Rectangle class and we will implement
// both interface Drawable and Colorable.
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Rectangle implements Drawable, Colorable{

	public void draw(){
		System.out.println("Drawing Rectangle!");
	}

	// Now here we will Change the color
	public void color(){
		System.out.println("Drawing Green Circle");
	}

}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make the Main class and we will test both classes implementation of draw.

class Main{
	
	public static void main(String args[]){

		// creating the instance of circle.
		Circle circle = new Circle();
		// creating the instance of rectangle.
		Rectangle rect = new Rectangle();

		// Now we will test their implementation of draw method.

		circle.draw();
		circle.color();

		System.out.println("\n");
		rect.draw();
		rect.color();
	
	}
}

/*-----------------------------------------------------------------------*/

/*
	Output:
	Drawing Circle!                                                                        
	Drawing red Circle                                                                     
	                                                                                       
	                                                                                       
	Drawing Rectangle!                                                                     
	Drawing Green Circle 


	Note: Multiple inheritance is not supported through class in java, but
	it is possible by an interface, this difference is done by ambiguity of
	having the same function with two different implementation.

	Through interface there is no ambiguity, because its implementation is provided
	by the implementation class. 
*/