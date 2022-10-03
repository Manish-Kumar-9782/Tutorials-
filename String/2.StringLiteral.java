/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Pogram: In this section we will see that what is string literal and 
	how to use in java program.

	There are two ways to create String Object:
		1. By string literal 
		2. By new keyword (creating a new instance of String).


	Literal String: java String Literal is created by using double quotes.

	String s = "welcome" // here "welcome" is the literal string which is
	assigned to the String object s.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

//

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class Main{
	
	public static void main(String args[]){

		// now we will create String object by passing literal string.

		String s1 = "Welcome!";
		String s2 = "Welcome!";
		String s3 = "Hello World!";


	/*
	Each time you create a string literal, the JVM checks the 
	"string constant pool" first. if the String already exist in the pool,
	a reference to the pooled instance is returned. if the string doesn't 
	exit in the pool, a new string instance is created and placed in the 
	pool.	
		*/
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*
	In the above program, only two object will be created.

	1. Initially JVM will not found any string object with the value 
	"Welcome!" in string constant pool that is why it will create new 
	object. 

	2. After creating s1, it will found the String with "Welcome!" 
	in the pool while assigning "Welcome!" to s2, so in this case it
	will not create a new object but will return the reference to the same
	instance.

	Note: String objects are stored in a special memory area known as the 
	"string constant pool".

	Note: Java use String literal to make java more memory efficient 
	(because no new object are created if it exists already in the string
	constant pool). 

*/