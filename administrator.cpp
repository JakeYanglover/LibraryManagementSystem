#include"administrator.h"
extern vector<reader> VR;
extern vector<admin> VA;
extern vector<Book> VB; 
extern vector<RecordReader> VRR; 
extern bool cmp3(reader r1,reader r2); 

admin::admin(string s,char* c)
{
	this->m_id=s;
	strcpy(this->m_code,c);	
}

admin::admin()
{
	
}

void admin::resetReader()
{
	system("cls");
	VR.clear();
	reader R;
	ifstream ifs;
	ifs.open(READER,ios::in);
	while(ifs>>R.m_id&&ifs>>R.m_code&&ifs>>R.lick)
	{
		VR.push_back(R);
	}
	ifs.close();
	cout<<"��������Ҫ���õ��˻���";
	string str;cin>>str; 
	int x=0;
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++)
	{
		if(it->m_id==str)
		{
			x=1;
			strcpy(it->m_code,"123456");
			break;
		}
	}
	if(x==0)
	{
		cout<<endl<<"�޴��˻�"<<endl; 
		return;
	}
	
	ofstream ofs;
	ofs.open(READER,ios::out|ios::trunc);
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<" "<<it->lick<<endl;
	}
	ofs.close();
	
	cout<<endl<<"���óɹ���"<<endl;
	getch(); 
	
}
void admin::checkReader()
{
	system("cls");
	cout<<"�û��б�\n" ;
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
	for(int i=0,j=1;i<VR.size();i++,j++)
	{
		cout<<"��"<<j<<"��"<<VR[i].m_id<<endl;
	}
	getch();	
}
void admin::addReader()
{
	addUser();
}

void admin::removeReader()
{
	system("cls");
	VR.clear();
	reader R;
	ifstream ifs;
	ifs.open(READER,ios::in);
	while(ifs>>R.m_id&&ifs>>R.m_code&&ifs>>R.lick)
	{
		VR.push_back(R);
	}
	ifs.close();
	 
	cout<<"��������Ҫɾ�����˻���";
	string str;cin>>str; 
	int x=0;
	vector<reader>::iterator its=VR.begin();
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++)
	{
		if(it->m_id==str)
		{
			its=it;
			x=1;break; 
		}
	}
	if(x==0)
	{
		cout<<"\n�޴��˻�"<<endl; 
		getch(); 
		return;
	}
	
	char ses;
	do
	{
		system("cls");
		cout<<"�Ƿ�ȷ��ɾ����Y/N��\n";
		cin>>ses;
	}
	while(ses!='Y'&&ses!='y'&&ses!='N'&&ses!='n');
	if(ses=='n'||ses=='N')
	{
		return;
	}
	
	VR.erase(its);
	

	ofstream ofs;
	ofs.open(READER,ios::out|ios::trunc);
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<" "<<it->lick<<endl;
	}
	ofs.close();
	cout<<"\nɾ���ɹ���"; 
	
	getch(); 
		
	
}
void admin::modifyReader()
{
	system("cls");
	VR.clear();
	reader R;
	ifstream ifs;
	ifs.open(READER,ios::in);
	while(ifs>>R.m_id&&ifs>>R.m_code&&ifs>>R.lick)
	{
		VR.push_back(R);
	}
	ifs.close();
	 
	cout<<"��������Ҫ�޸ĵ��˻���";
	string str;cin>>str; 
	int x=0;
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++)
	{
		if(it->m_id==str)
		{
			x=1;break; 
		}
	}
	if(x==0)
	{
		cout<<"\n�޴��˻�"<<endl; 
		getch();
		return;
	}
	//�޸��˻�
	cout<<"\n�˻��޸�Ϊ��";
	string str2;
	cin>>str2; 
	
	//�޸����� 
	cout<<endl<<"�����޸�Ϊ��";
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
	
	vector<reader>::iterator its=VR.begin();
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++)
	{
		if(it->m_id==str)
		{
			its=it;
			strcpy(it->m_code,ch);
			break;
		}
	}
	its->m_id=str2;
	
	ofstream ofs;
	ofs.open(READER,ios::out|ios::trunc);
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<" "<<it->lick<<endl;
	}
	ofs.close();
	cout<<"\n\n�޸ĳɹ���"; 
	
	getch(); 
}

