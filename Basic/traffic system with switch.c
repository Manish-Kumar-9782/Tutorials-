#include<stdio.h>

/* IN this we will make a traffic system by using the 
 switch statement. 
 	
 	color mapping:
 	
 	r -> red;
 	o -> orange;
 	g -> green color
 	
 	we will use this mapped color as our constant color.
 
 */
 
 void main(){
 	
 	// since we are using the color as single character so we need to
 	// make a char type variable.
 	
 	char color;
 	
 	// Now in this case we will ask the user to put the color.
 	// to take some input from the user we use scanf function.
 	// but before that we will the user what to input.
 	printf("\ncolor codes: r -> red \t g-> green \t o -> orange");
 	printf("\nEnter the traffic Signle color code: ");
 	scanf("%c", &color);
 	printf("\n================================\n");
 	// to take the input first we need to specify the format specifier
 	// inside the string, and then we need to use the variable in which
 	// we want to store the value with prefixed & (ampersand)
 	
 	switch(color){
 		
		case 'r':
 			printf("\nSignal is red please stop!!!");
 			break;
 		
 		case 'g':
 			printf("\nSignal is green you can go!!!");
 			break;
 			
 		case 'o':
 			printf("\nSignal is orange please be carefull!!");
 			break;
 			
 		default:
 			printf("\nTraffic system is failed, call traffic police..");
 			break;
	 }
 }
