#include "func.h"
#include "reader.h"
#include "administrator.h"
#include "globalFile.h"
#include "RecordReader.h"

extern vector<reader> VR;
extern vector<admin> VA;
extern vector<Book> VB; 
extern vector<RecordReader> VRR; 
extern bool cmp3(reader r1,reader r2); 

void gotoxy(int x, int y)
{
    int xx=0x0b;
    HANDLE hOutput;
    COORD loc;
    loc.X = x;
    loc.Y=y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, loc);
    return;
}

bool cmp1(Book b1,Book b2)
{
	return b1.like>b2.like;
}

bool cmp2(Book b1,Book b2)
{
	return b1.publisheddate>b2.publisheddate;
}


void showBook()
{
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
	
	system("cls");
	for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++)
	{
		
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
	}
	getch();
	
}

void freshReader()
{
	VR.clear();
	reader R;
	ifstream ifs;
	ifs.open(READER,ios::in);
	while(ifs>>R.m_id&&ifs>>R.m_code&&ifs>>R.lick)
	{
		VR.push_back(R);
	}
	ifs.close();
	ofstream ofs;
	ofs.open(READER,ios::out|ios::trunc);
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<" "<<it->lick<<endl;
	}
	ofs.close();
		
}

void hotBook()
{
	system("cls");
	cout<<"�����鼮���ư�\n" ;
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
	
	sort(VB.begin(),VB.end(),cmp1);
	for(int i=0,j=1;i<10;i++,j++)
	{
		cout<<"��"<<j<<"��"<<endl; 
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
	getch();
}

void hotReader()
{
	system("cls");
	cout<<"����TOP10��\n" ;
	VR.clear();
	reader R;
	ifstream ifs;
	ifs.open(READER,ios::in);
	while(ifs>>R.m_id&&ifs>>R.m_code&&ifs>>R.lick)
	{
		VR.push_back(R);
	}
	ifs.close();
	
	sort(VR.begin(),VR.end(),cmp3);
	for(int i=0,j=1;i<10;i++,j++)
	{
		cout<<"��"<<j<<"��"<<VR[i].m_id<<endl;
	}
	getch();	
}

void newBook()
{
	system("cls");
	cout<<"���³����鼮TOP10��\n" ;
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
	
	sort(VB.begin(),VB.end(),cmp2);
	for(int i=0,j=1;i<10;i++,j++)
	{
		cout<<"��"<<j<<"��"<<endl; 
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
	getch();	
}

void addUser()
{
	system("cls");
	string str;
	char ch[20];
	//����˻� 
	cout<<"�˻���";
	cin>>str;
	
	VR.clear();
	reader R;
	ifstream ifs;
	ifs.open(READER,ios::in);
	while(ifs>>R.m_id&&ifs>>R.m_code&&ifs>>R.lick)
	{
		VR.push_back(R);
	}
	ifs.close();
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++)
	{
		if(it->m_id==str)
		{
			cout<<"�û��Ѵ��ڣ�";
			getch();
			return;
		}
	} 
	
	//������� 
	cout<<endl<<"���룺";
	int i=0; char c; 
    while(1)
	{
        c=getch();
        if(c=='\r')
            break;
        ch[i++]=c;
        putchar('*');
	}
	ch[i]='\0';
	
	ofstream ofs;
	ofs.open(READER,ios::out|ios::app);
	ofs<<str<<" "<<ch<<" "<<0<<endl;
	ofs.close();
	freshReader();
	cout<<"\n\n�����ɹ���";
	getch();
	
}

void Menue()
{
	system("cls");
	
	cout  << "\t\t\t----------------------" << endl

          << "\t\t\t"<< "| ��ӭ����H��ѧͼ��� |" << endl

          << "\t\t\t----------------------" << endl << endl

          << setw( 52 )

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << "\t\t\t" << "( 1 ) ���ߵ�¼" << endl << endl

          << "\t\t\t" << "( 2 ) ����Ա��¼" << endl << endl

          << "\t\t\t" << "( 3 ) �ο͵�¼" << endl << endl

          << "\t\t\t" << "( 4 ) ���������˻�" << endl << endl

          << "\t\t\t" << "( Q ) �˳�" << endl << endl
		  
		  << "\t\t\t" << "����������ѡ�� [ ]" << endl << endl;
		  
	gotoxy(40,17);
			
}

void searchByAuthor()
{
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
	
	system("cls");
	cout<<"����������������";
	string str;cin>>str;
	cout<<"\n���ҽ�����£�\n\n";
	int x=0;
	for(int i=0;i<VB.size();i++)
	{
		if(VB[i].author==str)
		{
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
			x=1;
		}
	}
	if(x==0)
	{
		cout<<"û�������Ϣ\n"; 
	}
	getch();
}

void searchByname()
{
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
	
	system("cls");
	cout<<"�������鼮����";
	string str;cin>>str;
	cout<<"\n���ҽ�����£�\n\n";
	int x=0;
	for(int i=0;i<VB.size();i++)
	{
		if(VB[i].name==str)
		{
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
			x=1;
		}
	}
	if(x==0)
	{
		cout<<"û�������Ϣ\n"; 
	}
	getch();
}

void searchByPublisher()
{
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
	
	system("cls");
	cout<<"����������磺";
	string str;cin>>str;
	cout<<"\n���ҽ�����£�\n\n";
	int x=0;
	for(int i=0;i<VB.size();i++)
	{
		if(VB[i].publishe == str)
		{
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
			x=1;
		}
	}
	if(x==0)
	{
		cout<<"û�������Ϣ\n"; 
	}
	getch();
}

void searchByIsbn()
{
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
	
	system("cls");
	cout<<"�������鼮ISBN��";
	string str;cin>>str;
	cout<<"\n���ҽ�����£�\n\n";
	int x=0;
	for(int i=0;i<VB.size();i++)
	{
		if(VB[i].isbn == str)
		{
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
			x=1;
		}
	}
	if(x==0)
	{
		cout<<"û�������Ϣ\n"; 
	}
	getch();
}

void findBook()
{
	char ses;
	while(1)
	{
		system("cls");
		cout<<"1�������߲���\n"
			<<"2������������\n"
			<<"3����ISBN����\n"
			<<"4�������������\n"
			<<"5�����������鼮\n"
			<<"6������\n\n"
			<<"����������ѡ�";
		cin>>ses;
		switch(ses)
		{
			case '1':
				searchByAuthor();
				break;
			case '2':
				searchByname();
				break;
			case '3':
				searchByIsbn();
				break;
			case '4':
				searchByPublisher();
				break;
			case '5':
				showBook();
				break;
			case '6':
				return; 
				break;
			default:
				break; 
		}
		
	} 
}

void Rlogin()
{
	system("cls");
	cout<<"�˻���";
	string str;
	cin>>str; 
	
	cout<<"\n���룺";
	char ch[20];
	int i=0; char c; 
    while(1)
	{
        c=getch();
        if(c=='\r')
            break;
        ch[i++]=c;
        putchar('*');
	}
	ch[i]='\0';
	
	reader R(str,ch,0);
	//�ж��û� 
	
	VR.clear();
	reader RX;
	ifstream ifs;
	ifs.open(READER,ios::in);
	while(ifs>>RX.m_id&&ifs>>RX.m_code&&ifs>>RX.lick)
	{
		VR.push_back(RX);
	}
	ifs.close();
	int x=0;
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++)
	{
		if(it->m_id==str&&strcmp(it->m_code,ch)==0)
		{
			x=1;break;
		}
	} 
	
	//ʧ��
	if(x==0)
	{
		system("cls");
		cout<<"\n\n�û������ڻ��������";
		getch(); 
		return;
	} 
	
	//�ɹ�
	cout<<"\n\n��¼�ɹ�";
	getch();
	
	char select;
	while(1)
	{
	R.Rmenue();
	cin>>select;
	switch(select)
	{
		case '1':
			R.searchBook();
			break;
		case '2':
			R.BorrowAndBack();
			break;
		case '3':
			R.history();
			break;
		case '4':
			R.modifyCode();
			break;
		case '5':
			R.rank(); 
			break;
		case '6':
			return;
			break;
		case 'Q':
		case 'q':
			exit(0); 
			break;
		default:
			cout<<endl<<"\t\tֻ���������ѡ������������";
			getch();
			break;
	}
    }
		
}

