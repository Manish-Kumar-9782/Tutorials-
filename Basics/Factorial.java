// In this section we will make a program to compute the factorial of given number.

/*
	factorial: 
	4! = 4*3*2*1 = 24  
	5! = 5*4*3*2*1 = 120  
*/

class Factorial{

	// Now we will make here function to compute the factorial of a given number.

	// 1. Factorial by using for loop

	static int getFactorialExample1(int number){
		// number: number for which compute the factorial.

		if (number == 0){
			return 1;
		}

		int fact = 1;  // Note : a factorial cannot be zero.
		
		for(int i = 1; i<=number; i++){

			fact *= i;
		}

		return fact;
	}

	// ----------------------------------------------------- /

	// 2. Factorial by using the recursion.
	static int getFactorialExample2(int number){

		if(number == 0){
			return 1;
		}

		return(number*getFactorialExample2(number-1));
	}

	public static void main(String[] args){
		
		// factorial by using getFactorialExample1;
		// System.out.println("Factorial of 4: " + getFactorialExample1(4));

		// factorial by using getFactorialExample2;
		System.out.println("Factorial of 4: "+ getFactorialExample2(4));
	}
}