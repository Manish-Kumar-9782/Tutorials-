// In this section we will make a program to check that a number is Palindrom or not

/*

	Palindrom Number: A Palindrom number is number that is same after reverse.
	for example 545, 151, 34543, 343, 171, 48984 are called the palindorm number.

	We have also palindrom string like LOL, MADAM etc.	
*/

/*
	Steps to check that a number is palindrome or not:
	1. Get the number
	2. Hold the number in temp variable.
	3. Reverse the number.
	4. Compare the number with reversed one.
	5. if both number are same then the number is palindrom
	6. Else number is not palindrom.
*/

class PalindromNumber{


	/* now to check a number is palindrom or not we will make two
		static function.

		1. to reverse the number.
		2. to check the number.
	*/

	static int reverse(int number){
		// it will return the reversed number.

		int Number = number;
		int temp = 0;
		
		while (Number > 10){

			temp += (Number%10); 
			// first of all we will get the remainder and it will be saved in the temp.
			temp *= 10;
			// Now temp needed to be multiply by 10 so next digit will take place.
			// System.out.println("temp: "+ temp);
			Number = (int)(Number/10); 
			// Now we need to decrease the Number digits by dividing 10.


		}

		temp +=Number;  // adding the last value which is less than 10

		return temp;
	}


	// A function to check that a number is palindrom

	static boolean isPalindrom(int number){
		// check that a number is palindrom or not
		// if palindrom return true else false.

		int temp = reverse(number);
		
		if (temp == number){
			return true;
		}

		return false;
	}

	// ======================================================== //
	

	// Now we will make our main function

	public static void main(String[] args){

		System.out.println("is 34543 palindrom: "+ isPalindrom(34543));
	}

}
