/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section, we will learn about the wrapper class in Java
	and what are they used for?

	Wrapper Classes: The wrapper class in Java provides the mechanism to 
		convert primitive into object and object into primitive.

	
	Since J2SE 5.0, autoboxing and unboxing feature convert primitive into
	object and object into primitives automaitically. The automatic conversion
	of primitive into an object is known as autoboxing and vice-verca unboxing.	
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*	Use of Wrapper classes:

	* Change the value in Method: Java supports only call by value. So, if we
	pass a primitive value, it will not change the original value. But if we
	convert the primitive value in an object, it will change the original value.

	* Serialization: We need to convert the objects into streams to performs 
	the serialization. if we have primitive value, we can convert it in objects
	through the wrapper classes.

	* Synchronization: Java synchronization works with objects in Multithreading.

	* Java.util pakcage: The java.util package provides the utility classes to 
	deal with objects.

	* Collection Framework: Java collection framework works with objects only,
	All classes of the collection framework (ArrayList, LinkedList, Vector, 
	HashSet, LinkedHashSet, TreeSet, PriorityQueue, ArrayDeque, etc.) deal
	with objects only.
	
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


// Autoboxing an UnBoxing 

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

//wrapper objects and vice-versa  
class WrapperClassExample{  

	public static void main(String args[]){  

		// First we will make primitive data types
		byte b=10;  
		short s=20;  
		int i=30;  
		long l=40;  
		float f=50.0F;  
		double d=60.0D;  
		char c='a';  
		boolean b2=true;  
		  
		//Autoboxing: Converting primitives into objects  
		Byte byteobj=b;  
		Short shortobj=s;  
		Integer intobj=i;  
		Long longobj=l;  
		Float floatobj=f;  
		Double doubleobj=d;  
		Character charobj=c;  
		Boolean boolobj=b2;  
		  
		//Printing objects  
		System.out.println("---Printing object values---");  
		System.out.println("Byte object: "+byteobj);  
		System.out.println("Short object: "+shortobj);  
		System.out.println("Integer object: "+intobj);  
		System.out.println("Long object: "+longobj);  
		System.out.println("Float object: "+floatobj);  
		System.out.println("Double object: "+doubleobj);  
		System.out.println("Character object: "+charobj);  
		System.out.println("Boolean object: "+boolobj);  
		  
		//Unboxing: Converting Objects to Primitives  
		byte bytevalue=byteobj;  
		short shortvalue=shortobj;  
		int intvalue=intobj;  
		long longvalue=longobj;  
		float floatvalue=floatobj;  
		double doublevalue=doubleobj;  
		char charvalue=charobj;  
		boolean boolvalue=boolobj;  
		  
		//Printing primitives  
		System.out.println("---Printing primitive values---");  
		System.out.println("byte value: "+bytevalue);  
		System.out.println("short value: "+shortvalue);  
		System.out.println("int value: "+intvalue);  
		System.out.println("long value: "+longvalue);  
		System.out.println("float value: "+floatvalue);  
		System.out.println("double value: "+doublevalue);  
		System.out.println("char value: "+charvalue);  
		System.out.println("boolean value: "+boolvalue);  
	}
}  

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*
	OutPut:
	---Printing object values---                                                           
		Byte object: 10                                                                        
		Short object: 20                                                                       
		Integer object: 30                                                                     
		Long object: 40                                                                        
		Float object: 50.0                                                                     
		Double object: 60.0                                                                    
		Character object: a                                                                    
		Boolean object: true
		                                                                   
	---Printing primitive values---                                                        
		byte value: 10                                                                         
		short value: 20                                                                        
		int value: 30                                                                          
		long value: 40                                                                         
		float value: 50.0                                                                      
		double value: 60.0                                                                     
		char value: a                                                                          
		boolean value: true                                                                    
                      
*/