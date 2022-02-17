// In this section we will define a typedef structure in which we can call the defined structure with a diffent name.

/*

Suppose taht you want to define a structure to put together some attribute of students and use them in a program 
So for that we can make a structure of Student as defined below.

struct Student
{
    char Name[20];
    int age;
    float height; // in cm
    char address[50];
    char PhoneNumber[10]; 
};


But problem with this is that , if we want to declare a varaible of this data type then we need to type whole thing
like: struct Student student1;

-> Now suppose that instead of this name we just want to type an allias name like stud, std, stu etc.
-> To use this kind of allias name we need to use typedef structure which make an allias name of the structure data type.
*/

#include<stdio.h>

// Now since we want to make a typedef structure we will use typedef keyword.

typedef struct Student
{
    char Name[20];
    int age;
    float height; // in cm
    char address[50];
    char PhoneNumber[10]; 
   
   // Now we need to make an allias name after the end block with semicolon.  
}stu; // naming the sturcture as stu.

// Now we can declare variable by using the stu variables.

#include<stdio.h>

void main()
{
    stu student1;

    // we can also initialize any stu variable during the compile time like this.
    stu student2 = {"Manish Kumar",
                    25,
                    173.56,
                    "Plot number 21 keshwanand colony",
                    "8955530880"};
    
    // and we can initialize the student1 at run time by inputting the values from the user.

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

    printf("\nStudent-1 name is    : %s", student1.Name);
    printf("\nStudent-1 Age is     : %d", student1.age);
    printf("\nStudent-1 address is : %s", student1.address);
    printf("\nStudent-1 Phone NO.  : %s", student1.PhoneNumber);
    printf("\nStudent-1 height is  : %f", student1.height);

    // separing both student by newline.
    printf("\n");

    printf("\nStudent-2 name is    : %s", student2.Name);
    printf("\nStudent-2 Age is     : %d", student2.age);
    printf("\nStudent-2 address is : %s", student2.address);
    printf("\nStudent-2 Phone NO.  : %s", student2.PhoneNumber);
    printf("\nStudent-2 height is  : %f", student2.height);

}