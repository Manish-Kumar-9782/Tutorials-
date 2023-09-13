#include<iostream>
#include<string>
#include<iomanip>
#include "CSV.h"
#include "Book.h"

using namespace std;

namespace record {
	vector<string> header;
	vector<Book> bookDatabase;
}

bool isFileExist(string file);

void readData(string filename);


int main() {

	vector<string> header = { "id","title","subject","pages","chapters","author","price" };
	vector<string> shortHeader = { "title","pages","price" };

	string file_name = "Book.csv";
	readData(file_name);

	cout << "===============================================" << endl;
	for (string str : record::header) {
		cout << setw(10) << str;
	}
	cout << "\n===============================================" << endl;
	for (Book bk : record::bookDatabase)
		bk.display(10);


	cout << endl;

	bool ifFile = isFileExist(file_name);

	CSVWriter* writer = nullptr;

	if (ifFile) {
		  writer = new CSVWriter(file_name, ios::app);
	}
	else {
		writer = new CSVWriter(file_name, ios::out);
		writer->writeRow(shortHeader);
	}

	

	char ch = ' ';

	while (ch != 'n') {

		Book bk = Book::createShortBook(); // creating a book;
		cin.ignore();

		writer->writeRow(bk.getValues2());
		cout << "Do you want to add another book: (y/n): ";
		cin >> ch;
		cin.ignore();
	}



	cout << endl;
	//bk.display();

	writer->closeWriter();
	return 0;
}

bool isFileExist(string file_name) {

	ifstream file(file_name);

	if (!file) {
		return false;
	}
	return true;
}

void readData(string filename) {

	bool isFile = isFileExist(filename);

	if (isFile) {
		CSVReader reader(filename);
		record::header = reader.getNextRow();  // header

		for (int i = 0; i < 4; i++) {
			vector<string> data = reader.getNextRow();
			Book bk = Book::createShortBook(data);
			record::bookDatabase.push_back(bk);
		}
	}
	else {
		cerr << "Unable to open file" << endl;
		perror("Error: ");
	}
}