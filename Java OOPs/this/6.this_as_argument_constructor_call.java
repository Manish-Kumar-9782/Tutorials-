/*
	In this section we will use the this keyword to call the another class constructor.

	Other useage of the 'this' keyword:
		1. access the current class instance.
		2. invoke the method of the curren class
		3. invoke the current class constructor.
		4. reuse the constructor by using 'this' keyword.
		5. use as an argument to access/invoke current or other class attribute/method.

*/


// Now we will make two class one is Event and other is handler
// Event will make an event message and handeler will call the event.

class Handler{

	// Now in this section we will make an event object.
	Event obj;

	// Now we will make an constructor for the handler class
	Handler(Event obj){
		System.out.println("Using Handler on "+ obj);
		this.obj = obj;
	}

	void display(){
		System.out.println("Event data: "+ this.obj.data);
	}
}


class Event{

	// this event class has some data member which will be accessed by the handler.
	int data = 10;

	// Now we will make the constructor of the Event class.
	Event(){
		// in this constructor we will make an object of the handler.
		Handler handle1 = new Handler(this);
		// Now we will display the handler.
		handle1.display(); // this will show the data value.
	}
}


// Now we will make the Main class

class Main{

	public static void main(String args[]){

		Event eve = new Event();

		// this will display the event item data by using the handler class.
	}
}