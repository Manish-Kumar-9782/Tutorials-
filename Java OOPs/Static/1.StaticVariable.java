// in this section we will see how a static variable is used.

/*
	static variable are common for each object (from same class), so static varaible
	are used to store the common infomation for the each object.

	like student from a common shcool must have the school name which is common.
*/

//
class Student{

	int rollno;
	String name;
	static String school = "SMDJ";  // school name is static and common for each student.

	Student(int _rollno, String _name){
		// in this we will assign id, name and rollno.
		rollno = _rollno;
		name =_name;
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

		// now if we display the each student information then we will see that
		// each student contain same school name.

		s1.displayInfromation();
		s2.displayInfromation();
		s3.displayInfromation();


		// Now if we change the shchool Name then it will be changed for each student.
		//Note: we can update the school name by using any student 
		// but by convention we should use the Student class.

		Student.updateSchoolName("JCA");
		System.out.println("\nChanging the School Name by using the Student Class \n");
		s1.displayInfromation();
		s2.displayInfromation();
		s3.displayInfromation();
	}
}


/*
	Output:
	101 Manish SMDJ                                                                        
	102 Rahul SMDJ                                                                         
	103 Sagar SMDJ                                                                         
	                                                                                       
	Changing the School Name by using the Student Class                                   
	                                                                                       
	101 Manish JCA                                                                         
	102 Rahul JCA                                                                          
	103 Sagar JCA  
		
*/