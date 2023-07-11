#include<stdio.h>

/*
	structure is a data structure which allow us to create new user defined data type in which
	we can store multiple values with multiple data type.

	struct <user-data-type>{
	
		// declaration of multiple identifiers with defined data type.
	};

	Note: always create a structure outside of the any function.
*/

// enumerated data type
enum BloodGroup {A_POSITIVE=101, A_NEGATIVE, B_POSITIVE, B_NEGATIVE, AB_POSITIVE, AB_NEGATIVE, O_POSITIVE, O_NEGATIVE};

struct Person {
	char name[30];
	int age;
	float height;
	enum BloodGroup bloodGroup;
};

void showPerson(struct Person);

const char* get_bloodGroup(enum BloodGroup);

void main(){

	// Now we need to create a new Person type variable.
	struct Person pr1 = { "Karan", 21, 5.6, AB_POSITIVE };

	showPerson(pr1);

}

void showPerson(struct Person pr) {
	printf("Name: %s\n", pr.name);
	printf("Age: %d\n", pr.age);
	printf("Height: %f\n", pr.height);
	printf("BloodGroup: %s\n", get_bloodGroup(pr.bloodGroup));
}

const char* get_bloodGroup(enum BloodGroup bg) {
		
	switch (bg)
	{
	case A_POSITIVE: return "A+";
	case A_NEGATIVE: return "A-";
	case B_POSITIVE:return "B+";
	case B_NEGATIVE:return "B-";
	case AB_POSITIVE:return "AB+";
	case AB_NEGATIVE:return "AB-";
	case O_POSITIVE:return "O+";
	case O_NEGATIVE:return "O-";
	default: return "";
	}
}