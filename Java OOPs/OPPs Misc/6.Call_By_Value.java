
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that what is call by value and
	why it is used for?

	Call By Value: if we call a method passing a value, it is known as 
	call by value. The changes being done in the called method, is not
	affected in the calling method.

*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a test class in which we will pass a value

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class Test{

	int data = 100;

	// Now we will make a method to try to change the value.
	void change(int data){
		data = data + 100; // adding 100 into data.

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
		obj.change(obj.data);
		System.out.println("After Change: "+ obj.data);	
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*
	OutPut:
	Before Change: 100                                                                     
	data inside the change: 200                                                            
	After Change: 100

	Note: As you can see that data is changed only inside the change method.
	ther is no affect outside the method. data is still remain same. 
*/