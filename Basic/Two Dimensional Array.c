#include<stdio.h>

/*
	In this section we will see two dimensional array.
	
	two dimensional array are nothing but the on or more than one array inside 
	another array of having same size/length.
	
	stntax:
	
	array[row][column]:
	
		row: it define the length of the each inner array.
		column: it define the number of array present in our main array.
		
	matrix 4 x 4:
	
	matrxi[4][4] = [
		[1,2,3,4],
		[5,6,7,8],
		[9,10,11,12],
		[13,14,15,16]
	]
*/	

void showTable(char[][20], int[], float[], char[][4], int );

void main() {
	
	// now we will make four array to store these kind of information.
	// names (array of string), ages (array of integers), 
	// heights (array of floats), bloodGroups (array of string.)
	
	// names as 2-D array to stores multiple names
	char names[5][20] ={
		"Manish", "Aasif", "Chandan","Manyank","Aasish"
	};
	
	// ages array to store mutliple integers values.
	int ages[5] = {27, 19, 20, 18, 18};
	
	// height an array to store the float type values.
	float heights[5] = {5.6, 5.5, 5.6, 5.7,5.8};
	
	// bloodGropu 2-d array to store the blood group information as string.
	char bloodGroups[5][4] = {"A+","B+","AB+","B-","O+"};
	
	// Now we will make an formatted output to show our data.
	
	showTable(names, ages,heights,bloodGroups,5);
	
	printf("\nEnter first student name: ");
	gets(names[0]);
	
//	printf("\n\n");
	showTable(names, ages,heights,bloodGroups,5);
}

void showTable(char names[][20], 
				int ages[], 
				float heights[], 
				char bloodGroups[][4], 
				int n){
	
	printf("%8s %-10s %-15s %-15s %-15s\n", " ","Name", "Age", "Height", "BloodGroup");
	printf("--------------------------------------------------------------------\n");
	
	int i = 0;
 	for(i=0; i<n; i++){
 		printf("%8s %-10s %-15d %0.1f-inch %-6s  %-15s\n"," " , names[i], ages[i],heights[i]," ",bloodGroups[i]);
	 }
	 printf("--------------------------------------------------------------------\n\n");
}


