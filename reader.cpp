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
		cout<<"�Ƿ��޸����루Y/N��"<<endl; 
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
	
	cout<<"�������޸ĵ����룺";
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
	//��vector���� 
	ofstream ofs;
	ofs.open(READER,ios::out|ios::trunc);
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<" "<<it->lick<<endl;
	}
	ofs.close();
	cout<<"\n\n�����޸ĳɹ���";
	getch();
	
	
}

void reader::searchBook()
{
	findBook();
}

void reader::borrowBook()
{
	system("cls");
	cout<<"��������Ҫ�����鼮��ISBN���鼮����";
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
			cout<<"\n���ҽ�����£�\n";
			cout<<"������"<<it->name
				<<"\n���ߣ�"<<it->author
				<<"\nISBN��"<<it->isbn
				<<"\n�۸�"<<it->price
				<<"\nҳ����"<<it->pages 
				<<"\n�����磺"<<it->publishe
				<<"\n�������ڣ�"<<it->publisheddate
				<<"\n��飺"<<it->description
				<<"\n״̬��"<<(it->state==1?"�ѽ��":"δ���")
				<<"\n\n";
				x=1;
				its=it;
				break;
		}
	}
	if(x==0)
	{
		cout<<"û�������Ϣ��";
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
		cout<<"���鼮�Ѿ������ģ�";
		getch();
		return; 
	}
	
	else
	{
		cout<<"�Ƿ���Ĵ�ͼ�飨Y/N��" ;
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
			 
			
			cout<<"\n���ĳɹ���";
			getch();
			return;
		}
		else return;
		
	}
	
}



void reader::backBook()
{
	system("cls");
	cout<<"��������Ҫ�黹�鼮��ISBN���鼮����";
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
			cout<<"\n���ҽ�����£�\n";
			cout<<"������"<<it->name
				<<"\n���ߣ�"<<it->author
				<<"\nISBN��"<<it->isbn
				<<"\n�۸�"<<it->price
				<<"\nҳ����"<<it->pages 
				<<"\n�����磺"<<it->publishe
				<<"\n�������ڣ�"<<it->publisheddate
				<<"\n��飺"<<it->description
				<<"\n״̬��"<<(it->state==1?"�ѽ��":"δ���")
				<<"\n\n";
				x=1;
				its=it;
				break;
		}
	}
	if(x==0)
	{
		cout<<"û�������Ϣ��";
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
		cout<<"����δ�������ģ�";
		getch();
		return;
	}
	
		cout<<"�Ƿ�黹��ͼ�飨Y/N��" ;
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
			 
			
			cout<<"\n�黹�ɹ���";
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
		cout<<"��1���鿴���ļ�¼\n��2���鿴�����е�ͼ��\n��3������\n--------->";
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
					cout<<x<<"��" ;
					x++;
					cout<<"������"<<VB[i].name
						<<"\n���ߣ�"<<VB[i].author
						<<"\nISBN��"<<VB[i].isbn
						<<"\n�۸�"<<VB[i].price
						<<"\nҳ����"<<VB[i].pages 
						<<"\n�����磺"<<VB[i].publishe
						<<"\n�������ڣ�"<<VB[i].publisheddate
						<<"\n��飺"<<VB[i].description
						<<"\n״̬��"<<(VB[i].state==1?"�ѽ��":"δ���")
						<<"\n\n"; 
				}
			}
		}
		if(x==1)
		cout<<"�޼�¼��";
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
					cout<<x<<"��" ;
					x++;
					cout<<"������"<<VB[i].name
						<<"\n���ߣ�"<<VB[i].author
						<<"\nISBN��"<<VB[i].isbn
						<<"\n�۸�"<<VB[i].price
						<<"\nҳ����"<<VB[i].pages 
						<<"\n�����磺"<<VB[i].publishe
						<<"\n�������ڣ�"<<VB[i].publisheddate
						<<"\n��飺"<<VB[i].description
						<<"\n״̬��"<<(VB[i].state==1?"�ѽ��":"δ���")
						<<"\n\n"; 
				}
			}
		}
		if(x==1)
		cout<<"�޼�¼��";
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
		cout<<"��1������\n��2������\n��3������\n-------->";
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
	cout << "��ӭ����" << this->m_id << "��¼��" << endl<<endl; 
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��1������ͼ��            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��2���軹ͼ��            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��3�����ļ�¼            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��4���޸�����            |\n";
	cout << "\t\t|         				            |\n";
	cout << "\t\t|         ��5���鿴���а�          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��6��������һ��          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��Q���˳���¼            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout <<endl<< "\t\t��ѡ�����Ĳ����� [ ]" << endl;
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
			cout<<"��1�������鼮\n��2�����³���\n��3����������\n��4������\n----------->";
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
 
 



