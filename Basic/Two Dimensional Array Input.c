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

void getData(char[][20], int[], float[], char[][4], int );

void main() {
	
	// now we will make four array to store these kind of information.
	// names (array of string), ages (array of integers), 
	// heights (array of floats), bloodGroups (array of string.)
	
	// names as 2-D array to stores multiple names
	char names[5][20] = {'\0'};
	
	// ages array to store mutliple integers values.
	int ages[5] = {0};
	
	// height an array to store the float type values.
	float heights[5] = {0.0};
	
	// bloodGropu 2-d array to store the blood group information as string.
	char bloodGroups[5][4] ={'\0'};
	
	// Now we will make an formatted output to show our data.
	getData(names, ages,heights,bloodGroups,5);
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
 		printf("%8s %-10s %-15d %-15f %-15s\n"," " , names[i], ages[i],heights[i],bloodGroups[i]);
	 }
	 printf("--------------------------------------------------------------------\n\n");
}

void getData(char names[][20], 
				int ages[], 
				float heights[], 
				char bloodGroups[][4], 
				int n){
	
	int i=0;
	
	for(i=0; i<n; i++){
		printf("-------------------------------------------------------\n");
		
		printf("Enter Student Name: ");
		gets(names[i]);
		
		printf("Enter Student BloodGroup: ");
		gets(bloodGroups[i]);
		
		printf("Enter Student Age: ");
		scanf("%d", &ages[i]);
		
		printf("Enter Student Height: ");
		scanf("%f", &heights[i]);
		scanf("%c");
	}					
}


