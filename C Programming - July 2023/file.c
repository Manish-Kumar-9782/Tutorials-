#include<stdio.h>

void main(){
	
	int eof = 0;
	char ch = '\0';
	
	char fileData[50] = {'\0'};
	
	int i=0;
	
	FILE *file = fopen("test.txt", "r");
	
	for(i=0; i<50; i++){
		fscanf(file, "%c", &ch);
		printf("%c",ch);
	}
	
}
