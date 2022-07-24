/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will see that how to pass multiple argument
	and how to handle them.

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

		// To read multiple argumen we need to use the loop
		// here we will use the for loop

		for(int i=0; i<args.length; i++){
			System.out.println("Your "+ i + " input argument: "+ args[i]);	
		}
		
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*
	compile by --> javac 8.CommandLineArgument1.java
	run by ------> 	java Main Hello 8 this is -d delete all 


	Output:                                                                      
	Your 0 input argument: Hello                                                           
	Your 1 input argument: 8                                                               
	Your 2 input argument: this                                                            
	Your 3 input argument: is                                                              
	Your 4 input argument: -d                                                              
	Your 5 input argument: delete                                                          
	Your 6 input argument: all 

	Here we have passed multiple argument which is read by the args[] 
	of main function and access by using the for loop.
*/