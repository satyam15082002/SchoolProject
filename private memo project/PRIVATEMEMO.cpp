#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class A
{
	public:
		char tittle[50],desc[400];
		int un;
		int ui(char file_name[]);
		int show(char file_name[]);
		int add(char file_name[]);
		int d(char file_name[]);
}s;
int A::ui(char file_name[])
{
	char file[30];
	strcpy(file,file_name);
	int reply,opt;
	do{
		system("cls");
		cout<<"\n***************************MENU***********************************\n";
		cout<<"\n 1.Add->add any detail\n2.Show->Showing all store data\n3.Delete->Delete any details \n4.Exit\n";
		cin>>opt;
		switch(opt)
		{
			case 1: add(file); break;
			case 2: show(file); break;
			case 3: d(file); break;
			default: exit(0); break;
		}
		cout<<"\n enter 1 to continue =";
		cin>>reply;
	}while(reply==1);
	return 0;
}
int A::add(char file_name[])
{
	ofstream o(file_name,ios::binary|ios::app);
	char command[]="attrib +h +i +s +a ";
	strcat(command,file_name);
	system(command);
	cout<<"\n Unicode :";
	cin>>un;
	cin.get();
	cout<<"\n enter tittle:\n";
	gets(tittle);
	cout<<"\n enter description=";
	gets(desc);
	o.write((char*)&s,sizeof(s));
	o.close();
	return 0;
}
int A::show(char file_name[])
{
	ifstream i(file_name,ios::in|ios::binary);
	char command[]="attrib +h +i +s +a ";
	strcat(command,file_name);
	system(command);
	while(i.eof()==0)
	{
		i.read((char*)&s,sizeof(s));
		A *ptr;
		ptr=&s;
		cout<<"\n Unicode :"<<ptr->un<<"\n Tittle="<<ptr->tittle<<"\n Description :"<<ptr->desc;
	}
	i.close();
	return 0;
    	
}
int A::d(char file_name[])
{
	ifstream i(file_name,ios::in|ios::binary);
	ofstream o("temp.dat",ios::out|ios::binary);
	char command[]="attrib +h +i +s +a ";
	strcat(command,file_name);
	system(command);
	show(file_name);
	int id;
	cout<<"\n enter unicode to delete that record :";
	cin>>id;
	while(i.eof()==0)
	{
	
		i.read((char*)&s,sizeof(s));
		if(id==s.un)
		{
			continue;
		}
		else
		{
		o.write((char*)&s,sizeof(s));
	    }

	}
	i.close();
	o.close();
	remove(file_name);
	rename("temp.dat",file_name);
	system(command);
	cout<<"\n suceesfull";
	return 0;
}
struct B
{
	char user_name[30];
	char password[30];
	char filen[30];
}a;
int signup()
{
    cin.get();
	cout<<"\n username=";
	gets(a.user_name);
	cout<<"\n password =";
	gets(a.password);
	int l;
	do{
	cout<<"\n filename(enter at least 5 character) =";
	gets(a.filen);
	 l=strlen(a.filen);
    }while(l<5);
	char ext[]=".dat";
	strcat(a.filen,ext);
	ofstream out(a.filen,ios::app|ios::binary);
	out.close();
	ofstream o("account.dat",ios::app|ios::binary);
	o.write((char*)&a,sizeof(a));
	o.close();
	system("attrib +h +i +s +a account.dat");
	char command[]="attrib +h +i +s +a ";
	strcat(command,a.filen);
	system(command);
	return 0;
}
int login()
{
	int c=0;
	char un[30],pass[30];
	cin.get();
	cout<<"\n enter username =";
	gets(un);
	cout<<"\n enter password =";
	gets(pass);
	ifstream i("account.dat",ios::app|ios::binary);
	while(i.eof()==0)
	{
		i.read((char*)&a,sizeof(a));
		if(strcmpi(a.user_name,un)==0&&strcmpi(a.password,pass)==0)
		{
			c++;
			s.ui(a.filen);
		}
		
	}
	if(c!=0)
	{
		cout<<"\n you are logined ";
	}
	else
	{
		cout<<"\n invalid account";
	}
	i.close();
	return 0;
}

int main()
{
	int opt,reply;
	for(int i=1;i<4;i++)
	cout<<"\n \n";
	cout<<setw(420)<<"PRIVATE MEMO";
	cout<<setw(400)<<"\n\n enter any key to continue";
	cin.get();
	do{
		system("cls");
	    cout<<"\n***************************MENU***********************************\n";
		cout<<"\n 1.Signup->enter to make account \n 2.Login-> login to your account to use this software \n 3.Exit\n";
		cin>>opt;
		switch(opt)
		{
			case 1: signup(); break;
			case 2: login(); break;
			default: exit(0);
			
		}
		cout<<"\n enter 1 to continue =";
		cin>>reply;
	}while(reply==1);
	system("pause");
	return 0;
}
