#include "RecordReader.h"

RecordReader::RecordReader()
{
	
}

RecordReader::RecordReader(string str1,string str2,int s)
{
	this->BookIsbn=str1;
	this->ReaderName=str2;
	this->state=s; 
}
