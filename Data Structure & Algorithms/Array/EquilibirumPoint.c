/* Equilibrium Point:
    Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
    Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:

    Input: 
    n = 5 
    A[] = {1,3,5,2,2} 
    Output: 3 
    Explanation: For second test case 
    equilibrium point is at position 3 
    as elements before it (1+3) = 
    elements after it (2+2). 
 
Example 2:

    Input:
    n = 1
    A[] = {1}
    Output: 1
    Explanation:
    Since its the only element hence
    its the only equilibrium point.
*/

#include<stdio.h>

int getsum(int arr[], int lb, int ub){

    // This method will be used to get calculate the sum of the integer within the range.

    int i;
    int sum=0;

    for(i=lb; i<ub; i++){
        sum += arr[i];
    }

    return sum;
}

int EquilibriumPoint(int arr[], int n){

    
    if(n == 1)
        return 1;

    int i, sum1 = 0, sum2 = 0;
    for(i=1; i<n; i++){

        sum1 = getsum(arr, 0, i);
        sum2 = getsum(arr, i+1, n);

        printf("\nsum at i %d", i);
        printf("\nsum1 : %d     sum2 : %d\n", sum1, sum2);
        if(sum1 == sum2)
            return i;

    }
    return -1;

    
}

void main(){
    
    int arr[] = {1,2,7,10,6,4};
    int eqPoint;
    eqPoint = EquilibriumPoint(arr, 6);

    printf("\nEq Point: %d\n", eqPoint);

}