void admin::addBook()
{
	system("cls");
	cout<<"��������Ҫ����鼮����Ϣ\n";
	cout<<"������";
	string Name;cin>>Name; 
	cout<<"ISBN��";
	string ISBN;cin>>ISBN;
	cout<<"���ߣ�";	
	string Author;cin>>Author;
	cout<<"�۸�";	
	string Price;cin>>Price;
	cout<<"ҳ����";	
	int Pages;cin>>Pages;
	cout<<"�����磺";
	string Publishe;cin>>Publishe;	
	cout<<"�������ڣ�";	
	string PublishDate;cin>>PublishDate;
	cout<<"��飺";	
	string Description;cin>>Description;
	cout<<"\n�Ƿ���Ӵ��鼮��Y/N��";
	char ses;
	cin>>ses;
	if(ses=='y'||ses=='Y')
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
		
		int size=VB.size()+1;
		Book B2;
		B2.author=Author;
		B2.description=Description;
		B2.isbn=ISBN;
		B2.like=0;
		B2.name=Name;
		B2.pages=Pages;
		B2.price=Price;
		B2.publishe=Publishe;
		B2.publisheddate=PublishDate;
		B2.state=0;
		B2.id=size;
		VB.push_back(B2);
		
		ofstream ofs;
		ofs.open(BOOK,ios::out|ios::trunc);
		for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++ )
		{
			ofs<<it->id<<" "<<it->pages<<" "<<it->price<<" "<<it->state<<" "<<it->like<<" "
			   <<it->isbn<<'\t'<<it->name<<'\t'<<it->author<<'\t'<<it->publishe<<'\t'
			   <<it->publisheddate<<'\t'<<it->description<<endl;
		}
		ofs.close();
		cout<<"\n��ӳɹ���";
		getch();
	}
	else return;
	
}

void admin::removeBook()
{
	system("cls"); 
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
	
	cout<<"��������Ҫɾ��ͼ����鼮����ISBN��";
	string csc;
	cin>>csc;
	int x=0;
	vector<Book>::iterator its=VB.begin();
	for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++)
	{
		if(it->isbn==csc||it->name==csc)
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
	
	cout<<"\n�Ƿ�ɾ�����鼮��Y/N��";
	char ses;
	cin>>ses;
	if(ses=='y'||ses=='Y')
	{
		VB.erase(its); 
		ofstream ofs;
		ofs.open(BOOK,ios::out|ios::trunc);
		for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++ )
		{
			ofs<<it->id<<" "<<it->pages<<" "<<it->price<<" "<<it->state<<" "<<it->like<<" "
			   <<it->isbn<<'\t'<<it->name<<'\t'<<it->author<<'\t'<<it->publishe<<'\t'
			   <<it->publisheddate<<'\t'<<it->description<<endl;
		}
		ofs.close();
		cout<<"\nɾ���ɹ���";
		getch();
	} 
}

