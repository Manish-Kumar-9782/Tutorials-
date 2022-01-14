// in this section we will discuss about the array and their uses.

#include<stdio.h>
#include<time.h>

void print_line();
void main(){

	int i;
	char Names[5][15] = { 
							"Jakir Husain",
							"Manish Kumar",
							"Kunal sing",
							"Sager Soni",
							"Anil Kumar",
						};
	
	char standard[5][30] = {
							"12th",
							"Graduated in ME Engineer",
							"Graduated in ME Engineer",
							"Graduated in BA",
							"Graduated in polo deploma"
							};
	
	char Phone_number[5][11] = {
								"1234566978",
								"2563417896",
								"2541369987",
								"1233245896",
								"2589631475"
								};
								
								
	print_line();
	printf("Names \t\t Standard \t\t  Phone Number \n");
	print_line();
	
	for(i=0; i<5; i++)
		printf("%-15s %-26s %-11s \n", Names[i], standard[i], Phone_number[i]);
	
	print_line();
}

void print_line(){
		printf("______________________________________________________________\n");
}
