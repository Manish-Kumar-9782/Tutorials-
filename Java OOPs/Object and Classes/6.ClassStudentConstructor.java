// In this section we will make a student class and we will initialize it's data
// members by using the Constructor.

// Creating the student class.

class Student{

	int id;
	String name;

	// a constructor to initalize the value of the data members.

	Student(int _id, String _name){
		// this constructor will be called automatically when 
		// an instance of the Student is created.
		id = _id;
		name = _name;
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

		Student s1 = new Student(101, "Mainsh");
		Student s2 = new Student(102, "Kumar");

		// assign values to s1 and s2 by using the insertDetails() method.

		// now we will initialize the s1 data memeber. 
		// s1.insertDetails(101, "Mainsh");


		// now we will initialize the s2 data memeber.
		// s2.insertDetails(102, "Kumar");


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