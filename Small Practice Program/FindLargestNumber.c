// In this section we will make a program to find out the Largest number presented in a list or array.

#include<stdio.h>

void main(){

    // Hamare pass ek array hain of size 10 ka.
    int numbers[10] = {23,201,45,92,67,45,19,87,45,503};
    
    // Hame sabse Largest value ko find out karna hain.
    // kyonki hame sabhi values ko check karna padega to hame ek for loop ki requirment hogi
    // and also, hame ek variable bhi chaahiye jime hum ek suppose ki hui largest value ko store karenge.
    int largest = numbers[0]; // hamne suppose kiya ki first value of array hi sabse choti hain. 
    // ab hum is value ke sath compare karenge.

    // 1. agar compare karte waqt hame ko largest se large value milti hai to use hum largest(variable) me daal denge 
    // 2. fir waps se uss new largest) value ke sath compare karenge jab tak ki sabhi values ke sath compare na ho jaye.

    int i;
    for(i=0; i<10; i++){

        // Comparing sabhi value with largest.
        if(numbers[i]>largest)
            // agar hame ek new value milit hain jo largest se large hain to hum largest ko update karnge with new large value.
            largest = numbers[i];

    }

    printf("largest value: %d", largest);


}