/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how to compare two String 
	object in a java program.

	--> We can compare String in java on the basis of content and reference.

	--> it is used in authentication (by equal() method), sorting (by compareTo()
	method), reference matching (by == operator) etc.

	There are three way to compare String in Java.

	1. By Using equals() Method
	2. By Using == Operator
	3. By compareTo() Method	
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


// Now in this we will make three class to run the main program.
// each class will be an example of those three way to compare a string.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// 1. By using the equals() Method.

/* The String class equals() method compares the original content of the 
string. it compares vlaues of string for equality. String class provides
the following two methods.

	--> public boolean equals(Object another):
			compares this string to the specified object.

	--> public boolean equalsIgnoreCase(String another):
			compares this string to another string, ignoring case.
*/

class EqualsMethod{

	// Now here we will make some String Object and try to compare thme
	// by using the equal method. 
	public static void main(String[] args) {
		
		String s1 = "Hello";
		String s2 = "World";
		String s3 = "Hello";
		String s4 = "hello";  // lowercase string.

		//Now we will compare the S1 with s2,s3 and s4.

		System.out.println("equals: s1 --> s2 "+ s1.equals(s2));
		System.out.println("equals: s1 --> s3 "+ s1.equals(s3));
		System.out.println("equals: s1 --> s4 "+ s1.equals(s4));


		// Now comparing with equalIgnoreCase
		System.out.println("equalsIgnoreCase: s1 --> s2 "+ s1.equalsIgnoreCase(s2));
		System.out.println("equalsIgnoreCase: s1 --> s3 "+ s1.equalsIgnoreCase(s3));
		System.out.println("equalsIgnoreCase: s1 --> s4 "+ s1.equalsIgnoreCase(s4));

	}
}


/*
	Output:
	equals: s1 --> s2 false                                                                 
	equals: s1 --> s3 true                                                                  
	equals: s1 --> s4 false                                                                 
	equalsIgnoreCase: s1 --> s2 false                                                       
	equalsIgnoreCase: s1 --> s3 true                                                        
	equalsIgnoreCase: s1 --> s4 true 

	Note: Since equals() Method Case sensitive that's whay it's perfect match 
	is s3 and gives true, and for other it give false.

	Note: Since equalsIgnoreCase() Method case ignore Case that's why it 
	found a match with "hello" and gives true two time one for "Hello" and
	other for "hello".                                                       
                                  
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

//2.compare the String by using the == operator.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*	Now we will compare two string by using the equal equal operator
// -->> equal eqaul operator (== operator.)
*/
class EqualEqualOp{
	
	public static void main(String[] args) {

		String s1 = "Welcome";
		String s2 = "World";
		String s3 = "Welcome";
		String s4 = "hello";  // lowercase string.

		//Now we will compare the S1 with s2,s3 and s4.
		// by using the == operator
		System.out.print("Compare: s1 --> s2 :");
		System.out.println(s1 == s2);
		System.out.print("Compare: s1 --> s3 :");
		System.out.println(s1 == s3);
		System.out.print("Compare: s1 --> s4 :");
		System.out.println(s1 == s4);

	}
}

/*
	OutPut:
	Compare: s1 --> s2 :false                                                              
	Compare: s1 --> s3 :true                                                               
	Compare: s1 --> s4 :false

	Note: here s1 and s3 are pointing to the same literal string in the 
	literal string pool.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// 3. Compareing the String object with CompareTo() Method.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
/*	The String class compareTo() methodcompares values lexicographically and
returns an intergar value that describes if first string is less than, equal
to or greater than second string.

Suppose s1 and s2 are two String objects. if

* s1 == s2: The method returns 0;
* s1 > s2: The method returns a positive value.
* s1<s2: The method returns a negative value.
*/

class CompareToMethod{

	public static void main(String[] args) {
		
		// first we need a few string object to compare.
		String s1 = "Hello";
		String s2 = "Absolute";
		String s3 = "Hello";
		String s4 = "hello";  // lowercase string.

		System.out.println("CompareTo: s1 --> s2 "+ s1.compareTo(s2));
		System.out.println("CompareTo: s1 --> s3 "+ s1.compareTo(s3));
		System.out.println("CompareTo: s1 --> s4 "+ s1.compareTo(s4));
	}
}

/*
	OutPut:
	CompareTo: s1 --> s2 7                                                                 
	CompareTo: s1 --> s3 0                                                                 
	CompareTo: s1 --> s4 -32 
*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
