#include<stdio.h>
//#include<string.h>

void Array_intro();
void Array();
void ConditionalArry_input();

void main(){
	
//	Array_intro();

//	Array();

	ConditionalArry_input();

}

void Array_intro(){
		// while declaration we need to specify the size array.
	char Names[5][6];
	
//	char Name1 = {'o', 'n', 'e','\0'}
//	char Name4 = {'1', '2','3','4','5','6','f','o','u','r','\0','\0'};
	
	char Names2[][6] = {"One", "Two", "Three","123456", "four", "five"}; 
	
	// [[6], [6], [6], [6], [6], [6]]
	
	int i=0;
	for(i=0; i<6; i++){
		printf("%s\n", Names2[i]);
	}

}

void Array(){
	
	char Names[][6] = {"One", "Two", "Three","12345", "four", "five"};
	
	// updating one.
	
	// if you input like Hello it will save as Hello\nTwo 
	
//	Names[0]  = "One";
	
	int i=0;
	for(i=0; i<6; i++){
		scanf("%c", &Names[0][i]);
	} 
	
	/*alternative*/
//	scanf("%s", &Names[0])
	
	for(i=0; i<6; i++){
		printf("%s\n", Names[i]);
	}
	
}


void ConditionalArry_input(){
	int sub_size = 10; 
	char Names[][10] = {"One", "Two", "Three","12345", "four", "five"};
	
	printf("Enter the 1st sub array value: ");
	
	int i=0;
	 // sub array size.
	int count = 0; // bound checking.
	char ch;  // to hold the scanned value.
	
	do{
		
		scanf("%c", &ch);
		
		if(ch != '\n'){
			
			Names[0][count] = ch;
		}
		else{
			Names[0][count]='\0';
		}
		
		
		count++;
		// bound checking
		if(count>=sub_size-1){
			Names[0][count]='\0';
			break;
		}
		
		
	}while(ch != '\n');
	
	
	for(i=0; i<6; i++){
		printf("%s\n", Names[i]);
	}
	
}	
