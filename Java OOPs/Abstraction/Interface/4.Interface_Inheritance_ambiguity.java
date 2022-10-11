/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how we have a single 
	implementation for multiple abstracted method from multiple interface.
	and how we avoid the ambiguity of having same method in mutliple interface.\


	Note: Since there is no implementation from interface of any method so
	there will be no ambiguity, we will write from blank slate.
*/


/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make two interface with same method.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// printable interface
interface Printable{  
	void print();  
}  


// showable interface.
interface Showable{  
	void print();  
}  

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will implement in a class 

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class NonAmbiguity implements Printable, Showable{

	// here we will only implement single defination for two print method.
	public void print(){
		System.out.println("Hello World!");
	}
}


/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


// Now we will make Main class and we will make instance of NonAmbiguity
// and we will test it.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// Here we will make our instance of NonAmbiguity

		NonAmbiguity test = new NonAmbiguity();

		test.print();
	
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*
	OutPut:
	Hello World!                                                                           
     
    Note: From this we have seen that we have only single implementation 
    of print() method which was delcared in both interfaces (Showable,
    Printable)

*/