void admin::modifyBook()
{
	system("cls"); 
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
	
	cout<<"��������Ҫ�޸�ͼ����鼮����ISBN��";
	string csc;
	cin>>csc;
	int x=0;
	vector<Book>::iterator its=VB.begin();
	for(its=VB.begin();its!=VB.end();its++)
	{
		if(its->isbn==csc||its->name==csc)
		{
			cout<<"\n���ҽ�����£�\n";
			cout<<"������"<<its->name
				<<"\n���ߣ�"<<its->author
				<<"\nISBN��"<<its->isbn
				<<"\n�۸�"<<its->price
				<<"\nҳ����"<<its->pages 
				<<"\n�����磺"<<its->publishe
				<<"\n�������ڣ�"<<its->publisheddate
				<<"\n��飺"<<its->description
				<<"\n״̬��"<<(its->state==1?"�ѽ��":"δ���")
				<<"\n\n";
				x=1;
				break;
		}
	}
	if(x==0)
	{
		cout<<"û�������Ϣ��";
		getch();
		return;
	}
	
	cout<<"��������Ҫ�޸��鼮����Ϣ\n";
	cout<<"������";
	string Name;cin>>Name;its->name=Name; 
	cout<<"ISBN��";
	string ISBN;cin>>ISBN;its->isbn=ISBN;
	cout<<"���ߣ�";	
	string Author;cin>>Author;its->author=Author;
	cout<<"�۸�";	
	string Price;cin>>Price;its->price=Price;
	cout<<"ҳ����";	
	int Pages;cin>>Pages;its->pages=Pages;
	cout<<"�����磺";
	string Publishe;cin>>Publishe;its->publishe=Publishe;
	cout<<"�������ڣ�";	
	string PublishDate;cin>>PublishDate;its->publisheddate=PublishDate;
	cout<<"��飺";	
	string Description;cin>>Description;its->description=Description;
	cout<<"\n�Ƿ��޸Ĵ��鼮��Y/N��";
	char ses;
	cin>>ses;
	if(ses=='y'||ses=='Y')
	{
		ofstream ofs;
		ofs.open(BOOK,ios::out|ios::trunc);
		for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++ )
		{
			ofs<<it->id<<" "<<it->pages<<" "<<it->price<<" "<<it->state<<" "<<it->like<<" "
			   <<it->isbn<<"\t"<<it->name<<"\t"<<it->author<<"\t"<<it->publishe<<"\t"
			   <<it->publisheddate<<"\t"<<it->description<<endl;
		}
		ofs.close();
		cout<<"\n�޸ĳɹ���";
		getch();
	} 
	
}

void admin::checkBook()
{
	findBook();	
}

void admin::Amenue()
{
	system("cls");
	cout << "��ӭ����Ա" << this->m_id << "��¼��" << endl<<endl; 
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��1����ѯͼ��            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��2���޸�ͼ��            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��3��ɾ��ͼ��            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��4�����ͼ��            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��5���޸�����            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��6�������˻�����        |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��7��������һ��          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         ��Q���˳���¼            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout <<endl<< "\t\t��ѡ�����Ĳ����� [ ]" << endl;
	gotoxy(34,22);
}
	
void admin::modifyCode()
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
	
	VA.clear();
	admin RX;
	ifstream ifs;
	ifs.open(ADMIN,ios::in);
	while(ifs>>RX.m_id&&ifs>>RX.m_code)
	{
		VA.push_back(RX);
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
	
	for(vector<admin>::iterator it=VA.begin();it!=VA.end();it++)
	{
		if(it->m_id==this->m_id)
		{
			strcpy(it->m_code,ch);
		}
	}
	//��vector���� 
	ofstream ofs;
	ofs.open(ADMIN,ios::out|ios::trunc);
	for(vector<admin>::iterator it=VA.begin();it!=VA.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<endl;
	}
	ofs.close();
	cout<<"\n\n�����޸ĳɹ���";
	getch();
	
	
}

void admin::manageReader()
{
	char ses;
	while(1)
	{
		system("cls");
		cout<<"1��ɾ���û�\n"
			<<"2������û�\n"
			<<"3���޸��û���Ϣ\n"
			<<"4�������û�����\n"
			<<"5���鿴�û��б�\n"
			<<"6������\n" 
			<<"-----------------> ";
		cin>>ses;
		switch(ses)
		{
		case '1':
			this->removeReader(); 
			break;
		case '2':
			this->addReader();
			break;
		case '3':
			this->modifyReader();
			break;
		case '4':
			this->resetReader();
			break;
		case '5':
			this->checkReader();
			break;
		case '6':
			return;
			break;
		default:
			return;
			break;
		}
	}
}
		
		
		
		
