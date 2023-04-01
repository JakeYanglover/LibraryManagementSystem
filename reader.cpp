#include "reader.h"

extern vector<reader> VR;
extern vector<Book> VB;
extern vector<RecordReader> VRR; 


reader::reader(string s,char* c,int n)
{
	this->m_id=s;
	strcpy(this->m_code,c);	
	this->lick=n;
}

reader::reader()
{
	
}

void reader::modifyCode()
{
	char x;
	do
	{
		system("cls");
		cout<<"是否修改密码（Y/N）"<<endl; 
		cin>>x;
	} 
	while(x!='y'&&x!='Y'&&x!='N'&&x!='n');
	
	if(x=='n'||x=='N')
	{
		return;
	}
	
	VR.clear();
	reader RX;
	ifstream ifs;
	ifs.open(READER,ios::in);
	while(ifs>>RX.m_id&&ifs>>RX.m_code&&ifs>>RX.lick)
	{
		VR.push_back(RX);
	}
	ifs.close();
	
	cout<<"请输入修改的密码：";
	char ch[20];
	int i=0; char c; 
    while(1)
	{
        c=getch(); 
        if(c=='\r')
            break;
        ch[i++]=c;
        putchar(c);
	}
	ch[i]='\0';
	
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++)
	{
		if(it->m_id==this->m_id)
		{
			strcpy(it->m_code,ch);
		}
	}
	//将vector存入 
	ofstream ofs;
	ofs.open(READER,ios::out|ios::trunc);
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<" "<<it->lick<<endl;
	}
	ofs.close();
	cout<<"\n\n密码修改成功！";
	getch();
	
	
}

void reader::searchBook()
{
	findBook();
}

void reader::borrowBook()
{
	system("cls");
	cout<<"请输入您要借阅书籍的ISBN或书籍名：";
	string str;cin>>str;
	
	ifstream ifs;
	ifs.open(BOOK,ios::in);
	VB.clear();
	Book B;
	while(!ifs.eof())
	{
		ifs>>B.id;
		ifs>>B.pages;
		ifs>>B.price;
		ifs>>B.state;
		ifs>>B.like;
		ifs.get();
		getline(ifs,B.isbn,'\t');
		getline(ifs,B.name,'\t');
		getline(ifs,B.author,'\t');
		getline(ifs,B.publishe,'\t');
		getline(ifs,B.publisheddate,'\t');
		getline(ifs,B.description);
		VB.push_back(B);
	}
	ifs.close();
	
	
	int x=0;
	vector<Book>::iterator its=VB.begin();
	for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++)
	{
		if(it->isbn==str||it->name==str)
		{
			cout<<"\n查找结果如下：\n";
			cout<<"书名："<<it->name
				<<"\n作者："<<it->author
				<<"\nISBN："<<it->isbn
				<<"\n价格："<<it->price
				<<"\n页数："<<it->pages 
				<<"\n出版社："<<it->publishe
				<<"\n出版日期："<<it->publisheddate
				<<"\n简介："<<it->description
				<<"\n状态："<<(it->state==1?"已借出":"未借出")
				<<"\n\n";
				x=1;
				its=it;
				break;
		}
	}
	if(x==0)
	{
		cout<<"没有相关信息！";
		getch();
		return;
	}
	
	ifstream ifs2;
	ifs2.open(RERE,ios::in);
	VRR.clear();
	RecordReader RR;
	while(ifs2>>RR.BookIsbn&&ifs2>>RR.ReaderName&&ifs2>>RR.state)
	{
		VRR.push_back(RR);
	}
	ifs2.close();
	
	if(its->state==1)
	{
		cout<<"此书籍已经被借阅！";
		getch();
		return; 
	}
	
	else
	{
		cout<<"是否借阅此图书（Y/N）" ;
		char s;cin>>s;
		if(s=='y'||s=='Y')
		{
			its->state=1;
			its->like++;
			ofstream ofs;
			ofs.open(BOOK,ios::out|ios::trunc);
			for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++ )
			{
				ofs<<it->id<<" "<<it->pages<<" "<<it->price<<" "<<it->state<<" "<<it->like<<" "
			 	  <<it->isbn<<"\t"<<it->name<<"\t"<<it->author<<"\t"<<it->publishe<<"\t"
			 	  <<it->publisheddate<<"\t"<<it->description<<endl;
			}
			ofs.close();
			
			RecordReader RR2;
			RR2.BookIsbn=its->isbn;
			RR2.ReaderName=this->m_id;
			RR2.state=1;
			VRR.push_back(RR2);
			ofstream ofs2;
			ofs2.open(RERE,ios::out|ios::trunc);
			for(vector<RecordReader>::iterator it=VRR.begin();it!=VRR.end();it++ )
			{
				ofs2<<it->BookIsbn<<" "<<it->ReaderName<<" "<<it->state<<endl;	
			}
			ofs2.close();
			
			VR.clear();
			reader R;
			ifstream ifs3;
			ifs3.open(READER,ios::in);
			while(ifs3>>R.m_id&&ifs3>>R.m_code&&ifs3>>R.lick)
			{
				VR.push_back(R);
			}
			ifs3.close();
			
			for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++)
			{
				if(it->m_id==this->m_id)
				{
					it->lick++;
					break;
				}
			}
			ofstream ofs3;
			ofs3.open(READER,ios::out|ios::trunc);
			for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++ )
			{
				ofs3<<it->m_id<<" "<<it->m_code<<" "<<it->lick<<endl;
			}
			ofs3.close();
			 
			
			cout<<"\n借阅成功！";
			getch();
			return;
		}
		else return;
		
	}
	
}



