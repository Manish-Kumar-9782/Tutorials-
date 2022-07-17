// In this section we will make two a student class and we will create two different
// instance of the student class and store the information into them
// by using the class methods.

// Creating the student class.

class Student{

	int id;
	String name;

	// Now we will define a function which will be used to insert the 
	// name and id of the instance.

	void insertDetails(int _id, String _name){
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
		Student s2 = new Student();

		// assign values to s1 and s2 by using the insertDetails() method.

		// now we will initialize the s1 data memeber. 
		s1.insertDetails(101, "Mainsh");


		// now we will initialize the s2 data memeber.
		s2.insertDetails(102, "Kumar");


		// Now we will dispaly the inforamtion of both instance by 
		// using the dispalyInfromation method.

		s1.displayInfromation();
		s2.displayInfromation();
	}
}

/*

	output:
	101 Manish                                                                        
	102 Kumar                                                                                   
*/