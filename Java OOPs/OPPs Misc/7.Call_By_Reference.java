
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that what is call by Reference and
	why it is used for?

	Call By Reference: if we pass the object instead of the values and use
	the primitive value through that object refer than it will be called
	call by reference, calling by refernce will change the its original 
	value.

*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a test class in which we will pass a reference (object)

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class Test{

	int data = 100;

	// Now we will make a method to try to change the value.
	// This method will take the Test object which contain the refernece
	// of primitive data types.

	void change(Test obj){
		obj.data = obj.data + 100; // adding 100 into data.

		// Note here data is the local variable
		System.out.println("data inside the change: " + data);
	
		// Outside this scope data will be affected it means
		// our original data will remain unchnaged.
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


// Now we will make the Main class

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class Main{
	
	public static void main(String args[]){

		// Here we will make an instance of the Test class and 
		// try to change its data member.

		Test obj = new Test();

		// printing before change
		System.out.println("Before Change: " + obj.data);
		obj.change(obj);
		System.out.println("After Change: "+ obj.data);	
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*
	OutPut:
	Before Change: 100                                                                     
	data inside the change: 200                                                            
	After Change: 200

	Note: As you can see that primitive data has been changed by using the
	reference (through object).
*/