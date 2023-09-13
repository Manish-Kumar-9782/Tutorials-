#include "Book.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// ======================================================================================//
// constructor
Book::Book(string title, string subject,
	_num pages, _num chapters, string author,
	double price) {
	this->id = NULL;
	this->title = title;
	this->subject = subject;
	this->pages = pages;
	this->chapters = chapters;
	this->author = author;
	this->price = price;
}


Book::Book(_num id, string title, string subject,
	_num pages, _num chapters, string author,
	double price) {
	this->id = id;
	this->title = title;
	this->subject = subject;
	this->pages = pages;
	this->chapters = chapters;
	this->author = author;
	this->price = price;
}

// ======================================================================================//
// display method to show the data
void Book::display() {
	cout << "Book:{" << id << ","
		<< title << ","
		<< subject << ","
		<< pages << ","
		<< chapters << ","
		<< author << ","
		<< price << "}" << endl;
}

void Book::display(int fw) {
	cout << setw(fw) << title
		<< setw(fw) << pages
		<< setw(fw) << price << endl;

}

// ======================================================================================//
vector<string> Book::getValues() {
	vector<string> vc;

	vc.push_back(to_string(id)); // id
	vc.push_back(title); // title
	vc.push_back(subject); // subject
	vc.push_back(to_string(pages)); // pages
	vc.push_back(to_string(chapters)); // chapters
	vc.push_back(author); // author
	vc.push_back(to_string(price)); // price

	return vc;
}


vector<string> Book::getValues2() {
	vector<string> vc;

	//vc.push_back(to_string(id)); // id
	vc.push_back(title); // title
	//vc.push_back(subject); // subject
	vc.push_back(to_string(pages)); // pages
	//vc.push_back(to_string(chapters)); // chapters
	//vc.push_back(author); // author
	vc.push_back(to_string(price)); // price

	return vc;
}

// ======================================================================================//
int Book::getId() {
	return id;
}

void Book::setId(int id) {
	this->id = id;
}

// ======================================================================================//
// creat book
Book Book::createBook() {

	_num id = 0;
	string title = "";
	string subject = "";
	_num pages = 0;
	_num chapters = 0;
	string author = "";
	double price = 0;

	cout << "Book Title: ";
	getline(cin, title);
	cin.ignore();

	cout << "Book Subject: ";
	getline(cin, subject);
	cin.ignore();

	cout << "Book Author: ";
	getline(cin, author);
	cin.ignore();

	cout << "Book Pages: ";
	cin >> pages;

	cout << "Book chapters: ";
	cin >> chapters;

	cout << "Book Price: ";
	cin >> price;

	Book bk(1, title,subject,pages, chapters, author, price);

	return bk;
}


Book Book::createShortBook() {

	
	string title = "";
	_num pages = 0;
	double price = 0;

	cout << "Book Title: ";
	getline(cin, title);
	cin.ignore();

	cout << "Book Pages: ";
	cin >> pages;

	cout << "Book Price: ";
	cin >> price;

	Book bk(title, pages, price);

	return bk;
}

Book Book::createShortBook(vector<string> data) {


	string title = data[0];  // title
	_num pages = atoi(data[1].c_str()); // pages
	double price = atof(data[2].c_str());  // price

	Book bk(title, pages, price);

	return bk;
}