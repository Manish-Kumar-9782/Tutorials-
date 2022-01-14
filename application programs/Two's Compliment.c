// Program: To find the two's compliment of the binary number.

/*Algorithm steps:

	1. Start 
	2. Read a binary number string a[]
	3. Calculated the length of string str (len)
	4. Initialize the looping counter k=0
	5. Repeat steps 6-8 while a[k] != '\0'
	6. if a[k] !=0 AND a[k] = 1 got step 7 else step 8
	7. Display error "Incorrect binary number format" and terminate the program.
	8. k = k+1;
	9. Initialize the looping counter i=len-1
	10. Repeat step 11 while a[i] != '1'.
	11. i = i-1
	12. initialize the looping counter j= i-1
	13. Repeat step 14-17 while j>= 0
	14. if a[j] = 1 goto step 15 else got step 16
	15. a[j] ='0'
	16. a[j] = '1'
	17. j= j-1
	18. Display a[] as the two's compliment
	19. Stop. */
	

#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(){
	
	char a[16];
	int i, j, k, len;
	
	// first we will clear the screen by using the clrscr();
	
//	clrscr();
	
	printf("Enter a binary number: ");
	gets(a); // gets() is a function to get a string we can do this thing by using the scanf function also.
	
	// Now we will compute the length of the string.
	len = strlen(a);  // strlen is the function to compute the length of the string.
	
	// Now we will start a loop which will go through the each element of the string.
	
	for (k=0; a[k] != '\0'; k++){
		// this loop will run until we dont find out a null character in the string.
		
		// now we will check the correct format of the binary number
		
		if (a[k] != '0' && a[k] !='1'){
			printf("Error: Incorrect binary number format...");
			getch(); // wait for keyboard hit.
		//	exit(0); // exiting from the program with exit code 0;
		}
	}
	
		for(i=len-1; a[i]!='1'; i--)
			;
		
		for(j=i-1; j>=0; j--){
			
			if(a[j]=='1')
				a[j]='0';
			else
				a[j]='1';
		}
		
		printf("\n2's Compliment = %s ", a);
		//getch();
		
	
}	
