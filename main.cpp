#include "administrator.h"
#include "book.h"
#include "globalFile.h"
#include "reader.h"
#include "func.h"
#include "conio.h"
#include "windows.h"
#include "RecordReader.h"
#include <vector>

vector<reader> VR;
vector<admin> VA;
vector<Book> VB; 
vector<RecordReader> VRR;
bool cmp3(reader r1,reader r2)
{
	return r1.lick>r2.lick;	
}

int main()
{
	char select;
	while(1)
	{	
	Menue();
	cin>>select;
	switch(select)
	{
		case '1':
			Rlogin();	
			break;
		case '2':
			Alogin();
			break;
		case '3':
			Vlogin();
			break;
		case '4':
			addUser();
			break;
		case 'Q':
		case 'q':
			exit(0); 
			break;
		default:
			cout<<endl<<"\t\t\t只能输入给定选项！按任意键继续";
			getch();
			break;
	}
	}
	
	
	return 0;	
} 
