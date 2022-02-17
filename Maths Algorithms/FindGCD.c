// In this program we will find the gcd (greatest common diviser) of two value.

// Since our function will return integer type value so we need to make a integer type function.

#include<stdio.h>

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

void main(){

    int n = 7, d=2;
    int gcd;
    gcd = GCD(n,d);

    printf("GCD of %d and %d is:  %d", n, d, gcd);
    printf("\nd = d %% n = %d", d%n);
}