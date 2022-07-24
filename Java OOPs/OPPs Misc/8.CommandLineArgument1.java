/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that what are command line 
	argument and how to use them is our programs.

	Command Line Argument: The Java command-line argument is an argument 
	i.e passed at the time of running the java program.

	The arguments passed from the console can be received in the java program
	and it can be used as an input.	

	It provides a convenient way to check the behavior of the program for 
	the program for the different value. You can pass N (1,2,3 and so on) 
	number of arguments from the command prompt.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Simple example of command-line argument in java.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class Main{
	
	public static void main(String args[]){

		// all the runtime passed argument will be received by the 
		// args String object.
		System.out.println("Your first input argument: "+ args[0]);	
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*
	compile by --> javac 8.CommandLineArgument1.java
	run by ------> java Main hello


	Output:
	Your first input argument: Hello

	Here at the run time we can use any number of argument.
*/