void Alogin()
{
	system("cls");
	
	cout<<"�˻���";
	string str;
	cin>>str; 
	
	cout<<"\n���룺";
	char ch[20];
	int i=0; char c; 
    while(1)
	{
        c=getch();
        if(c=='\r')
            break;
        ch[i++]=c;
        putchar('*');
	}
	ch[i]='\0';
	
	admin A(str,ch);
	
	//�ж��û� 
	VA.clear();
	admin AX;
	ifstream ifs;
	ifs.open(ADMIN,ios::in);
	while(ifs>>AX.m_id&&ifs>>AX.m_code)
	{
		VA.push_back(AX);
	}
	ifs.close();
	
	int x=0;
	for(vector<admin>::iterator it=VA.begin();it!=VA.end();it++)
	{
		if(it->m_id==str&&strcmp(it->m_code,ch)==0)
		{
			x=1;break;
		}
	} 
	
	//ʧ��
	if(x==0)
	{
		cout<<"\n\n�û������ڻ��������!";
		getch();
		return;
	} 
	
	//�ɹ�
	cout<<"\n\n��¼�ɹ�";
	getch();
	
	char select;
	while(1)
	{
	A.Amenue();
	cin>>select;
	switch(select)
	{
		case '1':
			A.checkBook();
			break;
		case '2':
			A.modifyBook();
			break;
		case '3':
			A.removeBook();
			break;
		case '4':
			A.addBook();
			break;
		case '5':
			A.modifyCode();
			break;
		case '6':
			A.manageReader();
			break;
		case '7':
			return;
			break;
		case 'Q':
		case 'q':
			exit(0); 
			break;
		default:
			cout<<endl<<"\t\tֻ���������ѡ������������";
			getch();
			break;
	}
    }
	
}


