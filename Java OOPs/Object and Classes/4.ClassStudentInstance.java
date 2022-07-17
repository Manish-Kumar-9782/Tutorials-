// In this section we will make two a student class and we will create two different
// instance of the student class and store the information into them.

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
		Student s2 = new Student();

		// now we will initialize the s1 data memeber.
		s1.id = 101;
		s1.name = "Manish";


		// now we will initialize the s2 data memeber.
		s2.id = 102;
		s2.name = "Kumar";


		// Now we will print them

		System.out.println("s1 : "+ s1.id+ " " + s1.name);
		System.out.println("s2 : "+ s2.id+ " " + s2.name);
	}
}

/*

	output:
	s1 : 101 Manish                                                                        
	s2 : 102 Kumar                                                                                   
*/