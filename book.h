#ifndef _BOOK_H
#define _BOOK_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Book
{
	public:
		int id;
		string isbn;
		string name;
		string author;
		string publishe;
		string publisheddate;
		string price;
		int pages;
		string description;
		int like;
		int state;
};

#endif
