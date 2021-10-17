#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>


class BloodBank
{
	char Name[30];
	int Age;
	char Tno[15];

      public:
	char Bloodgroup[5];
	BloodBank()
	{	strcpy(Name,"N-I-L");
		Age=0;
		strcpy(Tno,"000000");
		strcpy(Bloodgroup,"--");
	}
	void accept()
	{
		cout<<"\nEnter Name : ";
		gets(Name);
		cout<<"\nEnter Age  : ";
		cin>>Age;
		cout<<"\nEnter Telephone number : ";
		gets(Tno);
		cout<<"\nEnter Blood Group : ";
		gets(Bloodgroup);
	}
	void display()
	{
		cout<<"\n Name : "<<Name<<endl;
		cout<<"\n Age  : "<<Age<<endl;
		cout<<"\n Telephone number : "<<Tno<<endl;
		//cout<<"\n Blood Group  : "<<Bloodgroup<<endl;
	}
	char* getTno()
	{
		return Tno;
	}



};

void displayrecords();
void appendrecords();
void modifyrecords();

void main()
{       clrscr();
	int opt;
	cout<<"\n***********************************************************************\n";
	cout<<"1. Display name,age and phone number of all Donors of given Blood group\n";
	cout<<"2. Append records in the file \n";
	cout<<"3. Input a telephone number and modify the record\n";
	cout<<"***********************************************************************\n";
	cout<<"Choose your option : ";
	cin>>opt;
	if(opt==1)
	{    clrscr();
	     displayrecords();

	}
	else if(opt==2)
	{
		clrscr();
		appendrecords();
	}
	else if(opt==3)
	{
		clrscr();
		modifyrecords();
	}




	getch();
}

void displayrecords()
{
	fstream file;
	file.open("BloodBank.dat",ios::binary|ios::in);
	if(!file)
	{	cout<<"File opening error";
		exit(1);
	}
	BloodBank B;
	int flag=0;
	char Bg[5];
	cout<<"Enter Blood group ";
	gets(Bg);

	while(!file.eof())
	{	file.read((char*)&B,sizeof(B));
		if(!strcmpi(B.Bloodgroup,Bg))
		{       flag=1;
			B.display();
		}
		else
			continue;
	}
	if(!flag)
	{	cout<<"\nRecord not found ";
	}

	file.close();
}

void appendrecords()
{
	fstream file;
	file.open("BloodBank.dat",ios::binary|ios::app);
	BloodBank B;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{ 	B.accept();
		file.write((char*)&B,sizeof(B));
		cout<<"Want to add more records (y/n)";
		cin>>ch;
	}


	file.close();
}

void modifyrecords()
{
	fstream file;
	file.open("BloodBank.dat",ios::binary|ios::ate|ios::in|ios::app);
	if(!file)
	{	cout<<"File opening error";
		exit(1);
	}
	BloodBank B;
	file.seekp(0,ios::beg);
	while(file.eof()==0)
	{	char Tno[15];
		cout<<"Enter telephone number  = ";
		gets(Tno);
		file.read((char*)&B,sizeof(B));
		if(!strcmp(Tno,B.getTno())
		{
		}
	}
}