// In this section we will make a program to check that a letter is vowel or not.

// vowel letters: a, e, i, o, u, A, E, I, O, U;
// ye sabhi letters jo hain vowel hain.

// agar input kiya huaa letter inme se match hota hain to ham print karenge.
// "Input letter is a vowel!"

// agar input kiya huaa letter inme se match nhi hota hain to ham print karenge.
// "Input letter is no a vowel!"

// vowel letters ko hum ek array me store karnge jisse hum har ek letter ko match kara sake with the help of for loop.

#include<stdio.h>

void main(){

    char vowels[] = "aeiouAEIOU";
    // above array is saved in the form of: a, e, i, o, u, A, E, I, O, U;

    char inputchar; // user se input liya hua character store karne ke liye.
    int isvowel=0; // Ye variable show karegaa ki inputchar vowel hain ki nhi.

    // isvowel = 0; hain it means inputchar vowel nhi hain.
    // isvowel = 1; hain it means inputchar vowel hain.


    int i; // for for-loop;

    // ab hum user se input lenge;
    printf("Enter a character : ");
    scanf("%c", &inputchar);

    // Ab hum inputchar ko vowels array characters se compare krayenge.

    for(i=0; i<9; i++){

        // ab hum vowels array ke element ko access karenge with the help of subscript vowel[].
        // matching the inputchar with vowels array characters
        if(inputchar == vowels[i])
        {
            isvowel = 1;
            break;  // agar ek bhi character match hota hain to hum loop ko break karenge.
            // kyon ki ek bhi character match hone ka matlab hain ki inputchar ek vowel hain.
        }
            
    }

    // loop se exit hone ke baad hum isvowel ko check karenge.

    if(isvowel)
        printf("Input letter is a vowel!\n");
    else
        printf("Input letter is no a vowel!\n");

}