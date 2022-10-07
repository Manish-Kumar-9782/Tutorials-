/*
	In this section we will see that how to use method overloading to achieve the polymorphism
	in the java programs.

	In this we will use the multiple method with same name but with different no or arguments.	
*/

class Add {

	// add method to add 2 integer only.
	static int add(int a, int b) {
		return a + b;
	}

	static int add(int a, int b, int c) {
		return a + b + c;
	} // add three integers

}

// Now we will test this method overloading in the Main method

class Main {

	public static void main(String args[]) {

		System.out.println(Add.add(10, 20));
		System.out.println(Add.add(10, 20, 30));
	}
}

/*
 * Output:
 * 30
 * 60
 * 
 * Note: as you can see that both method called when their corresponding number
 * of args
 * are passed, this is called the Polymorphism with method overloading.
 */
