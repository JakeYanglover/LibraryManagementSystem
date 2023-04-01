#ifndef _RR_H
#define _RR_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class RecordReader
{
	public:
		RecordReader();
		RecordReader(string str1,string str2,int s);
		string BookIsbn;
		string ReaderName;
		int state; 
};
#endif
