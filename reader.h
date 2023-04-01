#ifndef _READER_H
#define _READER_H
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <conio.h>
#include "func.h"
#include "globalFile.h"
#include "book.h" 
using namespace std;


class reader
{
	public:
		reader();
		reader(string s,char* c,int n);
		string m_id;
		char m_code[20];
		int lick;
		void modifyCode();
		void searchBook();
		void borrowBook();
		void backBook();
		void viewBook();
		void history();
		void Rmenue();
		void BorrowAndBack();
		void rank();
};

#endif
