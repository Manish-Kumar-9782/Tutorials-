// In this section we will learn about the Constructor or more specificly non argument constructor.

// Creating the student class.

class Student{

	int id;
	String name;

	// Creating a non args constructor, 
	// it will be called when we don't pass any argument while creating 
	// a new instance.
	Student(){
		System.out.println("Non Args Constructor is called.");
	}

	// a method to update the data members.
	void updateDetails(int _id, String _name){
		id = _id;
		name = _name;
	}

	// A method to display the information.
	void displayInfromation(){
		System.out.println(id+ " " +name);
	}
}

class Main{

	// now here we need to define our main funciton and we will 
	// also initialize the Student instance data members.

	public static void main(String args[]){

		Student s1 = new Student();
		// as we creates the s1 non-args constructor is called.
	}
}

/*

	output:
	Non Args Constructor is called.                                                                                  
*/