void Vlogin()
{
	char ses;
	while(1)
	{
		system("cls"); 
		cout <<"\t\t\t\t|||||||||||||||||||||||||||||||" <<endl;
		cout <<"\t\t\t\t|||||||||||||||||||||||||||||||" <<endl;
		cout <<"\t\t\t\t| what would you like to do? ||" << endl;
		cout <<"\t\t\t\t|||||||||||||||||||||||||||||||" <<endl;
		cout <<"\t\t\t\t||| Enter the process number|||" << endl;
		cout <<"\t\t\t\t|||||||||||||||||||||||||||||||" <<endl;
		cout <<"\t\t\t\t||||||||| 1-�鿴�����鼮 ||||||" <<endl;
		cout <<"\t\t\t\t|||||||||||||||||||||||||||||||" <<endl;
		cout <<"\t\t\t\t|||||||||| 2-�����鼮  ||||||||" <<endl;
		cout <<"\t\t\t\t|||||||||||||||||||||||||||||||" <<endl;
		cout <<"\t\t\t\t||||||||||||| 3-���� ||||||||||" <<endl;
		cout <<"\t\t\t\t|||||||||||||||||||||||||||||||" <<endl;
		cout <<"\t\t\t\t|||||||||||||||||||||||||||||||" <<endl;
		cout <<"\t\t\t\t----------------------------( )" <<endl;
		cout << endl;
		gotoxy(61,13);
		cin>>ses;
		switch(ses)
		{
			case '1':
				hotBook();
				break;
			case '2':
				findBook();
				break;			
			case '3':
				return; 
				break;			
			default:
				break;
		}	
		
	} 
	
	
}










