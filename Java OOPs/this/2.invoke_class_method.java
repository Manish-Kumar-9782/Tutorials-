/* In this section we will use the this keyword to inoke the class method. 
This 'this' keyword will be used inside the class to invoke the current class method.


Note: When we don't require the 'this' keyword.
		this, keyword is not required when we don't face any kind of ambiguity
		in b/w the arguments and the instance attribute names.

--> Now we will make a student class and we will use the this keyword 
	
--> Now suppose that we have a method named as update which will update the
	attributes of the student so we will use that update method inside the 
	Constructor and we will use 'this' keyword to invoke the update mehtod 
	of Student class.
	
*/

class Student{

	int rollno;
	String name;
	float fee;


	// Now we will make a constructor 
	Student(int rollno, String name, float fee){
		// Now we will invoke the update method of the Student class.
		this.update(rollno, name, fee); 

		/* Note: if we don't use the 'this' keyword before to invoke the method
				 compiler will automatically add this during compile time.
				
		*/
	}

	void update(int rollno, String name, float fee){
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


	void display(){
		// a display function to display the details of the student

		System.out.println(this.rollno + " " + this.name + " " + this.fee);
		// using this keyword to refer the current instance attributes.
	}
}


class Main{

	public static void main(String args[]){

		// NOw first of all we will make three students;

		Student s1 = new Student(101, "Manish", 85000);
		Student s2 = new Student(102, "Rahul", 67000);
		Student s3 = new Student(103, "Sagar", 80000);


		// Now we will display the each student inforamtion.
		s1.display();
		s2.display();
		s3.display();
	}
}

/* 
	Output:
	101 Manish 85000.0                                                                     
	102 Rahul 67000.0                                                                      
	103 Sagar 80000.0                                                                      
    
	// Note: if we don't use 'this' keyword then there will be no assignmet of values
		in the case of ambiguity.

	// Note: we have initiated the Student details by using the update  which is invoked
			 by using the 'this' keyword.

*/
