// In this section we will make a program to illustrate that how we can create an
// class outside the main function and use it.

// Creating the student class outside the main main function class.

class Student{

	int id;
	String name;
}

// Now we will make our class in which we will define our main program.

class Test{

	// now defining the main function:

	public static void main(String args[]){

		// now here we need to make an instance of the Student
		Student s1 = new Student();

		// Now we will use  access them by using the . operateor.

		System.out.println(s1.id);
		System.out.println(s1.name);
	}
}

/*
	output:
	0                                                                                      
	null                                                                                   
*/