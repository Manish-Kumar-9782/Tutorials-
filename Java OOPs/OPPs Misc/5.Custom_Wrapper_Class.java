/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
	Program: In this section we will make a custom wrapper class which will
	convert a primitive data type to object.	
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a CustomWrapper class.

class CustomWarpper{

	// In this class we will pack the integer type primitive.

	private int i;

	//Now we need a constructor

	CustomWarpper(int i){
		this.i = i;
	}

	// Now we will make getter and setter methods

	public int getValue(){return i;}

	public void setValue(int i){this.i = i;}

	// Now we will override the toString() method of object class
	public String toString(){
		return Integer.toString(i);
	}
}

// Now we will test this CustomWrapper Class

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class Main{
	
	public static void main(String args[]){

		// Now here we will make an instance of the CustomWrapper
		CustomWarpper  obj = new CustomWarpper(38);

		// Now we will use the print	
		System.out.println(obj);

		// this println method will call the toString() method of object.
	}
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

