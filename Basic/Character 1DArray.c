#include<stdio.h>

void main(){
	
	char Name[10] = {'m','a','n','i','s','h','\0'};
	char Name2[10] = "Manish";
	
	int i=0;
	for(i=0; i<10; i++){
		printf("%c", Name[i]);
	}
	
	printf("%s", Name);
	printf("%s\n", Name2);
	
	gets(Name2);
	
	printf("\n%s", Name2);
}
