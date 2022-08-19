#include<stdio.h>
#include<string.h>

void main(){

	char Students_Names[4][16] = {'\0'};
	int Students_age[4];
	char Students_graduations [4][5];
	
	char ch[16];
	int i=0;
	
	for(i=0; i<4; i++){
		
		printf("Enter Student %d Name: ",i);
		gets(Students_Names[i]);
		
		printf("Enter Student %d graduation: ", i);
		gets(Students_graduations[i]);
		
		printf("Enter Student %d age: ", i);
		scanf("%d", &Students_age[i]);
		gets(ch); // dummy string-stream flush array.
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
	}
	
	printf("\n\n");
	
	printf("%-16s %-5s %-10s", "Name","Age","Graduation");
	printf("\n-----------------------------------------\n");
	
	for(i=0; i<4; i++){
		printf("%-16s %-5d %-10s\n", Students_Names[i], Students_age[i], Students_graduations[i]);
	}
	

}

/*
Enter Student 0 Name: Manish
Enter Student 0 graduation: b.tech
Enter Student 0 age: 26
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

Enter Student 1 Name: Abhishek
Enter Student 1 graduation: bca
Enter Student 1 age: 18
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

Enter Student 2 Name: Sager
Enter Student 2 graduation: Ba
Enter Student 2 age: 26
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

Enter Student 3 Name: Rahul
Enter Student 3 graduation: b.sc
Enter Student 3 age: 21
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

*/

/*
	structure
	
	struct Student {
		
		char name[16] = {'\0'};
		int age = 0;
		char graduation[5] = {'\0'}; 
	};

	struct Student student;
*/


