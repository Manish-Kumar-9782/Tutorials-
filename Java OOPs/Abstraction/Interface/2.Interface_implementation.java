/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	In this section we will see that how to use the interface in two different
	class and they can have their own implementation of abstracted method of 
	interface according to their own functionality.

	--> In this section we will make a Drawable interface.
	--> This Drawable interface will be implemented by another classes.
	--> In this we will make Circle and Rectangle class and we will
		implement the interface Drawable in those class.
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

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make a circle class 

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// Circle class

class Circle implements Drawable{

	public void draw(){
		System.out.println("Drawing Circle!");
	}

}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make a Rectangle class 

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Rectangle implements Drawable{

	public void draw(){
		System.out.println("Drawing Rectangle!");
	}
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Now we will make the Main class and we will test both classes implementation of draw.

class Main{
	
	public static void main(String args[]){

		// creating the instance of circle.
		Drawable circle = new Circle();
		// creating the instance of rectangle.
		Drawable rect = new Rectangle();

		// Now we will test their implementation of draw method.

		circle.draw();
		rect.draw();
	
	}
}