#include<iostream>

using namespace std;

int main(){

    printf("Hellow world");
    int arr[5]{1,2,3,4,5};

    arr[6]= 56;

    printf("array 6th pos elem: %d", arr[6]);
    return 0;
}