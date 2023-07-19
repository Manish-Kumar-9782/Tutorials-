#include<stdio.h>
#include<string.h>


/*
	file write, file mode 
	
	"w" -> to write a file, it will create a new file if not found.
		-> it will truncate all data from file if exist.

	"a" -> to write a file, it will create a new file if not found.
		-> it will start to write after the existing data, if exist.
*/

int main() {

	FILE* file = NULL;
	char str[100] = { '\0' };

	errno_t err = fopen_s(&file, "testfile.txt", "w");

	if (!err) {
		printf("Write Something to file: ");

		gets_s(str, sizeof(str));

		fputs(str, file);

		fclose(file);
	}
	else {
		perror("fopen failed: ");
	}

	return 0;
}