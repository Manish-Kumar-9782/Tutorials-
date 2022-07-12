
import java.text.NumberFormat;
import java.util.Scanner;
import java.util.Locale;

class MortgageCalculator{

	// Now we need to define the four variables
	// 1. Monthly payment
	// 2. principal
	// 3. rate.
	// 4. number of payment.

	public static void main(String[] args){

		int principal = 0;
		final byte MONTHS_IN_YEAR = 12;
		final byte PERCENT = 100;
		double annual_interest = 0.0;
		int n_payment = 0;

		// Now we need ot read all the values for the user.
		// for that we need to use the Scanner.
		Scanner read = new Scanner(System.in);
		// here in this we need to give the System.in attribute 
		// if we want to read the input value from user via console.

		System.out.print("Enter the Principal Amount:");
		principal = read.nextInt();  // read integer data type from user.

		System.out.print("Enter the Annual Interset Rate: ");
		annual_interest = read.nextFloat(); 	// read float data type from user.
		
		// Now we need to convert the annual interset rate to monthly interest rate.
		double monthly_interest = annual_interest/PERCENT/MONTHS_IN_YEAR;


		System.out.print("Enter Period (Years): ");
		n_payment = read.nextInt();  // read integer data type from user.

		// total number of payment in months.
		n_payment *= MONTHS_IN_YEAR;
	
		double Mortgage = principal 
			 * (monthly_interest * Math.pow(1+monthly_interest, n_payment))
			 /(Math.pow(1+monthly_interest, n_payment) - 1);

		String MortgageFormatted = NumberFormat.getCurrencyInstance(Locale.US).format(Mortgage);
		System.out.println("Calculated Mortgage Value: "+ MortgageFormatted);
	}
}