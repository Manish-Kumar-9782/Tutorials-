#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;


class CSVReader {

private:
	vector<string> header;
	string fileName;
	char delimiter;
	int lineNumber;
	fstream fileStream;
	bool eof; // end of the file 
	// function to get the header 
	void _setHeader_();

	// a function to get and convert the row string into a list.
	vector<string> _str_split_(string, char = ',');

public:
	// a default constructor
	CSVReader();
	// parameterized constructor
	CSVReader(string filename, char delimiter=',');

	void setFileName(string filename);

	vector<string> getNextRow();

	void closeReader();

	bool is_eof();
};

class CSVWriter {

	vector<string> header;
	string fileName;
	ios_base::openmode filemode;
	char delimiter;
	int lineNum;
	fstream fileStream;

	// a function to split the string by given delimiter
	vector<string> _split(string, const char* = ",");

	// a function to join the array or vector by using the delimiter
	string _join(vector<string>, char = ',');

	// a abstract function to write the row using fileStream.
	void _write_row(string);

	// a function to set the filemode.
	void _set_filemode(bool =false);

public:
	CSVWriter(string, ios::openmode);

	void writeRow(string);
	void writeRow(vector<string>);
	void closeWriter();
};