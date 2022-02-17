// in this section we will see that how can we use a differnt type of data types by using a single name.
// we can do this by using the structure in c.
// structures: structures are user-definied data type in which we defines the defination of the \
// structure according to our need like a function.

// In this section we will make a Student structure in which we will make attributes related to the a student.

#include<stdio.h>

// defining a structure by using the keyword struct.

struct Student
{
    char Name[20];
    int age;
    float height; // in cm
    char address[50];
    char PhoneNumber[10]; 
};

// char Name, int age, float heiht ... etc are called the member of the structure type of struct Student.
// structure must be ended by the semicolon.
// Note: memory is not allocated to the structure defination until we dont make a variable of data type struct Student.

void main()
{

    // Now we will make a variable of struct Student  type which will have all the attributes which is defined in the defination.
    // declaring the variable by using the struct Student type.
    struct Student student1;

    // now we have made a variable as named student1;
    // now we will input some data according to their data types.
    // first of all we will input all the char type data by using the gets() function.

    // Note: we will access the student attributes by using the dot operator (.) or we can call it memeber operator.

    printf("Enter Your name: ");
    gets(student1.Name);

    printf("Enter your address: ");
    gets(student1.address);

    printf("Enter your phone number: ");
    gets(student1.PhoneNumber);

    printf("Enter your age: ");
    scanf("%d", &student1.age);

    printf("Enter your height: ");
    scanf("%f", &student1.height);


 // Now we will print all the stored (inputed values in the student1 attributes.)

 printf("\nYour name is    : %s", student1.Name);
 printf("\nYour Age is     : %d", student1.age);
 printf("\nYour address is : %s", student1.address);
 printf("\nYour Phone NO.  : %s", student1.PhoneNumber);
 printf("\nYour height is  : %f", student1.height);

// Now in this way we can store multiple data type information under a single variable.

}