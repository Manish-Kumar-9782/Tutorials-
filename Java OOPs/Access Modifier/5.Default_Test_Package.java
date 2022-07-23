
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

/*
    Program: In this section we will try to access the default data 
    members from other package.
    
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

import default_test_package.Test;

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
class InTest{
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

        Test out_test = new Test();  // imported test
 
        InTest in_test = new InTest(); // defined here.

        // Now we will access outside data default members.
        System.out.println("accessing from outside Test: " + out_test.data);
        System.out.println("Accessing from inside Test: "+ in_test.data);

    
    }
}

/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*
    Output:
    error: Test is not public in default_test_package; cannot be accessed from outside package                                                    
    import default_test_package.Test;                                                      
                               ^                                                           
    5.Default_Test_Package.java:48: error: cannot access Test                              
            Test out_test = new Test();  // imported test                                  
            ^                                                                              
      bad class file: .\Test.class                                                         
        class file contains wrong class: default_test_package.Test                         
        Please remove or make sure it appears in the correct subdirectory of the classpath.
    
    Note: Here Test class is not public that's why we cannot access it from outside the package.
    this Test class has access modifier as defalut.
*/