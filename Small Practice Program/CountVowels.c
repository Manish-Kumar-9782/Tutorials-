// In this program we will make a program which will count the number of vowels present in a string 
// or in a line of text.

// maan leejie ki hamaare paas ek string hai (line of text)

// String: "Hello, This is C programming.";
// to ab, ham check karna chaahate hain ki is string mein kitane vowel present hain

#include<stdio.h>

void main(){

    // sabase pahale, ham ek string ko initialise karenge
    char String[] = "Hello, This is C programming.";
    // ab hame ek or array banana hain jo vowels ke letters ko contain karta hain. 
    // Iss array ka use letters ko compare karne me hoga
    char vowels[] = "aeiouAEIOU";

    // Now we will declare the required variable.
    int i,j,vowels_count=0;
    int StringSize, VowelSize;
    // i : i variable will  be used as a counter variable for for-loop.
    // j : j variable will  be used as a counter variable for for-loop.
    // vowels_count: this variable will be used to store the counted number of vowels present in the string. 

    StringSize = sizeof(String)/sizeof(String[0])-1;  // String ke size find out karne ke liye.
    VowelSize = sizeof(vowels)/sizeof(vowels[0])-1;  // Vowels ke array ke size find out karne ke liye.
    // Note: hamne null character '\0' ko -1 karke hata diya hain.

    for(i=0; i<StringSize; i++){
        // ye outer loop string ke har ek element ko access karne ke liye chalega.

        // ab ek or loop chahiye jo string ke har ek  letter ko vowels se sath compare karega.
        for(j=0; j<VowelSize; j++){
            // Ab hame String ke letter ko vowels ke letters ke sath compare karna hain,
            if(String[i] == vowels[j]){
                // agar hame ek match milta hain to vowels_count ko hum +1 karenege or inner loop ko break karenge.
                vowels_count++;
                break;
            } // end of if statement.
        }// end of inner loop

    }// end of outer loop

    // ab hame counted vowels print karne hain.
    printf("String: %s", String);
    printf("\nVowels Counted: %d", vowels_count); 

}// end of main loop