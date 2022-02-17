
#include<stdio.h>
    
int partition (int arr[], int low, int high)
{
   // Your code here
   printf("\narr Low: %d", arr[low]);
   int temp;
   int pivot = arr[low];
   int start, end;
   start = low;
   end = high;
   
   while(start <=end){
       
       while(arr[start] <= pivot){
       
            start++;
       }
       
       while(arr[end] > pivot){
            end--;
       }
       
       if(start < end){
        
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
       }
   }
   
    if(start > end){
        
        temp = arr[low];
        arr[low] = arr[end];
        arr[end] = temp;
    }
    
    return end;
   
}

void quickSort(int arr[], int low, int high)
{
    // code here
    if(low< high){
    	
	    int loc = partition(arr, low, high);
	    
	    quickSort(arr, low, loc-1);
	    quickSort(arr, loc+1, high);
	
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



void main(){
	
int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};

printf("Array befor sorting:	");
ArrayPrint(arr, 9);

quickSort(arr, 0, 8);

printf("Array after Sorting:	");
ArrayPrint(arr, 9);

}
