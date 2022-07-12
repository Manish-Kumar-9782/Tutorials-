
// In this section we will make a program to get the prime number

/*
	PrimeNumber: Prime number in java: Prime number is a number that is greater tahn 
	1 and divided by 1 or itself only. in other word, prime number can't be dividd by other number
	than itself or 1. For example 2, 3, 5, 7, 11, 13, 17... etc.
*/

import java.util.Scanner;  // Scanner to get the user input from the user.


class PrimeNumber{


	// Now here we will define the Static method to compute the PrimeNumbers

	static boolean PrimeNumberExample(int number){
		/** 
		 check that a number is prime or not.
		 number: number to be checked as the prime number.
		*/


		if (number==0 || number==1){
			return false;  // number 0 and 1 are not prime number.
		}

		// Now we will check that a number is devidable with 2 or not.
		for(int i=2; i<number; i++){

			if(number % i == 0){
				return false;
			}
		}

		return true;
	}

	// ---------------------------------------------------------- //

	static void getPrimeNumbers(int start, int end){
		// get all the prime number b/w start and end numbers.

		for(int i = start; i<=end; i++){

			if (PrimeNumberExample(i)){

				System.out.print(i+ " ");
			}

		}
	}

	public static void main(String[] args){

		System.out.println("is 2 prime number: "+ PrimeNumberExample(2));


		Scanner read = new Scanner(System.in);

		System.out.print("Enter the firt number: ");
		int start = read.nextInt();

		System.out.print("Enter the second number: ");
		int end = read.nextInt();
		
		getPrimeNumbers(start, end);

		
	}
}