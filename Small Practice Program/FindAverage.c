// In this program we need to find the average of the programs.
// in this program we will have a set of number in a array and we need to find the average of the numbers.

// Average find out karne ke liye hame do steps karni hain.
// 1. Add all the values of array.
// 2. divide the total sum by array size.
// print the result with "Average : xyz"

#include<stdio.h>

void main(){

    int arr[10] = {22,345,533,45,332,456,654,667,543,234};
    int i; // variable counter for for-loop
    int total_sum = 0; // total_sum variable jisme total sum store hoga
    // Note: Total sum ko zero karna zaruri hain, nhi to sum me garbage value show hogi.
    
    float average=0; // kyonki average points me hoga to 


    for(i=0; i<10; i++){
        // array me 10 values hai and array index 0 se suru hota hain to 0-9 10 values hoti hain.
        // so loop 9 tak chalega jo ki 9<10 hain.

        total_sum = total_sum + arr[i];

        // yha hum total_sum ko array ki values ke sath add kar rhe hain and usee wapas se total_sum variable
        // me store kar rahe hain.
        // arr[i]: isse hum accessing of array element kahate hain.
        // arr[i]: array name ke aage subscript bracket [] lgaa ke usme element ki position dal ke hum 
        // array ke element ko access kar sakate hain.

    }

    // Now, ab total_sum ko array ki size (or total number of element presents in array se divide karenge.)
    average = total_sum/10; // yha 10 array ki size (element presented in array) hain.

    // ab hum average ko print karenge.
    printf("Average: %.2f", average);

    // yha hum %.2f use kiya hain.
    // .2 ki help se hum result ko point ke baad 2 digits tak limit kar sakete hain jeese 20.10;

    // result without .2f
    printf("\nAverage: %f", average);
}