void reader::backBook()
{
	system("cls");
	cout<<"请输入您要归还书籍的ISBN或书籍名：";
	string str;cin>>str;
	
	ifstream ifs;
	ifs.open(BOOK,ios::in);
	VB.clear();
	Book B;
	while(ifs>>B.id&&
		ifs>>B.pages&&
		ifs>>B.price&&
		ifs>>B.state&&
		ifs>>B.like&&
		ifs.get()&&
		getline(ifs,B.isbn,'\t')&&
		getline(ifs,B.name,'\t')&&
		getline(ifs,B.author,'\t')&&
		getline(ifs,B.publishe,'\t')&&
		getline(ifs,B.publisheddate,'\t')&&
		getline(ifs,B.description))
	{
		VB.push_back(B);
	}
	ifs.close();
	
	
	int x=0;
	vector<Book>::iterator its=VB.begin();
	for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++)
	{
		if(it->isbn==str||it->name==str)
		{
			cout<<"\n查找结果如下：\n";
			cout<<"书名："<<it->name
				<<"\n作者："<<it->author
				<<"\nISBN："<<it->isbn
				<<"\n价格："<<it->price
				<<"\n页数："<<it->pages 
				<<"\n出版社："<<it->publishe
				<<"\n出版日期："<<it->publisheddate
				<<"\n简介："<<it->description
				<<"\n状态："<<(it->state==1?"已借出":"未借出")
				<<"\n\n";
				x=1;
				its=it;
				break;
		}
	}
	if(x==0)
	{
		cout<<"没有相关信息！";
		getch();
		return;
	}
	
	ifstream ifs2;
	ifs2.open(RERE,ios::in);
	VRR.clear();
	RecordReader RR;
	while(ifs2>>RR.BookIsbn&&ifs2>>RR.ReaderName&&ifs2>>RR.state)
	{
		VRR.push_back(RR);
	}
	ifs2.close();
	
	int y=0;
	vector<RecordReader>::iterator rits=VRR.begin();
	for(vector<RecordReader>::iterator it=VRR.begin();it!=VRR.end();it++)
	{
		if(its->isbn==it->BookIsbn&&it->ReaderName==this->m_id&&it->state==1)
		{
			rits=it;
			y=1;
			break;
		}
	}
	
	if(y==0)
	{
		cout<<"此书未被您借阅！";
		getch();
		return;
	}
	
		cout<<"是否归还此图书（Y/N）" ;
		char s;cin>>s;
		if(s=='y'||s=='Y')
		{
			its->state=0;
			rits->state=0; 
			
			ofstream ofs;
			ofs.open(BOOK,ios::out|ios::trunc);
			for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++ )
			{
				ofs<<it->id<<" "<<it->pages<<" "<<it->price<<" "<<it->state<<" "<<it->like<<" "
			 	  <<it->isbn<<"\t"<<it->name<<"\t"<<it->author<<"\t"<<it->publishe<<"\t"
			 	  <<it->publisheddate<<"\t"<<it->description<<endl;
			}
			ofs.close();
			
			ofstream ofs2;
			ofs2.open(RERE,ios::out|ios::trunc);
			for(vector<RecordReader>::iterator it=VRR.begin();it!=VRR.end();it++ )
			{
				ofs2<<it->BookIsbn<<" "<<it->ReaderName<<" "<<it->state<<endl;	
			}
			ofs2.close();
			 
			
			cout<<"\n归还成功！";
			getch();
			return;
		}
	
		else return;
	
}

void reader::viewBook()
{
	
}

