/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Pogram: In this section we will see that how to create a string object 
	by using the new keyword.

	There are two ways to create String Object:
		1. By string literal 
		2. By new keyword (creating a new instance of String).

	
	/------------------------------------
	
	syntax: String s = new String("welcome");
	
	------------------------------------/
	
	---> here instead of "welcome" we can place any character sequence as we
	want.


	---> In such case, JVM will create a new string object in normal (non-pool)
	heap memory, and the literal "Welcome" will be placed in the string constant
	pool. the variable s will refer to the object in a heap (non-pool)
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class Main{
	
	public static void main(String args[]){

		// now we will create String object by passing literal string.

		// a String by array of char.
		char ch[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l','d'};
		
		// A String by Making a new instance of String
		String greet = new String("hello World!");

		// A String by passing value (literal string) to String objecct.
		String greet2 = "Hello World again!";

		System.out.println(ch);
		System.out.println(greet);
		System.out.println(greet2);
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*

	
	

*/