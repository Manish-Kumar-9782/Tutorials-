#include<stdio.h>

void use_gets();
void use_getch();

void main(){
	
//	char Name[10] = {'m','a','n','i','s','h','\0'};
//	char Name2[10] = "Manish";
//	
//	int i=0;
//	for(i=0; i<10; i++){
//		printf("%c", Name[i]);
//	}
//	
//	printf("%s", Name);
//	printf("%s\n", Name2);
//	
//	gets(Name2);
//	
//	printf("\n%s", Name2);

//	use_gets();
	use_getch();

}

void use_gets(){
	
//	first we will make a char array

	char Name[10] = {'\0'};  // '\0' null-character define end of string point/position.
	
//	gets(Name);
//	scanf("%s", &Name);
	
	printf("Name: %s", Name);
	
	
}


void use_getch(){
	
	char ch;
	
	ch = getch();
	
	printf("Entered char: %c", ch);
	
	
}





