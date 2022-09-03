#include<stdio.h>
#include<string.h>

typedef struct Book{
	//Book -- book(title,subject,page,chapters,author,publisher,price)
	char title[30];
	char subject[20];
	char author[20];
	char publisher[20];
	int page;
	int chapters;
	float price;
}book;

void print_book(book);
void readline(FILE *file, char line[]);

void main(){
	
	FILE *file = NULL;
	file = fopen("books.csv", "r");
	char line[200] = {'\0'};
	
//	Title,Subject,Page,Chapters,Author,Publisher,Price
	
//	char header[][12] = {"Title", "Subject","Page","Chapters","Author","Publisher","Price"}
	
	book *bk = (book*)malloc(sizeof(book)); // dynamic memory allocation.
	
//	strcpy(bk->title, "Hello");
//	printf("%s", bk->title);
	
	if(file == NULL){
		printf("\nFile is not found\n");
	}
	else{
		printf("\nfile found\n");
		
		readline(file, line);
//		printf("%s", line);
		split_line(line);
		printf("\n-------------------------------------------------------------------------\n");
		readline(file, line);	
		split_line(line);
		
		readline(file, line);	
		split_line(line);
		
		readline(file, line);	
		split_line(line);
		
		readline(file, line);	
		split_line(line);
		
		fclose(file);
		printf("\nfile reading completed");
	}
}



//================================================================//
void print_book(book bk){
	// Book -- book(title,subject,page,chapters,author,publisher,price)
	printf("Title:\t%s\n", bk.title);
	printf("Subject:\t%s\n", bk.subject);
	printf("Page:\t%d\n", bk.page);
	printf("Price:\t%f\n",bk.price);
	printf("Chapters:\t%d\n", bk.chapters);
	printf("Author:\t%s\n", bk.author);
	printf("Publisher:\t%s\n", bk.publisher);
}

void readline(FILE *file, char line[]){
	char ch;
	int eof;
	int i = 0;
	do{
		eof = fscanf(file,"%c", &ch);
//		get the character from strem buffer
//		printf("%c",ch);
		line[i] = ch;
		i++;
//		print the ch on the screen.
	}
	while(ch != '\n');
//	here EOF is used for end of file.
	
}

void split_line(char line[]){
//	line: array in which our whole line stored.
//	split_no: 
	char ch;
	int i =0;
	char result[7][20]={'\0'};
//	char str[20] = {'\0'};
	int j,k =0;
	do{
			
		ch = line[i];
		
		if(ch != ','){
			
			result[j][k] = ch;
//			j : to show the position of the outer array
//			k : to show the position of the inner array.
			k++;
		}
		else{
			j++;
			k = 0;
		}
		i++;
		
	}while(ch!='\0');
	
	printf("\n");
	for(i=0; i<=j; i++){
		printf("%-15s", result[i]);
	}
	
}
