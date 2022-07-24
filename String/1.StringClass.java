/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Pogram: In this section we will see about the String, what is string
	how to use it in our progrm, how it is usefull in our program.

	Java String: In java, String is basically an object that represents 
	sequence of char values. An array of characters works Same as Java
	String.	
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a string by using the Character array and String object.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class Main{
	
	public static void main(String args[]){

		// a String by array of char.
		char ch[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l','d'};
		
		// A String by Making a new instance of String
		String greet = new String("hello World!");

		// A String by passing value (literal string) to String objecct.
		String greet2 = "Hello World again!";

		System.out.println(ch);
		System.out.println(greet);
		System.out.println(greet2);
	/*
		Note: We should always use the String class to make string.

		Java String class provides a lot of methods to perform operations
		on strings such as compare(), concat(), equal(), split(), length(),
		replace(), compareTo(), intern(), substring() etc.

		Note: The java.lang.String class implements Serializable, Comaparable,
		and CharSequence interface.	
		*/
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*
	OutPut:
	Hello World                                                                            
	hello World!                                                                           
	Hello World again!

	Note: As you can see that we have printed all the three string created
	by three different method.     
*/