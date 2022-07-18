/*
	In this section we will see that how to use the 'this' keyword to return the 
	current class instance.

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

	//Now we will make a method to return the current handler instance.
	Handler getHandler(){return this;}

}


class Event{

	// this event class has some data member which will be accessed by the handler.
	int data = 10;
	Handler handle1 = new Handler(this);
	// Now we will make the constructor of the Event class.
	Event(){
		// in this constructor we will make an object of the handler.
		
		// Now we will display the handler.
		handle1.display(); // this will show the data value.
	}

	// Now we will make two method to return the current handler and event instance.
	Event getEvent(){
		return this;
	}

	Handler getHandler(){
		return handle1;
	}
}


// Now we will make the Main class

class Main{

	public static void main(String args[]){

		Event eve = new Event();

		// this will display the event item data by using the handler class.
	
		// Now we will get the current handler and the event class instance.

		System.out.println("Current Handler: "+ eve.getHandler());
		System.out.println("Current Evnet: "+ eve.getEvent()); 
	}
}


/*
	Output:
	Using Handler on Event@452b3a41                                                        
	Event data: 10                                                                         
	Current Handler: Handler@65b54208                                                      
	Current Evnet: Event@452b3a41 
	
	Note: As you can see that Handler has the same event instance which is retued
	by the Event instance.
*/