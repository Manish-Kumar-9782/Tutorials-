// in this section we will see how a static variable is used
// to count the Number of student are created from Student class.

// In this section we will also learn that how to use the static method.


/*
	static variable are common for each object (from same class), so static varaible
	are used to store the common infomation for the each object.

	static method: static method may be used to update the static variable.

	like student from a common shcool must have the school name which is common.
*/

//
class Student{

	int rollno;
	String name;
	static String school = "SMDJ";  // school name is static and common for each student.

	private static int totalStudents = 0;
	/*	Note: totalStudent cannot be changed from outside of the class.
		so we will use the setter and getter method to display the infromation of the.
		total student created.
	*/


	Student(int _rollno, String _name){
		// in this we will assign id, name and rollno.
		rollno = _rollno;
		name =_name;

		// Now each time of creating a student we will increase the totalStudent.
		totalStudents++;
	}


	// Since school name is common so we need to make a static function to 
	// update the school name, so we can change the school name for each object of school.

	static void updateSchoolName(String _name){
		/** Change the school name at once */

		school = _name;
	}

	// A method to display the information.
	void displayInfromation(){
		System.out.println(rollno+ " " +name + " " + school);
	}

	// Now Here we will make getter and setter method to update the totalStudent.
	// Since totalStudent is static then we need to make getter and setter as static.

	static void getTotalStudent(){System.out.println("Total Students: "+totalStudents);}

	// void setTotalStudent() // Now use for now.	
}

// ========================================================== //

// Now we will create the Main class to run the main program.

class Main{

	public static void main(String args[]){

		// Now we need to create three student with different name.
		// but these student will contain the same school name.
		Student s1 = new Student(101, "Manish");
		Student s2 = new Student(102, "Rahul");
		Student s3 = new Student(103, "Sagar");

		// Now we will see how many student are created 
		s1.displayInfromation();
		s2.displayInfromation();
		s3.displayInfromation();

		Student.getTotalStudent();



	}
}


/*
	Output:
	101 Manish SMDJ                                                                        
	102 Rahul SMDJ                                                                         
	103 Sagar SMDJ                                                                         
	Total Students: 3

	As we can see that we have created three student and also have the record of
	how many student have been created. this is done by using the static variable and 
	static function.     
		
*/