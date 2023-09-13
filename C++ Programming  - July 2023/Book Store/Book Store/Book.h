#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

using _num = unsigned int;

class Book {
	_num id;
	string title;
	string subject;
	_num pages;
	_num chapters;
	string author;
	double price;

	

public:

	Book(string title, int page, double price) {
		this->title = title;
		this->pages = page;
		this->price = price;
	}

	Book(string title, string subject,
		_num pages, _num chapters, string author,
		double price);

	Book(_num id, string title, string subject,
		_num pages, _num chapters, string author,
		double price);

	static Book createBook();
	static Book createShortBook();
	static Book createShortBook(vector<string>);

	void display();
	void display(int fw);

	int getId();
	void setId(int id);

	vector<string> getValues();
	vector<string> getValues2();

};