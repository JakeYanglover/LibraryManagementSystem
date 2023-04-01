#ifndef _FUNC_H
#define _FUNC_H
#include <iostream>
#include <string>
#include "windows.h"
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include "reader.h"
#include "book.h"
#include "administrator.h"
#include "RecordReader.h"
#include <algorithm>

using namespace std;

bool cmp1(Book b1,Book b2);
bool cmp2(Book b1,Book b2);
void gotoxy(int x, int y);
void Rlogin();
void Alogin();
void Vlogin();
void freashReader();
void addUser();
void Menue();
void findBook();
void showBook();
void searchByAuthor();
void searchByname();
void searchByPublisher();
void searchByIsbn(); 
void hotBook();
void hotReader();
void newBook(); 



#endif
