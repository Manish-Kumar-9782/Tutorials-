
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how a wrapper class is used
	to convert a primitve type into an object.

	Autoboxing: The automatic conversion of primitive data type into its 
	corresponding wrapper class is known as autoboxing.

	Since Java 5, we do not need to use the valueOf() method of wrapper
	class to convert the primitive into objects.	
*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Wrapper class Example: Primitive To Wrapper 

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class PrimitiveToWrapper{

		
		public static void main(String args[]){
			
			// Now here first we will make primitives

			int i = 10;
			int j = 40;

			// converting to into an Integer object using valueOf()
			Integer a = Integer.valueOf(i);

			// autoboxing, without using valueOf() 
			Integer b = j;


			// Now we will print both vlaues.

			System.out.println("Primitive i: " + i);
			System.out.println("Primitive j: " + j);
			System.out.println("Wrapper a: " + a);
			System.out.println("Wrapper b: " + b);
		
		
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*
	OutPut:
	Primitive i: 10                                                                        
	Primitive j: 40                                                                        
	Wrapper a: 10                                                                          
	Wrapper b: 40

	As you can see that Wrapper Class object have the same values as primitive. 
*/