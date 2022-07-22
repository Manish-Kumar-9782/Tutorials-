
/*-----------------------------------------------------------------------*/

/* In this section we will see that how to use an abstracted class and define it*/


// Now we will Make an abstracted class.
// since we don't know that user what kind of shape will, so we don't know
// it's implementation so i will make it as a abstracted class.

abstract class Shape{

	abstract void draw();
	// whenever a user will inherit/extends this class he/she will apply
	// the implementation.
} 

/*-----------------------------------------------------------------------*/

// Now we will make two more class which will inherit the Shape class.
// and they will implement their own implementation of the draw method.

class Circle extends Shape{


	void draw(){
		System.out.println("drawing the Circle!");
	}  
	// Here Defination is implemented by the Circle class.
}

/*-----------------------------------------------------------------------*/


class Rectangle extends Shape{

	void draw(){

		System.out.println("drawing the Rectangle!");
	}
}

/*-----------------------------------------------------------------------*/

// Now we will make Main class in which we will run the main loop

class Main{

	public static void main(String[] args) {
		
		// Now here will make a Circle Shape
		Shape new_shape = new Circle();

		new_shape.draw(); // 
	}
}