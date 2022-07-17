/* In this section we will create a class of calcuation in from which we will
 calculate the factorial of a number.

	Anonymous Object:
		if you have to use an object only once, an anonymous object is a good approach.

*/

// a calculate class to calcualte the factoral of a number.
class Calculate{

	void fact(int n){

		int fact = 1;

		for(int i=1; i<=n; i++){
			fact *= i;
		}
		System.out.println("factorial of "+n+" : " +fact );
	}
}


class Main{

	public static void main(String args[]){

		// Here we will use the fact function form Calculate class
		// we will not store the instance of Calculate class instance in any variable.

		new Calculate().fact(4);
	}
}