
// In this section we will make a program to check that a number is Armstrongs.

/*
	Armstrong Number:
		An Armstrong number is a postive m-digit number that is equal to the sum
		of the m-th powers of their digits. it is also known as pluperfect, or Plus Perfect, or Narcissistic number.
		it is an OEIS sequence A005188.
*/

class ArmstrongNumber{

	// 1. A Method to compute that how many digits in a numbers.
	static int getNumberDigits(int number){
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

	public static void main(String[] args){

		// In this section we will use the 

		System.out.println("Number of digits in 12345: " + getNumberDigits(12345));
		// String str = String.valueOf(12345);
		// System.out.println("pow: " + Math.pow(10,2));
		System.out.println("exponent sum: "+ getExponentSum(1234, 4));

	}
}