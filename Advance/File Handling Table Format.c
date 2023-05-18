#include<stdio.h>

/*
	In this section we will read data from books.csv file and display it into 
	the table format.
*/

// a function declaration to display the separator
void printSep(char,int);

void main(){
	
	// Title,Subject,Page,Chapters,Author,Publisher,Price
//	char title[30] = {'\0'};
//	char subject[30] = {'\0'};
//	char page[30] = {'\0'};
//	char chapters[30] = {'\0'};
//	char author[30] = {'\0'};
//	char publisher[30] = {'\0'};
//	char price[30] = {'\0'};
//	char String[300] = {'\0'};
	char bookData[7][30] = {'\0'};
	char ch ='\0';
	// now reading the heading of the table.
	FILE *file = fopen("books.csv","r");
	
//	fscanf(file,"%s",String);
	int i = 0, j=0,k=0; 
	
	for(i=0; i<300; i++){
		
		fscanf(file,"%c",&ch);
//		printf("%c",ch);
		
		if(ch != '\n'){
			if(ch != ','){
				bookData[j][k] = ch;
				k++;
			}else{
				j++; // it will moniter the record columns
				k=0; // it will moniter the each char index in each column.
			}
		}
		else{
			// break the loop at the end of the current line
			break;
		}
	}
	
	for(i=0; i<7; i++){
		printf("%s,", bookData[i]);
	}
//	 closing the file.
	fclose(file);
}

void printSep(char ch, int count){
	int i=0;
	for(i=0;i<count; i++){
		printf("%c",ch);
	}
	printf("\n");
}
