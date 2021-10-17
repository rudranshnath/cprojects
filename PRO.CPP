#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>

class Student
{
	int rno;
	char name[30];
	float marks;
      public:
	Student()
	{
		rno=0;
		strcpy(name,"N-I-L");
		marks=0.0;
	}
	int getrno()
	{
		return rno;
	}
	void accept()
	{
		cout<<"Enter the roll no : ";
		 cin>>rno;
		cout<<"Enter the name : ";
		 gets(name);
		cout<<"Enter your marks : ";
		 cin>>marks;
	}
	void display()
	{
		cout<<rno<<'\t'<<name<<'\t'<<marks<<endl;
	}


};

void Displayfromthefile()
{
	Student S;
	fstream file;
	file.open("Student.dat",ios::in|ios::binary);

	while(1)
	{
		file.read((char*)&S,sizeof(S));
		if(file.eof())
			break;
		S.display();
	}
	file.close();
	getch();
}

void Addinginthefile()
{       clrscr();
	int n;
	Student S;
	getch();
	cout<<"How many records u want to enter ? \n";
	cout<<"Answer : ";
	cin>>n;
	fstream file;
	file.open("Student.dat",ios::out|ios::binary|ios::app);
	for(int i=0; i<n; i++)
	{
		S.accept();
		file.write((char*)&S,sizeof(S));
	}
	file.close();
}

void Deletefromthefile()
{       clrscr();
	Student S;
	int rn,flag=0;
	char confirm='n';
	cout<<"Enter rno of student whose record is to be deleted : ";
	cin>>rn;
	fstream file,temp;
	temp.open("temp.dat",ios::out|ios::binary);
	file.open("Student.dat",ios::in|ios::binary);
	while(1)
	{       file.read((char*)&S,sizeof(S));
		if(file.eof())
			break;
		if(S.getrno()==rn)
		{
			S.display();
			flag=1;
			cout<<"Are u sure, u want 2 delete? (y/n) \nAnswer :";
			cin>>confirm;
			if(confirm=='n')
			{
				temp.write((char*)&S,sizeof(S));
			}
		}
		else
			temp.write((char*)&S,sizeof(S));

	}
	if(flag==0)
	{
		cout<<"Record not found\n";
	}
	file.close();
	temp.close();
	remove("Student.dat");
	rename("temp.dat","Student.dat");
	getch();
}

void Sortingthefile();
/*
{       int size=30;
	Student S[30];
	fstream file;
	fstream temp;
	file.open("Student.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);

	for(int i=0; i<30; i++)
	{
		file.read((char*)&S[i],sizeof(Student));
		if(file.eof())
		{
			break;
		}
	}
	for( i=0; i<size; i++)
	{
		for(int j=0; j<=i; j++)
		{	int x,y;
			x=S[j].getrno();
			y=S[j+1].getrno();
			if(x>y)
			{
				Student t=S[j];
				S[j]=S[j+1];
				S[j+1]=t;
			}
		}
	}
	for( i=0; i<size; i++)
	{
		temp.write((char*)&S[i],sizeof(Student));
	}
	file.close();
	temp.close();
	remove("Student.dat");
	rename("temp.dat","Student.dat");
	getch();
}*/

void Searchingarecord()
{       Student S;
	int rn;
	cout<<"Enter the rno of student whose record to be displayed : ";
	 cin>>rn;
	fstream file;
	file.open("Student.dat",ios::in|ios::binary);
	for(int i=0; i>-1; i++)
	{
		file.read((char*)&S,sizeof(S));
		if(file.eof())
			break;
		if(S.getrno()==rn)
			S.display();
	}
	getch();
}

void Insertinasortedfile();
/*
{
	int flag=1;
	Student S,S1;
	fstream file,temp;
	file.open("Student.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	cout<<"Enter the details of student whose record to be inserted \n";
	S.accept();
	while(1)
	{
		file.read((char*)&S1,sizeof(S1));
		if(file.eof())
			break;
		if(S.getrno()<=S1.getrno())
		{
			temp.write((char*)&S,sizeof(S));
			flag=0;
			break;
		}
		else
			temp.write((char*)&S1,sizeof(S1));
	}
	if(flag==1)
		temp.write((char*)&S,sizeof(S));

	else if(!file.eof())
	{
		while(1)
		{
			file.read((char*)&S1,sizeof(S1));
			temp.read((char*)&S1,sizeof(S1));

		}
	}
	file.close();
	temp.close();
}*/

void main()
{
	clrscr();
	int opt=0;
    while(1)
    {   clrscr();
	cout<<"################################################################\n";
	cout<<"#1. Display the records \n";
	cout<<"#2. Add new records     \n";
	cout<<"#3. Delete specific records\n";
	cout<<"#4. Searching a record    \n";
	cout<<"#5. Inserting a record at appropriate position \n";
	cout<<"################################################################\n";
	cout<<"Choose your option : ";
	cin>>opt;
	if(opt==1)
	{
		Displayfromthefile();
	}
	else if(opt==2)
	{
		Addinginthefile();
	}
	else if(opt==3)
	{
		Deletefromthefile();
	}
	else if(opt==4)
	{
		Searchingarecord();
	}
	else if(opt==5)
	{
		Insertinasortedfile();
	}
	else
		exit(1);
    }


}
