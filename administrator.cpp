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
	cout<<"请输入需要重置的账户：";
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
		cout<<endl<<"无此账户"<<endl; 
		return;
	}
	
	ofstream ofs;
	ofs.open(READER,ios::out|ios::trunc);
	for(vector<reader>::iterator it=VR.begin();it!=VR.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<" "<<it->lick<<endl;
	}
	ofs.close();
	
	cout<<endl<<"重置成功！"<<endl;
	getch(); 
	
}
void admin::checkReader()
{
	system("cls");
	cout<<"用户列表：\n" ;
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
		cout<<"（"<<j<<"）"<<VR[i].m_id<<endl;
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
	 
	cout<<"请输入需要删除的账户：";
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
		cout<<"\n无此账户"<<endl; 
		getch(); 
		return;
	}
	
	char ses;
	do
	{
		system("cls");
		cout<<"是否确定删除（Y/N）\n";
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
	cout<<"\n删除成功！"; 
	
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
	 
	cout<<"请输入需要修改的账户：";
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
		cout<<"\n无此账户"<<endl; 
		getch();
		return;
	}
	//修改账户
	cout<<"\n账户修改为：";
	string str2;
	cin>>str2; 
	
	//修改密码 
	cout<<endl<<"密码修改为：";
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
	cout<<"\n\n修改成功！"; 
	
	getch(); 
}

void admin::addBook()
{
	system("cls");
	cout<<"请输入需要添加书籍的信息\n";
	cout<<"书名：";
	string Name;cin>>Name; 
	cout<<"ISBN：";
	string ISBN;cin>>ISBN;
	cout<<"作者：";	
	string Author;cin>>Author;
	cout<<"价格：";	
	string Price;cin>>Price;
	cout<<"页数：";	
	int Pages;cin>>Pages;
	cout<<"出版社：";
	string Publishe;cin>>Publishe;	
	cout<<"出版日期：";	
	string PublishDate;cin>>PublishDate;
	cout<<"简介：";	
	string Description;cin>>Description;
	cout<<"\n是否添加此书籍（Y/N）";
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
		cout<<"\n添加成功！";
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
	
	cout<<"请输入需要删除图书的书籍名或ISBN：";
	string csc;
	cin>>csc;
	int x=0;
	vector<Book>::iterator its=VB.begin();
	for(vector<Book>::iterator it=VB.begin();it!=VB.end();it++)
	{
		if(it->isbn==csc||it->name==csc)
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
	
	cout<<"\n是否删除此书籍（Y/N）";
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
		cout<<"\n删除成功！";
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
	
	cout<<"请输入需要修改图书的书籍名或ISBN：";
	string csc;
	cin>>csc;
	int x=0;
	vector<Book>::iterator its=VB.begin();
	for(its=VB.begin();its!=VB.end();its++)
	{
		if(its->isbn==csc||its->name==csc)
		{
			cout<<"\n查找结果如下：\n";
			cout<<"书名："<<its->name
				<<"\n作者："<<its->author
				<<"\nISBN："<<its->isbn
				<<"\n价格："<<its->price
				<<"\n页数："<<its->pages 
				<<"\n出版社："<<its->publishe
				<<"\n出版日期："<<its->publisheddate
				<<"\n简介："<<its->description
				<<"\n状态："<<(its->state==1?"已借出":"未借出")
				<<"\n\n";
				x=1;
				break;
		}
	}
	if(x==0)
	{
		cout<<"没有相关信息！";
		getch();
		return;
	}
	
	cout<<"请输入需要修改书籍的信息\n";
	cout<<"书名：";
	string Name;cin>>Name;its->name=Name; 
	cout<<"ISBN：";
	string ISBN;cin>>ISBN;its->isbn=ISBN;
	cout<<"作者：";	
	string Author;cin>>Author;its->author=Author;
	cout<<"价格：";	
	string Price;cin>>Price;its->price=Price;
	cout<<"页数：";	
	int Pages;cin>>Pages;its->pages=Pages;
	cout<<"出版社：";
	string Publishe;cin>>Publishe;its->publishe=Publishe;
	cout<<"出版日期：";	
	string PublishDate;cin>>PublishDate;its->publisheddate=PublishDate;
	cout<<"简介：";	
	string Description;cin>>Description;its->description=Description;
	cout<<"\n是否修改此书籍（Y/N）";
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
		cout<<"\n修改成功！";
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
	cout << "欢迎管理员" << this->m_id << "登录！" << endl<<endl; 
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （1）查询图书            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （2）修改图书            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （3）删除图书            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （4）添加图书            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （5）修改密码            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （6）读者账户管理        |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （7）返回上一级          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         （Q）退出登录            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout <<endl<< "\t\t请选择您的操作： [ ]" << endl;
	gotoxy(34,22);
}
	
void admin::modifyCode()
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
	
	VA.clear();
	admin RX;
	ifstream ifs;
	ifs.open(ADMIN,ios::in);
	while(ifs>>RX.m_id&&ifs>>RX.m_code)
	{
		VA.push_back(RX);
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
	
	for(vector<admin>::iterator it=VA.begin();it!=VA.end();it++)
	{
		if(it->m_id==this->m_id)
		{
			strcpy(it->m_code,ch);
		}
	}
	//将vector存入 
	ofstream ofs;
	ofs.open(ADMIN,ios::out|ios::trunc);
	for(vector<admin>::iterator it=VA.begin();it!=VA.end();it++ )
	{
		ofs<<it->m_id<<" "<<it->m_code<<endl;
	}
	ofs.close();
	cout<<"\n\n密码修改成功！";
	getch();
	
	
}

void admin::manageReader()
{
	char ses;
	while(1)
	{
		system("cls");
		cout<<"1、删除用户\n"
			<<"2、添加用户\n"
			<<"3、修改用户信息\n"
			<<"4、重置用户密码\n"
			<<"5、查看用户列表\n"
			<<"6、返回\n" 
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
		
		
		
		
