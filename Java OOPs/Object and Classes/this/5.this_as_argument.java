/* In this section we will see that how to use the 'this' keyword as an argument


	Other useage of the 'this' keyword:
		1. access the current class instance.
		2. invoke the method of the curren class
		3. invoke the current class constructor.
		4. reuse the constructor by using 'this' keyword.


	Note: passing 'this' keyword to a method is mainly used in the event handling.

*/


class Event{

	void event1(Event obj){
		System.out.println("Event method has invoked.");
	}

	// Now we will make another method in which we will invoke the event1 method.

	void callthis(){
		this.event1(this); // this will call the event1 method.
	}
}


// Now we will make the Main class in which we will run the main method.

class Main{

	public static void main(String args[]){

		// Now first we will make the Event class instance.

		Event ev = new Event();

		ev.callthis(); // this will invoke the event1 method.
	}
}

/*

	Output:
		Event method has invoked.
	

	Note: In event handling (or) in a situation where we have to provide reference of 
		a clas to another one. it is used to reuse on object in many methods.

*/