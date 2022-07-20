// C program to print *
// in place of characters
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(void){
	
	// overflow and underflow
	char ch=' ';
	printf("Enter something: ");
	scanf("[^\n]%c ", &ch);
	
	
	while (ch != '\r' || ch != '\n'){
		scanf("[^\n]%c ", &ch);
		printf("%c", ch);
		
		if (ch == '\r'){
			break;
		}
	} 	
	
	
}
