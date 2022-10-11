
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
    Program: In this section we will see the Default Access Modifier and 
    its application in a class.
    
    Default: if we don't use any modifier, it is treated as default by default.
        The default modifier is accessible only within package. it cannit be 
        accessed from outside the package. it provides more accessibilit 
        than private. But, it is more restrictive than protected, and public.
*/

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/* Now we will make Simple class in which we will make a data member of
    and method which will be private. 
*/

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
package default_test_package;

class Test{
    // Here we will make a private constructor.

    int data = 80;
    void printdata(){
        System.out.println("data: " + data);
    }
}
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/

// Now we will make a Main class in which we will test our Test class
// with it's default data member and method.

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

class Main{
    
    public static void main(String args[]){

        // Now we will make an instance of the Test class

        Test test = new Test();
        System.out.println("test data: " + test.data);
        test.printdata(); 


    
    }
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*
    Output:
    test data: 80                                                                          
    data: 80                                                                               
         
    
    Note: we can access the default data member of class in it's own package 
    but we can't access them outside the package. 
*/