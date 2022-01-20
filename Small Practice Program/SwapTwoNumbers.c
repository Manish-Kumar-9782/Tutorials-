// In this section we will  make a swap program which is very useful in many computer problems.
/*
    Process of swap Program:

        Suppose karo ki hamare pass do values variable hain 'a' and 'b'.
        
        a = 300;
        b=500;

        -> ab hume a = 500 and b = 300 karna hain  bina kisi new value assignment.
        -> To ab hame ek new variable chahiye jiseme haum a ko store kara sake. let's say that ye variable 'temp' hain.
        -> Ab hum 'a' ko temp me,  'b' ko 'a' me,  and  'temp' ko 'b' me store karenge is process ko swap bolte hain,

        temp = a;
        a = b;
        b = a;

*/

#include<stdio.h>

void main(){

    int a = 100, b = 500;
    int temp;

    // phle hum a and b ki values ko print karenge jisse hum compare kar paayenge 
    printf("a and b vales before swap:  \na = %d \nb = %d", a, b);

    // Ab hame swap karna hain.
    // Step 1. a ko temp me store karo
    temp = a;

    // Step 2. b ko a me store karo;
    a = b;

    // Step 3. temp ko b me stroe karo;
    b = temp;

    printf("\n\na and b vales after swap:  \na = %d \nb = %d", a, b);

}