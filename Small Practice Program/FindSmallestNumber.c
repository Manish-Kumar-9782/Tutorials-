// In this section we will make a program to find out the smallest number presented in a list or array.

#include<stdio.h>

void main(){

    // Hamare pass ek array hain of size 10 ka.
    int numbers[10] = {23,33,45,20,67,45,19,87,45,5};
    
    // Hame sabse small value ko find out karna hain.
    // kyonki hame sabhi values ko check karna padega to hame ek for loop ki requirment hogi
    // and also, hame ek variable bhi chaahiye jime hum ek suppose ki hui smallest value ko store karenge.
    int smallest = numbers[0]; // hamne suppose kiya ki first value of array hi sabse choti hain. 
    // ab hum is value ke sath compare karenge.

    // 1. agar compare karte waqt hame ko smallest the small value milti hai to use hum samallest me daal denge 
    // 2. fir waps se uss new smallest value ke sath compare karenge jab tak ki sabhi values ke sath compare na ho jaye.

    int i;
    for(i=0; i<10; i++){

        // Comparing sabhi value with smallest.
        if(numbers[i]<smallest)
            // agar hame ek new value milit hain jo smallest se choti hain to hum smallest ko update karnge with new small value.
            smallest = numbers[i];

    }

    printf("Smallest value: %d", smallest);


}