#include "CSV.h"
#include<string.h>

CSVReader::CSVReader() {
	this->fileName = "";
	this->delimiter = ',';
	this->eof = false;
}

CSVReader::CSVReader(string filename, char delimiter) {
	this->setFileName(filename);
	this->delimiter = delimiter;
	this->eof = false;
	this->lineNumber = 0;
}

void CSVReader::setFileName(string filename) {
	this->fileName = filename;
	this->fileStream.open(fileName, ios::in);
}

void CSVReader::closeReader() {
	this->fileStream.close();
}

bool CSVReader::is_eof() {
	return this->eof;
}

vector<string> CSVReader::getNextRow() {
	string row = "";

	if (this->fileStream.is_open()) {
		getline(this->fileStream, row);
		this->lineNumber++;
		this->eof = this->fileStream.eof();
		return this->_str_split_(row);
	}
	else {
		cout << "File is not opened.."<<endl;
		
	}

}


vector<string> CSVReader::_str_split_(string str, char delimiter) {

	string value="";
	vector<string> vc;

	// Now reading the each single character from the given str.
	// using for range loop

	for (char ch : str) {

		if (ch == ',') {
			vc.push_back(value); // adding value to array.
			value = ""; // reseting the value
		}
		else {
			value += ch;
		}
	}

	vc.push_back(value); // adding last value;

	return vc;
	
}

// ================================================ //

CSVWriter::CSVWriter(string file, ios::openmode mode){
	this->fileName = file;
	this->filemode = mode;
	this->delimiter = ',';
}

vector<string> CSVWriter::_split(string row, const char* delimiter) {
	string value = "";
	vector<string> vc;

	char *str = (char*)row.c_str();


	char* next_str;

	char* token =strtok_s(str, delimiter, &next_str);

	while (token != nullptr) {
		value = token;
		vc.push_back(value);
	}

	return vc;
}

string CSVWriter::_join(vector<string> vc, char delimiter) {
		
	string value = "";

	for (int i = 0; i < vc.size(); i++) {
		
		if (i < vc.size() - 1) {
			value += vc[i] + delimiter;
		}
		else {
			value += vc[i];
		}
	}
	return value;
}

void CSVWriter::_write_row(string row) {

	// first check that our file is open or not
	if (!fileStream.is_open()) {
		this->fileStream.open(this->fileName, this->filemode);
		
		if (this->fileStream.fail()) {
			cout << "unable to open file" << endl;
			this->fileStream.clear();
		}
	}

	if (row.rfind("\n") != -1) {
		this->fileStream << row;
	}
	else {
		this->fileStream << row << "\n";
	}
}

void CSVWriter::writeRow(string row){
	this->_write_row(row);
}

void CSVWriter::writeRow(vector<string> vc) {
	this->_write_row(this->_join(vc));
}

void CSVWriter::closeWriter() {
	if (this->fileStream.is_open())
		this->fileStream.close();
}