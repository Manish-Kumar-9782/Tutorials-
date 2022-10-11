// In this section we will learn about the Constructor.
// in this we will learn that what is the difference in the non-parameterized
// and parameterized constructor.

// Creating the student class.

class Student{

	int id;
	String name;

	// Creating a non args constructor, 
	// it will be called when we don't pass any argument while creating 
	// a new instance.

	//Note: Here non parameterised constructor act as a default constructor.
	Student(){
		System.out.println("Non Args Constructor is called.");
	}

	// Now here we will make one more constructor with parameters
	// hense it will be called parameterised constructor.
	
	Student(int _id, String _name){
		System.out.println("Parameterised Constructor is called.");
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

		// Here we will create two new instace
		// * one without paramters
		// * one with parameters.
		Student s1 = new Student();
		Student s2 = new Student(101, "Manish");
		
	}
}

/*

	output:
	Non Args Constructor is called.
	Parameterised Constructor is called.                                                                                  
*/