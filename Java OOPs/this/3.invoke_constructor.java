/* 
===> In this section we will see that how to use 'this' keyword to invoke the 
	 current class method.

Note: this keyword can be used to refer the current class instance variable. 
if there is ambiguity b/w the instance variable and parameters, this keyword 
resolves the problem of ambiguity.

Note: this keyword can be used to invoke the current class constructor.


Note: When we don't require the 'this' keyword.
		this, keyword is not required when we don't face any kind of ambiguity
		in b/w the arguments and the instance attribute names.


---> Now we will make a class in whic we will overload the constructor and
	we will call one construtor from another constructor.


*/


class Foo{

	// Now we will make a two constructor one is default and another with one arg.

	Foo(){
		System.out.println("Hello default Foo");
	}

	Foo(String msg){

		// Now here we will call the default constructor also.
		this();  // empty list for default contructor.
		// Note: this(); must be the first statement in the constructor.
		System.out.println(msg);
	}

}


// Now we will make two Foo instance to check the output.

class Main{

	public static void main(String args[]){

		// Now we will make two foo instance.

		Foo foo_one = new Foo("This is foo one!");
		Foo foo_two = new Foo("This is foo two!");

		
	}
}

/* 
	Output:
	Hello default Foo                                                                      
	This is foo one!                                                                       
	Hello default Foo                                                                      
	This is foo two!     

	Note: in this we called the default constructor inside the 
	one argumented constructor.
*/
