/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how to use the unboixing in
	java.

	Unboxing: The automatic conversion of wrapper type into its corresponding.
	primitve type is known as unboxing. it is the reverse process of
	autoboxing.

	Since java5, we don't need to use the intValue(), floatValue() methods of
	wrapper classes to convert the wrapper type into primitives.	
*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Wrapper class Example: Wrapper to Primitive

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class WrapperToPrimitive{

	public static void main(String[] args) {
		

		// Now here first we will make wrapper object
		Integer i = new Integer(3);
		Float f = new Float(3.45);


		// unboxing i by using the intValue()
		int a = i.intValue();

		// unboxing f without floatValue();

		float b = f;


		System.out.println("Interger i: "+ i);
		System.out.println("Float f: "+ f);
		System.out.println("int a: "+ a);
		System.out.println("float b: "+ b);

	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*
	OutPut:
	warning: [removal] Integer(int) in Integer has been deprecated and 
	marked for removal                                                
                Integer i = new Integer(3);                                            
                            ^                                                          
	warning: [removal] Float(double) in Float has been deprecated and 
	marked for removal                                                 
	            Float f = new Float(3.45);


	Interger i: 3                                                                          
	Float f: 3.45                                                                          
	int a: 3                                                                               
	float b: 3.45       
*/