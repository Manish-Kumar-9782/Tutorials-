/* In this section we will see that how to use the this keyword to refer a 
current class instance variable. 

Note: this keyword can be used to refer the current class instance variable. 
if there is ambiguity b/w the instance variable and parameters, this keyword 
resolves the problem of ambiguity.


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


*/
