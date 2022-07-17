
// in this section we will illustrate how to defiena class and field.

//defining a studen class

class Student{

	// now we will define the fields of the student class
	// these are the data members of the fields class.
	int id;  	 
	String name;

	// Now we will create a main method inside the Student class.


	public static void main(String args[]){

		// now we will create an object of the Student class.
		Student s1 = new Student();

		// Now s1 is the instance of the Student class and have id and name.

		// Now here we will print the values of the Student fields 
		System.out.println(s1.id);
		System.out.println(s1.name);
	}
}

/*

	Output:

	0
	null

*/