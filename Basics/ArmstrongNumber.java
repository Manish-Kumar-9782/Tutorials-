
// In this section we will make a program to check that a number is Armstrongs.

/*
	Armstrong Number:
		An Armstrong number is a postive m-digit number that is equal to the sum
		of the m-th powers of their digits. it is also known as pluperfect, or Plus Perfect, or Narcissistic number.
		it is an OEIS sequence A005188.
*/

import java.util.Scanner;

class ArmstrongNumber{

	// 1. A Method to compute that how many digits in a numbers.
	static int getNumberDigits(int number){

		/**
		 * A fuction to get the number of digits in a number
		 */

		// to get the number of digits in a number.

		int Number = number;
		int count = 0;

		while(Number > 10){

			Number = (int)(Number/10);  // decrease the number of digits.
			count++;  // increase the count to
		}
		count++; // to also add the last number of digit.

		return count;
	}

	// ----------------------------------------------------------- //

	// 1.1 count the number of digits in a number by converting it into string.

	static int getNumberDigits2(int number){

		/**
		 * A functiont
		 */

		// Now in this first of all we will convert the int into String.
		String str = String.valueOf(number);

		// NOw we will return the length of the string.
		return str.length();
	}


	// 2. Now we will compute the sum of it's digits exponent (length)

	static int getExponentSum(int number, int pow){

		// number: a number from which we need to extract the digits and get the sum
		// pow: it is the exponent number of each digits from number.

		int Number = number;
		int result = 0;

		while(Number > 10){

			result += Math.pow((Number%10), pow);

			Number = (int)(Number/10);
		}

		result += Math.pow(Number, pow);
		return result;
	}

	// Now we will make final function to check that a number is armstrong or not 
	static boolean isArmStrong(int number){

		int n_digits = getNumberDigits(number);
		int sum = getExponentSum(number, n_digits);

		if (sum == number)
			return true;

		return false;
	}


	public static void main(String[] args){

		// In this section we will use the 

		System.out.println("Number of digits in 12345: " + getNumberDigits(12345));
		// String str = String.valueOf(12345);
		// System.out.println("pow: " + Math.pow(10,2));
		
		String input = new String();

		Scanner read = new Scanner(System.in);

		while(!input.equals("q")){

			System.out.print("\n\nis ArmStrong Number: ");
			input = read.nextLine();

			if(!input.equals("q")){
				System.out.print(isArmStrong(Integer.parseInt(input)));
				}

		}
	}
}