/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will learn about the object cloninng and How
	can be it is usefull in our daily life and how to achieve.

	Object Cloning: the object cloning is a way to create exact copy of an
	object. The clone() method of Object class is used to clone an object.

	-> The java.lang.Cloneable interface must be implemented by the class whose
	object clone we want ot create. if we don't implement Cloneable interface, 
	clone() method generates CloneNotSupportedException.

*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Exmaple of cloning.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/* Now we will make a new class which will implement the Cloneable interface
	and we will define that method as well.	*/

class Student implements Cloneable{

	int rollno;
	String name;

	Student(int rollno, String name){

		this.rollno = rollno;
		this.name = name;
	}

	void display(){
		System.out.println(this.rollno + " "+ this.name);
	}

	// Now we will define the clone method.

	public Object clone() throws CloneNotSupportedException{
		return super.clone();
	}
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a Main class in which we will make make clone of student 
// object.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
	
	public static void main(String args[]){

		// Now here we will Make a instance and clone it

		// Note Here we need to use the try-catch block
		// to handle the Exeption.

	try{
		
		Student s1 = new Student(101, "Manish");
		Student s2 = (Student)s1.clone();  // making a clone of the s1

		// Now we will display them and see that they have same data.
		s1.display();
		s2.display(); 

	}catch(CloneNotSupportedException c){}
	
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

/*
	OutPut:
	101 Manish                                                                             
	101 Manish

	Note: As you can see that we have successfully clonned an object.

	If we create another object by new keyword and assign the values of 
	another object to this one, it will require a lot of processing on 
	this object. So to save the extra processing task we use clone() method.    
*/