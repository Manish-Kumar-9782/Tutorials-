// In this section we will see that how to use the static block and how they are executed.

/*
	Use of Static Block:
		* It is used to initialize the static data member.
		* it executed before the main method at the time of calssloading.
*/

// Now we will create a class which will hold the static block.

class Main{

	int a;

	static{System.out.println("static block invoked!");}

	// Now if we run a main function

	public static void main(String args[]){
		System.out.println("hello main");
	}

	
}
