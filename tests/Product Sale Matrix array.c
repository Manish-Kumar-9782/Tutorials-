//  Suppose that we have four girls in marketing to sale three products, they all have same three product.

// compute: Total value sales by each girl
// copmpute: Total value of each items sold.
// compute: grand total;

#include<stdio.h>
#include<time.h>
void main(){


// girl1, girl2, girl3, gril4;
// product1, product2, product3

	int Sales[4][3] = { {310,275,365},
						{210,190,325},
						{405,235,240},
						{260,300,380}
						};
						
	int Grand_Total = 0;
	int Girls_Sales[4] = {0,0,0,0};
	int Product_Sales[3] = {0,0,0};
	int i,j;
	//---------------------------------------------SALE BY EACH GIRL----------------------------------------//
	
	for(i=0; i<4; i++){
		
		for(j=0; j<3; j++){
			Girls_Sales[i] += Sales[i][j];
		}
	}
	
	
	//---------------------------------------------EACH PRODUCT SALE ----------------------------------------//	
	
	for(i=0; i<3; i++){
		
		for(j=0; j<4; j++){
			
			Product_Sales[i] += Sales[j][i];
		}
	}
	
	//---------------------------------------------GRAND TOTAL ----------------------------------------//
	
	for(i=0; i<3; i++){
		
		Grand_Total += Product_Sales[i];	
	}
	
	
	printf("\n-----------------------------------TOTAL SALE BY EACH GIRLS------------------------------------\n");
	
		for(i=0; i<4; i++){
		
		printf("Grils %d Sale:  %d \n", i,Girls_Sales[i]);	
	}
	printf("\n\n");
	
	printf("\n-----------------------------------TOTAL SALE OF EACH PRODUCT------------------------------------\n");
		for(i=0; i<3; i++){
		
		printf("Product %d Sale: %d \n", i, Product_Sales[i]);	
	}
	printf("\n\n");
	
	printf("\n-----------------------------------GRAND TOTAL------------------------------------\n");
	
	printf("Grand Total: %d", Grand_Total);

}
