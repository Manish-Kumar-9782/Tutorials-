/*
	In this section we will see that what is the blank final variable.

	blank final variable: a final variable that is not initialized at the time of declaration is known as blank final variable.

	A blank final variable can be static if it is declared as static final variable.
	a static blank final varaible can only be initialized inside the static block.
*/
// Now we will make a student class

class Student{

	int id;
	String name;
	final int PAN_CARD_NUMBER; // since pan card nuber do not change.


	// Now this PAN_CARD_NUMBER is uninitialized so it is a blank final variable.
	// A final blank variable can only be updated by the constructor.

	Student(int id, String name){

		this.id = id;
		this.name = name;
		this.PAN_CARD_NUMBER = 23455674;
	}

	void display(){

		System.out.println("id: "+ this.id);
		System.out.println("name: "+ this.name);
		System.out.println("PCard: "+ this.PAN_CARD_NUMBER);
	}	
}

class Main{

	public static void main(String[] args) {
		
		Student st1 = new Student(101, "Manish");

		// s1.PAN_CARD_NUMBER = 100002020; // Compile time error will occure.
		st1.display();
	}
}


/*

	Output:
	id: 101                                                                                
	name: Manish                                                                           
	PCard: 23455674    

	Note: In this we have seen that a blank final variable can only be initialized inside the constructor.
*/