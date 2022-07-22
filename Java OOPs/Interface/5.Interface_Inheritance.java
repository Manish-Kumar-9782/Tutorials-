/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how can we inherit an interface
	and extend it in another interface.

	In other word we will extend the existing interface by inheriting it.

*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make two interface one will be parent and other will be child
// interface , in which we will extend the parent interface.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// printable interface 
interface Printable{  
	void print();  
}  


// showable interface, In this interface we will extend the printable
// interface by inheriting (extending) it.
interface Showable extends Printable{  
	void show(); 
}  

/* 
	Now we have added another feature in the Printable interface 
Now we can use This Showable interface with Printable interface 
functionallity.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will implement the showable interface in a class

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Test implements Showable{

	// Now here we will implement/define both interface methods.
	public void print(){
		System.out.println("Hello World!");
	}

	public void show(){
		System.out.println("Showing Hand Waves!");
	}
}


/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


// Now we will make an instance of this Test class and we will
// refer it by Test class.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// Here we will make our instance of Test

		Test test = new Test();

		test.print();
		test.show();
	
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*
	OutPut:
	Hello World!                                                                           
	Showing Hand Waves!                                                                         
     
    Note: As you can that we have the output form both method which are 
    declared in different interface.

    Conclusion: we can extedn or inherit an interface by using another 
    user-defined interface.

*/
