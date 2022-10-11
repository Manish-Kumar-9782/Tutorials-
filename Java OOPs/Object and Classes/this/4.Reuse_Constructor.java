/* In this section we will see that how to reuse the constructor to increase the
	efficieny of the program.

Note1: this keyword can be used to refer the current class instance variable. 
if there is ambiguity b/w the instance variable and parameters, this keyword 
resolves the problem of ambiguity.

Note2: this keyword can be used to invoke the current class method and current
		class constructor.


Note: When we don't require the 'this' keyword.
		this, keyword is not required when we don't face any kind of ambiguity
		in b/w the arguments and the instance attribute names.

--> Now we will make a student class and we will use the this keyword 
	
	assign the values which will be passed inside the constructor with the
	same parameter name as intance attributes.

*/

class Student{

	int rollno;
	String name;
	float fee;
	int age;


	Student(int rollno, String name, float fee){
		/*
		Note: Now here, we need to notice that the name of the arguments and
		name of the attributes are same to resolve this kind of ambiguity 
		we we will use 'this' keyword.
		*/

		this.rollno = rollno;
		this.name = name;
		this.fee = fee;


		/*Note: For better practice always use 'this' keyword.*/ 
	}

	// Now suppose that we also wanted to update the age of the student from another 
	// constructor, then we can use the above constructor inside the new constructor.

	Student(int rollno, String name, float fee, int age){
		// In this case for other three attribute we can use the above constructor.
		this(rollno, name, fee);
		// and now we can update the age of the student.
		this.age = age;

		/* Note: by using the we reduce the rewriting all the code for other attributes.
		//		it looks clean code and easy to debug.
			
		   Note2: call this() as the first statement in a Constructor. 
		*/
	}


	void display(){
		// a display function to display the details of the student

		System.out.println(this.rollno + " " + this.name + " " + this.fee +" " + this.age);
		// using this keyword to refer the current instance attributes.
	}
}


class Main{

	public static void main(String args[]){

		// NOw first of all we will make three students;

		Student s1 = new Student(101, "Manish", 85000);
		Student s2 = new Student(102, "Rahul", 67000);
		Student s3 = new Student(103, "Sagar", 80000, 21);


		// Now we will display the each student inforamtion.
		s1.display();
		s2.display();
		s3.display();
	}
}

/* 
	Output:
	101 Manish 85000.0 0                                                                   
	102 Rahul 67000.0 0                                                                    
	103 Sagar 80000.0 21                                                                        
    
	// Conclusion: As we can see that we have added the age for student s3.

*/
