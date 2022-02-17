// In this progam will rotate an array by using the juggling method.
// in this method we devide our array into number of gcd of n and d.

/*
gcd: Here gcd is the greatest common diviser of n and d.
n: size of the arrray.
d: number of elements need to be rotated in an array.
*/

// Process of Juggling method of array rotation.
// 1. find the number of subset of an array.
// 2. copy first set (first element) in a temp array
// 3. left shift the first element of second set.
// 4. continue to left shifting of element of remaining elements.
// 5. if we reaches to the last set then copy the temp element to the final set.
// 6. repeat this process upto gcd number by using the outer loop.

/* For example:
lets suppose that we have an array of 9 element and we want to rotate the array by 3 elements.
int arr[] = {1,2,3,4,5,6,7,8,9};

in this case our n = 9, and d = 3;
their gcd is 3;

now we have the three sets of this array.
first set indexes: (0,3, 6) -> (1, 4, 7) elements
second set indexes: (1, 4, 7) -> (2, 5, 8) elements
third set indexes: (2, 5, 8) -> (3, 6, 9) elements

Now we will run a loop for every set which will track the positin of elements in every set.
 
for first round: (only for first set, other sets are also processed in same way.)
1. we will copy first 0-th element into a temp varaible.
2. now we will make j=i, which will track the index of element in firts set at which we will left shift the element.
3. we will also make k = j+d; which will track the index of elements in first set elements index  which we will be shifted to left side.
4. by doing this we will store 0th elements into temp, 3rd -> 0th, 6th -> 3rd and temp -> 6th,
5. by doing above process we can successfully rotate the first set.
6. repeate this process for other sets also, all process are same except their index value (i, j, k); 

*/

#include<stdio.h>

// first of all we will make a function which will find the gcd value of two integers.

int GCD(int a, int b){
    // here a and b are two integer values.

    int i, gcd=0;
    if (a<b){

        for(i=a; i>=1; i--){
            if(a%i == 0 && b%i == 0)
                return i;
        }
       // return 1;

    }
    else{
        // if a < b then we will swap the values.
        int temp = a;
        a = b;
        b = temp;

        // and return to the program.
        GCD(a,b);

    }
}

// after finding the gcd value we need to make a array roatation function.

void ArrayRotate(int arr[], int ArraySize, int RotateUpto){

    /*
    arr[]: it is the array which is going to be roatated.
    ArraySize: it the size of the array which is going to be passed inside the function.
    RoatteUpto: This parameters is used to define that how much element need to be rotated.
    */

   // Now first we will get the gcd value.

   int d, n; // for simplicity we are making two more extra integer varaible 

   d = RotateUpto; // d will be used to show how many elements are we going to rotate.
   n = ArraySize;  // n will be used to show array size.
   int gcd; 
   gcd = GCD(n, d); // this will give us the gcd value.

   // Now after finding we need to declare some variable which will track the 

   int i, j, k, temp;

   /*
   i: it is the counter variable for outer loop which will track the number of elements needed to rotate.
   
   j: it is the index number of the element in a set in which elements are going to shift. 
    (we can say this is the index number of element in right side subset from we are going to move element. )
   
   k: it is the index number of the element in a set from which elements are going to shift towards left side.
    (we can say this is the index number of element in left side subset in which we are going to place element. )
   
   temp: it is a variable which will hold the elements of first set which are need to put at the tail of the array.   
   */

  d = d % n; // checking that d < n 

  // Now we will run a for loop which will track the position of elements which needed to rotate.

  for(i=0; i<gcd; i++){

      // now we need to put the i-th elmeent into the temp variable.
    temp = arr[i];
    j = i; // initiating the j which will track index of the element present in a subset in which we move the element.
    // now we need to make anoter loop which will be used to shift and track the subsets.

    while(1){
        // we will shift and move to next subset until we dont reach at last subset.

        // now we need to move next subset by using d, d contains the number of elements in per subset.
        k = j+d; // initiaing the k which will track the index of the element present in a subset from 
                 //which we move the element towards left subset.

        // if k, (which is the index number of the element which is going to left shift.)
        // is greater or equal to n, then we will minus k by n, which will reset the k for next round of left shift.
        if(k >=n ) 
            k = k-n;
        
        // if k becomes the same index as i then we will stop the left shift in each round.
        if(k == i)
            break;

        // Now we will shift the element from left subset to right subset.
        arr[j] = arr[k];
        j = k; // after shifting we j moves to the next subset, and k also moves to the next subset if available
        
    }
    arr[j] = temp; // after end of the each round of left shifting we will put the temp variable
                   // at the position of j-th index which will be the index in the last subset (tail of the array).
  }

}


void ArrayPrint(int arr[], int ArraySize){

    /*
    arr: it is the array which is need to be printed.
    ArraySize: it is the size of the array.
    */
   int i;
   for(i=0; i<ArraySize; i++)
    printf("%d ", arr[i]);

}

// here Now we will make the main function and in this function we will call the Roatation function to rotate the array.
void main(){

// Declaring the array.
int n = 9, d = 3;
int arr[] = {1,2,3,4,5,6,7,8,9};

printf("Array before the Rotation: ");
ArrayPrint(arr,n);

ArrayRotate(arr, n, d);

printf("\n\nArray after the Rotation: ");
ArrayPrint(arr,n);

}