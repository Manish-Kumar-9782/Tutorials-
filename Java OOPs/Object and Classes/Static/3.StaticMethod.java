// In this section we will see that how can we use class methods without creating an instance of that class.


/*
	We can only access the static methods from the class without creating its instacne.
	So in this section we will make a Calculation class to calculate some math problem.
	like square, qube, add, etc
*/

class Calculate{

	static int add(int a, int b){return a+b;}

	static int square(int a){return a*a;}

	static int cube(int a){return a*a*a;}
}

// Now we will use these method without creating the Calculate class object

class Main{

	public static void main(String args[]){

		// using static method without creating the Calcuate class.
		System.out.println("addition of 2,3: "+ Calculate.add(2,3));
		System.out.println("square of 2: "+ Calculate.square(2));
		System.out.println("cube of 2: "+ Calculate.cube(2));
	}
}