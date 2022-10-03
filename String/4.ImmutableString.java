/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that what is immutable string in
	java, why it is useful, how to use it in java.


	Immutable String: A String is an unavoidable type of variable while writing
	any application program. String references are used to store various 
	attributes	like username, password, etc. In Java, String objects are 
	immutable. Immutable simply means unmodifiable or unchangeable.

	Once String object is created its data or state can't be changed but a new
	String object is created.


	Why String Objcet are immutable in java:

	As java uses the concept of String Literal. Suppose there are 5 reference
	variable, all refer to one object "Hello". if one reference variable changes 
	the value of the object, it will be affected by all the reference variable.
	That is why String Object are immutable in java.

*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will create a string object and try to change it.

class TestImmutableString1{

	/* Test 1: In this test we will try to change the Sring data by 
	using the Sting object member methods. */

	public static void main(String[] args) {
		
		// first we will create a new String object using literal string.
		String s = "Hello";

		// Now if we want to add the "World" by using the concat method.

		s.concat("World"); 

		/* Now by logic s should contain "Hello World" but it return a 
		new String object with "Hello World" and the original data remain
		same, if we try to print the both things we will see that operation
		clearly.
		 */ 

		// printing original and returned value.

		System.out.println(s); // before concat
		System.out.println(s.concat(" World"));  // concating " World"
		System.out.println(s); // after concat

	}

}

class TestImmutableString2{

	/* Test 2: In this test we will see that how to update the String
	object with new changed string. */

	public static void main(String[] args) {
		
		// first we will create a new String object using literal string.
		String s = "Hello";
		System.out.println(s); // before concat
		// Now if we want to add the "World" by using the concat method.

		// Note: here you need to reassign the this the return value
		// of s.concat() method into s again, that how we will update 
		// our object state.

		s = s.concat("World"); 
		System.out.println(s); // after concat
		
		/* Now here we will reassign the s with new string object, but old 
		String literal will remain in the string constant pool, until garbage
		collector don't collect it.
		 */ 
	}
}

/*
	Note: Run both the classes inidividually to see the effect.

	0. compile ---> javac 4.ImmutableString.java 
	1. run 	   ---> java TestImmutableString1
	2. run 	   ---> java TestImmutableString2

	Output In sequence:

	java TestImmutableString1           
	Hello                                                                                  
	Hello World                                                                            
	Hello                                                                                  
                                                                                       
	java TestImmutableString2           
	Hello                                                                                  
	HelloWorld  
*/

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/


/*
	Additional Documentation:

	Following are some features of String which makes String objects 
	immutable.

1. ClassLoader:

	A ClassLoader in Java uses a String object as an argument. Consider, 
	if the String object is modifiable, the value might be changed and the 
	class that is supposed to be loaded might be different.

	To avoid this kind of misinterpretation, String is immutable.

2. Thread Safe:

	As the String object is immutable we don't have to take care of the 
	synchronization that is required while sharing an object across 
	multiple threads.

3. Security:

	As we have seen in class loading, immutable String objects avoid 
	further errors by loading the correct class. This leads to making the 
	application program more secure. Consider an example of banking 
	software. The username and password cannot be modified by any intruder 
	because String objects are immutable. This can make the application 
	program more secure.

4. Heap Space:

	The immutability of String helps to minimize the usage in the heap 
	memory. When we try to declare a new String object, the JVM checks 
	whether the value already exists in the String pool or not. If it 
	exists, the same value is assigned to the new object. This feature 
	allows Java to use the heap space efficiently.

Why String class is Final in Java?
	The reason behind the String class being final is because no one can 
	override the methods of the String class. So that it can provide the 
	same features to the new String objects as well as to the old ones.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