void reader::history()
{
	char s;
	do
	{
		system("cls");
		cout<<"（1）查看借阅记录\n（2）查看借阅中的图书\n（3）返回\n--------->";
		cin>>s;
	}
	while(s!='2'&&s!='1'&&s!='3');
	
	if(s=='1')
	{
		ifstream ifs;
		ifs.open(BOOK,ios::in);
		VB.clear();
		Book B;
		while(ifs>>B.id&&
			ifs>>B.pages&&
			ifs>>B.price&&
			ifs>>B.state&&
			ifs>>B.like&&
			ifs.get()&&
			getline(ifs,B.isbn,'\t')&&
			getline(ifs,B.name,'\t')&&
			getline(ifs,B.author,'\t')&&
			getline(ifs,B.publishe,'\t')&&
			getline(ifs,B.publisheddate,'\t')&&
			getline(ifs,B.description))
		{
			VB.push_back(B);
		}
		ifs.close();
		
		ifstream ifs2;
		ifs2.open(RERE,ios::in);
		VRR.clear();
		RecordReader RR;
		while(ifs2>>RR.BookIsbn&&ifs2>>RR.ReaderName&&ifs2>>RR.state)
		{
			VRR.push_back(RR);
		}
		ifs2.close();
		
		int x=1;
		for(vector<RecordReader>::iterator it=VRR.begin();it!=VRR.end();it++)
		{
			for(int i=0;i<VB.size();i++)
			{
				if(VB[i].isbn==it->BookIsbn&&it->ReaderName==this->m_id)
				{
					cout<<x<<"、" ;
					x++;
					cout<<"书名："<<VB[i].name
						<<"\n作者："<<VB[i].author
						<<"\nISBN："<<VB[i].isbn
						<<"\n价格："<<VB[i].price
						<<"\n页数："<<VB[i].pages 
						<<"\n出版社："<<VB[i].publishe
						<<"\n出版日期："<<VB[i].publisheddate
						<<"\n简介："<<VB[i].description
						<<"\n状态："<<(VB[i].state==1?"已借出":"未借出")
						<<"\n\n"; 
				}
			}
		}
		if(x==1)
		cout<<"无记录！";
		getch();
			
	}
	
	else if(s=='2')
	{
		ifstream ifs;
		ifs.open(BOOK,ios::in);
		VB.clear();
		Book B;
		while(ifs>>B.id&&
			ifs>>B.pages&&
			ifs>>B.price&&
			ifs>>B.state&&
			ifs>>B.like&&
			ifs.get()&&
			getline(ifs,B.isbn,'\t')&&
			getline(ifs,B.name,'\t')&&
			getline(ifs,B.author,'\t')&&
			getline(ifs,B.publishe,'\t')&&
			getline(ifs,B.publisheddate,'\t')&&
			getline(ifs,B.description))
		{
			VB.push_back(B);
		}
		ifs.close();
		
		ifstream ifs2;
		ifs2.open(RERE,ios::in);
		VRR.clear();
		RecordReader RR;
		while(ifs2>>RR.BookIsbn&&ifs2>>RR.ReaderName&&ifs2>>RR.state)
		{
			VRR.push_back(RR);
		}
		ifs2.close();
		
		int x=1;
		for(vector<RecordReader>::iterator it=VRR.begin();it!=VRR.end();it++)
		{
			for(int i=0;i<VB.size();i++)
			{
				if(VB[i].isbn==it->BookIsbn&&it->ReaderName==this->m_id&&it->state==1)
				{
					cout<<x<<"、" ;
					x++;
					cout<<"书名："<<VB[i].name
						<<"\n作者："<<VB[i].author
						<<"\nISBN："<<VB[i].isbn
						<<"\n价格："<<VB[i].price
						<<"\n页数："<<VB[i].pages 
						<<"\n出版社："<<VB[i].publishe
						<<"\n出版日期："<<VB[i].publisheddate
						<<"\n简介："<<VB[i].description
						<<"\n状态："<<(VB[i].state==1?"已借出":"未借出")
						<<"\n\n"; 
				}
			}
		}
		if(x==1)
		cout<<"无记录！";
		getch();
		
	}
	
	else return;			
}

void reader::BorrowAndBack()
{
	char s;
	do
	{
		system("cls");
		cout<<"（1）借书\n（2）还书\n（3）返回\n-------->";
		cin>>s;
	} 
	while(s!='1'&&s!='2'&&s!='3');
	if(s=='1')
	{
		this->borrowBook();
	}
	if(s=='2')
	{
		this->backBook();
	}
	else return;
}

 
void reader::Rmenue()
{
	system("cls");
	cout << "欢迎读者" << this->m_id << "登录！" << endl<<endl; 
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （1）搜索图书            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （2）借还图书            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （3）借阅记录            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （4）修改密码            |\n";
	cout << "\t\t|         				            |\n";
	cout << "\t\t|         （5）查看排行榜          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （6）返回上一级          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （Q）退出登录            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout <<endl<< "\t\t请选择您的操作： [ ]" << endl;
	gotoxy(34,20);
}	
 
void reader::rank()
{
	while(1)
	{
		char s;
		do
		{
			system("cls");
			cout<<"（1）热门书籍\n（2）最新出版\n（3）风云人物\n（4）返回\n----------->";
			cin>>s; 
		}
		while (s!='1'&&s!='2'&&s!='3'&&s!='4');
		if(s=='1')
		hotBook();
		else if(s=='2')
		newBook();
		else if(s=='3')
		hotReader();
		else return; 
	}
}
 
 



