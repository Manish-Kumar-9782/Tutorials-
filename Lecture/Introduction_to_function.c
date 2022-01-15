// In this lecture we will see the what are the function and how we can use function in our program & and how they are usefull.

/* Definition: function is a set of statement which are executed in sequential order are put together in a block by a name 
   which is called name of function, we can use this function again and again without typing those codes again.
   
   In C Programming we have three step to setup a function for use.

   1. Declaration: first of all we need to declare the name and type of the function with its parameter list.
   2. Definition: after declaration we need to define its body according to our desired resutl.
   3. Call: after declaration and proper definition we can make a call to the function which is defined.
    
    
   Function can be divide in four types:
   1. No Return & No Arguments
   2. No Return & Arguments
   3. Return & No Arguments
   4. Return with Arguments 
   
   Now we will declaration and define them make thier uses.*/

   #include<stdio.h>
   #define PI 3.14

   int radius=4, height=5;

/*===============================================DECLARATION OF ALL FOUR TYPE OF FUNCITON============================  */
    // Now first of all we will declare all four type of function.

    /*1. No return value with no arguments: This type of function do not take any arguments 
        and also they do not return any type of value*/ 

    void print_line();

    /*2. No return value with some arguments: this type of function do take one or more arguments
        but don't return any value.*/

    void your_name(char []);

    /*3. Return with no arguments: this type of function return specified type of value but do not take 
        any arguments.*/
    
    float cylinder_volume();

    /*4. Return with arguments: this type of function return specified type of values and also take 
        one or more arguments.*/

    float sphere_volume(float);


    // all function are defined blelow the main function.
/*===================================================MAIN FUNCTION============================================================*/
   int main(){
        // first of all we will print a line by using no arguments and no return type of funciton.d
        system("cls"); // This line is used to clear the output screen.
        printf("Program output\n\n"); // This line is used to show that our program is started from here


/*---------------------------------------NO RETURN NO ARGUMENTS---------------------------------------------------------------*/       
       // 1. using no argument and no return type function.
        print_line();


/*---------------------------------------NO RETURN ONE ARGUMENTS---------------------------------------------------------------*/
        // 2.  using no return type but one arguments function.
        char name[12];
        printf("\n\nEnter your name:");
        gets(name);

        // now we will put this name into the your_name function.
        your_name(name); // this will show name with some texts.

/*---------------------------------------RETURN NO ARGUMENTS---------------------------------------------------------------*/
        // 3. Using return type but no argument type function.
        // since it will return someting so we need a variable of same type of returned value to hold that valeu.
        // since cylinder_volume will return float type of value we need to make a float type of variable to store the value.
        float volume =0;
        volume = cylinder_volume();
        // NOw we will show the return value
        printf("\n\nCylinder volume is : %f\n\n", volume);


/*---------------------------------------RETURN WITH ARGUMENTS---------------------------------------------------------------*/
        // 4. Using return type with one argument;
        // Since, in this we will return a value and also we will take some input from outside (by user) 
        // this type of function provide us the advance computation ability to take care of outside data 
        // and send them outside the function body.

        // in this we will use sphere_volume function. 
        // Since, sphere_volume will return a float type value we will use already defined volume variable.
        // we will ask form the user to set the radious of the sphere
        float radius=0;
        printf("\n\nEnter sphere radius: ");
        scanf("%f",&radius);
        volume = sphere_volume(radius);
        printf("Your sphere volume is: %f", volume);

        printf("\n\n\nEnd of program:"); // This line is used to show that our program has ended.
        return 0;
   }

/*======================================DEFINITION OF ALL FOUR TYPE OF FUNCTION==============================================*/

    // 1. Definition of no return and no arguments type function.
   void print_line(){

       // Since this function does not takes any thing form outside of it and also does not return anything
       // it means it will compute somthing on a global variable 
       // we can also use this type of program to set some specific type of pattern on the screen.

       printf("_______________________________________________________________\n");


       // we can also make some specified pattern with this kind of function again and again.
   }

    // 2. Definition of no return and one arguments type function.
   void your_name(char name[]){

       // This program take some arguements but do not return any thing this kind of function are used to modify 
       // the data or to same them in the memory, since they take arguments so they can access outside variable.
       // in this we will tak a name from the user and we aill print it with more texts.

       printf("Hello, Your name is %s nice to meet your. \n\n", name); 

   }

   // 3. Definition of return but no arguments.

   float cylinder_volume(){

       // Since this function does not take any value from out side but it return some value.
       // this kind of funciton are used to make some compution on data which are stored in local storage.
       // or also to make some compution on the global variable and return the computed value.

       // For our example we can use our globally defined variables.

       float volume=0;

       volume = PI*radius*radius*height;

       // now we can return this value by using return keyword.
       return volume;
       // Note: function can only return same type of value as it defined on function return type.

   }


    //4.  Definition of return with arguments;

float sphere_volume(float r){

    // This type of function are used mostely in daily life problem as we can see in this.
    // suppose that we want to compute the sphere volume which dimensions are defined from outside of this program
    // and also we need to get the computed result and to send somewhere, in this situation we need to get the input
    // and return the output.

    // for our explanation we will take only an example of volume of sphere.
    printf("Entered radius: %f\n", r);
    float volume = 0;

    volume = (3*PI*r*r*r)/4;

    printf("Computed volumne: %f\n", volume);
    return volume;
}










