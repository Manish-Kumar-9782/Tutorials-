/*
	In this section we will see that how to use method overloading to achieve the polymorphism
	in the java programs.

	In this we will use the mulitple method with same name but with differnt no or arguments.	
*/


class Add{

	// add mathod to add 2 integes only.
	static int add(int a, int b){return a+b;}
	static double add(double a, double b){return a+b;} // add 2 doubles

}

// Now we will test this method overloading in the Main method

class Main{

	public static void main(String args[]){

		System.out.println(Add.add(10, 20));
		System.out.println(Add.add(10.8, 20.6));
	}
} 

/*
	Output:
	30                                                                                     
	30

	Note: as you can see that both method called when their corresponding types of args
		are passed, this is called the Polymorphism with method overloading.  
*/
	