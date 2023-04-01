#ifndef _ADMINISTRATOR_H
#define _ADMINISTRATOR_H
#include <iostream>
#include "reader.h"
#include "func.h"
#include "book.h"
using namespace std;
class admin
{
	public:
		admin();
		admin(string s,char* c);
		string m_id;
		char m_code[20];
		void resetReader();
		void checkReader();
		void addReader();
		void removeReader();
		void modifyReader();
		void addBook();
		void removeBook();
		void modifyBook();
		void checkBook();
		void Amenue();
		void modifyCode();
		void manageReader();
};
#endif
