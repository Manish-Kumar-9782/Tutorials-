// In this section we will see that how to format our number values
// we need to import the NumberFormat class from java text

import java.text.NumberFormat;
import java.util.Locale;

class NumberFormatter{

	public static void main(String[] args){

		// Now we we will create an instance of the NumberFormat 
		NumberFormat format_number = NumberFormat.getCurrencyInstance(Locale.US);
		String fnumber = format_number.format(123.456);
		System.out.println("Formatted number: "+ fnumber);
	}
}
