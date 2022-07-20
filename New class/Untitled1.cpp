#include <stdio.h>


int main(){
	
	char ch;
	int number;
	
	printf("Enter the name: ");
	
	scanf("%c", &ch);
	printf("%c ", ch);
	
	while(ch != '\n'){
		scanf("%c", &ch);
		printf("%c ", ch);
	}
	
	printf("\n\nEnter PhNumber: ");
	scanf("%d", &number);
	printf("Ph Number: %d", number);
}
