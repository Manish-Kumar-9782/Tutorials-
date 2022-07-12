
// In this section we will make a program to show the fibonacci series.

// first of all we will make a class of FibonacciSeries in thata we will 
// define the fibonacci series funciton.

class FibonacciSeries{

	// Now we will make a function to get the fibonacci series
	static int fib1 = 0, fib2 = 1; 
	static int next_fib = 0;

	/*
	Note: here we should note that we have made the static function to use them
	direct without making an instance of the FibonacciSeries class.

	If we want to use a method from a class without creating it's instance then use
	*/

	// Example1
	static void FibonacciSeriesExample1(int _range){
		// here _range is the parameter to get the value that 
		//how much value do you need in the series.
		System.out.print(fib1 + " "+fib2);

		for(int i = 2; i<_range; i++){

			next_fib = fib2 + fib1;
			System.out.print(" "+next_fib);
			
			fib1 = fib2;
			fib2 = next_fib;
		}
	}

	// Example2
	// reseting all the three values
	
	static void FibonacciSeriesExample2(int count){

		if(count>0){

			if (fib1==0 && fib2==1){
				System.out.print(fib1+","+fib2);

			}
			
			next_fib = fib1 + fib2;
			fib1 = fib2;
			fib2 = next_fib;

			System.out.print(","+next_fib);
			FibonacciSeriesExample2(count-1);

		}
	}

	public static void main(String[] args){
		//Here we need to call the fibonacci series funciton.

		FibonacciSeriesExample2(10);

	}
}