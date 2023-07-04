#include<stdio.h>
#include<string.h>

/*
	struct name {
		// Here now we need to declare variable
		// we can declare multiple variable of multiple type.
		int a;
		char c;
		float f;
		// here variable a, b and c are called data members of structure
	}

	// Note we should create our structure out of the any function.

	// it is used to create user defined data types.

	enum variables => 

	enum {AB_POSITIVE, AB_NEGATIVE, A_POSITIVE, A_NEGATIVE, B_POSITIVE, B_NEGATIVE}
*/

// here we will also use enum type variable

enum bloodgroup { AB_POSITIVE, AB_NEGATIVE, A_POSITIVE, A_NEGATIVE, B_POSITIVE, B_NEGATIVE, O_POSITIVE, O_NEGATIVE };

struct Person {
	char name[30];
	int age;
	float height;
	char bloodgroup[5];
};

void displayPerson(struct Person);

void main() {

	// declaring and initializing Person
	struct Person person = {"Kush", 21, 5.6, "AB+"};
	// Note: here struct Person is a complete data type.

	struct Person person2;

	strcpy_s(person2.name,30, "Kuldeep");
	person2.age = 21;
	person2.height = 5.7;
	strcpy_s(person2.bloodgroup, 5, "A+");



	displayPerson(person);
	printf("\n");
	displayPerson(person2);
}



void displayPerson(struct Person person) {

	printf("Person<%s>{\n", person.name);
	printf("\t Name: %s\n", person.name);
	printf("\t Age: %d\n", person.age);
	printf("\t Height: %.1f\n", person.height);
	printf("\t BloodGroup: %s\n}", person.bloodgroup);

}