// In this section we will make a student class and assigning some value to its
// data members through reference.

// Creating the student class.

class Student{

	int id;
	String name;
}

class Main{

	// now here we need to define our main funciton and we will 
	// also initialize the Student instance data members.

	public static void main(String args[]){

		Student s1 = new Student();

		// now we will initialize the s1 data memeber.
		s1.id = 101;
		s1.name = "Manish";

		// Now we will print them

		System.out.println("s1 id : "+ s1.id);
		System.out.println("s1 name : "+ s1.name);
	}
}

/*

	output:
	s1 id : 101                                                                            
	s1 name : Manish                                                                                   
*/