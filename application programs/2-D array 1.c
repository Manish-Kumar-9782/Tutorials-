/* Write a program using two-dimensional array to compute and print the following 
information from the table. 

	1. Total value of sales by each girl.
	2. total value of each item sold.
	3. Grand total sales of all items by all girls.
	
*/

// Solution: in this we need to make a 2-d array in which row will define the total number of girls
//			  and columns will define total number of items and intersection of row and column will define
// 			item sold by a girl.


#include<stdio.h>

#define MAXGIRLS 4  // limiting the grils
#define MAXITEMS 3  // limiting the itmes.

void main(){
	
	// now we need to make a 2-d array which can hold both the girls and items.
	
	// in this program we need to calculate three values.
	// total value of sales by each girl.
	// total value of each item sold.
	// grand total sales by all items sold by all girls.
	
	int value[MAXGIRLS][MAXITEMS];
	int girls_total[MAXGIRLS], items_total[MAXITEMS];
	int grand_total=0;
	int i, j; // here i and j will represent the number of girl and item respectively.
	// girsl_total will hold sold value of per items.
	// items_total will hold total value of a item by all girls.
	
	// Now we need to read all values and computing the girls_total
	
	//-----------------READING DATA-----------------------//
	
	printf("Input data\n");
	printf("Enter values, one at a time, row-wis\n");
	
	for(i=0; i<MAXGIRLS; i++){
		girls_total[i]= 0;
		// outer loop will track each girls.
		for(j=0; j<MAXITEMS; j++){
			// inner loop will track each item
			
			scanf("%d", &value[i][j]);
			// Now after scanning each item we need to compute the girls total
			girls_total[i] += value[i][j];
			// here i represent the number of the girl
			// and j represent the number of item.
		}
	}
	
	
	//--------------------COMPUTING THE ITEMS TOTAL------------//
	
	// Now we will compute the total of items by each item.
	
	for(j=0; j<MAXITEMS; j++){
		
		// this loop will track the items in the table.
		
		items_total[j] = 0;
		
		for(i=0; i<MAXGIRLS; i++){
			// now we need to access the each value by all girls.
			
			items_total[j] += value[i][j]; // in this we will compute the total of each item.
		}
	}
	
	
	//-------------------------COMPUTING THE GRAND TOTAL---------------//
	// Grand total is the sum of all itmes.
	
	for(i=0; i<MAXGIRLS; i++)
		grand_total += girls_total[i];
		
	
	//---------------------------	PRINTING THE RESULT-------------------//
	// Now we need to print the result which we have computed.
	
	printf("GIRLS TOTALS\n");
	
	for(i=0; i<MAXGIRLS; i++)
		printf("Salesgirl (%d) = %d \n", i+1, girls_total[i]);
	
	printf("\n ITEMS TOTAL \n");
	
	for(j=0; j<MAXITEMS; j++)
		printf("Items (%d) = %d \n", j+1, items_total[j]);
		
	//printf("\n GRAND TOTAL \n ");
	
	printf("\n Grand Total = %d\n", grand_total);
	
}
