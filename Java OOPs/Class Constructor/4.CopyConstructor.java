// in this section we will learn;
/*
	* default constructor.
	* Parameterized Constructor.
	* Constructor Overloading.
	* Copy Constructor.
*/

// Creating the student class.

class Student{

	int id;
	String name;
	int age;

	// Creating a non args constructor, 
	// it will be called when we don't pass any argument while creating 
	// a new instance.

	//Note: Here non parameterised constructor act as a default constructor.
	Student(){
		// this will do nothing
	}

	// Now here we will make one more constructor with parameters
	// hense it will be called parameterised constructor.
	
	Student(int _id, String _name){
		// this will assign the id and name.
		id = _id;
		name =_name;
	}

	// Now Here again we will use another constructor to initialize all the data members.
	// Until this constructor we have overloaded The Constructor
	// one time
	Student(int _id, String _name, int _age){
		// in this we will assign id, name and age
		id = _id;
		name =_name;
		age = _age;
	}

	// Now we will make another constroctor to copy one object data into
	// another object of Student.

	Student(Student obj){
		this.id = obj.id;
		this.name = obj.name;
		this.age = obj.age;
	}

	// a method to update the data members.
	void updateDetails(int _id, String _name){
		id = _id;
		name = _name;
	}

	// A method to display the information.
	void displayInfromation(){
		System.out.println(id+ " " +name + " " + age);
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
		Student s3 = new Student(102, "Kumar", 26);
		

		// Now we will copy s3 data into a new Student.
		Student s4 = new Student(s3);
		// Now s4 contain the s3 values.

		// Now we will display the information of the each Student instance.
		s1.displayInfromation();  // default constructor
		s2.displayInfromation(); // 2-parameter constructor
		s3.displayInfromation(); // 3-paramter constructor
		s4.displayInfromation(); // Copy Constructor result.
	}
}

/*

	output:
	0 null 0                                                                               
	101 Manish 0                                                                           
	102 Kumar 26 


Note: As we can see that there is Constructor overloading happening.
according to the type and size of argument list it will run the specified Constructor.                                                                                
*/