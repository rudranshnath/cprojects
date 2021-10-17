/**********************************BANK.CPP***********************************
		   Name          : Rudransh Nath Tripathi
		   Class         : XII th - A
		   Date Created  : 28-03-2019
		   Date Modified : 28-03-2019
***********************************BANK.CPP***********************************/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>


const int Size=5;
int i=0;
class Bank_Account
{
	static int Count;                   //Static Data member
	int AccNo;
	char Name[20];
	float Balance;

 public:
	Bank_Account()
	{
		AccNo=00;
		strcpy(Name,"N-I-L");
		Balance=00000;
		Count++;
	}

	int getaccno()
	{
		return AccNo;
	}

	int getbalance()
	{
		return Balance;
	}

	void enter()
	{
		cout<<"Enter the AccNo   : ";
		cin>>AccNo;
		cout<<"Enter the name    : ";
		gets(Name);
		cout<<"Enter the balance : ";
		cin>>Balance;
	}
	void withdraw(float amt)
	{
		Balance=Balance-amt;
	}

	void deposit(float amt)
	{
		Balance=Balance+amt;
	}
	void show()
	{     cout<<setw(8)<<AccNo<<setw(16)<<Name<<setw(11)<<Balance<<endl;
	   /* cout<<AccNo<<'\t'<<name<<"\t\t"<<Balance<<'\t'<<endl;*/
	}
	static void showcount()
	{
	     cout<<Count;
	}
};
int Bank_Account::Count;

void Account_Holder();                                //F u
void Add_account(Bank_Account B[]);                    //  n c
void Display_Account(Bank_Account B[]);                //    t i
void Main_menu(Bank_Account B[]);                                     //      o n
void Admin_top();                                     //
void Admin_menu(Bank_Account B[]);                     //P r o
int Search_Account(Bank_Account B[],int Svalue);       //    t o
void Account_Holder_Top();                            //      t y
void Account_Holder(Bank_Account B[]);                 //        p e

void Add_account(Bank_Account B[])          //
{       int opt;
	clrscr();
	Admin_top();
	for(int i=0;i<Size;i++)
	{
		  B[i].enter();
		  cout<<"Type |1| to  add another account : ";
		  cin>>opt;
		  if(!(opt==1))
			break;
	}
}

void Display_Account(Bank_Account B[])     //
{       clrscr();
	Admin_top();
	cout<<"       AccNo"<<'\t'<<"Name"<<"\t\t"<<"Balance"<<'\t'<<endl;
	for(i=0;i<Size;i++)
	{
		  B[i].show();
		  getch();
	}
	getch();
}

void Main_menu(Bank_Account B[])              //
{       int opt=0;
	Menu:
	clrscr();
	cout<<"#################################################################\n";
	cout<<"#################################################################\n";
	cout<<"(1)	Admin	         \n";
	cout<<"(2)	Account Holder   \n";
	cout<<"(3)	Shut Down	 \n";
	cout<<"#################################################################\n";
	cout<<"Choose your option : ";
	cin>>opt;
	if(opt==1)
	{
		Admin_menu(B);
	}
	else if(opt==2)
	{
		Account_Holder(B);
	}
	goto Menu;
}

void Admin_top()                            //
{	cout<<"############################################################ADMIN\n";}
void Admin_menu(Bank_Account B[])            //
{
	label:
	clrscr();
	int opt;
	Admin_top();
	cout<<"#################################################################\n";
	cout<<"(1)	Add account	\n";
	cout<<"(2)	Display account	\n";
	cout<<"(3)	Delete account	\n";
	cout<<"(4)	Update account	\n";
	cout<<"(5)	No.of account	\n";
	cout<<"(6)	Log Out		\n";
	cout<<"(7)	Shut Down	\n";
	cout<<"#################################################################\n";
	cout<<"Choose your Option : ";
	cin>>opt;
	if(opt==1)
	{
		Add_account(B);
		goto label;
	}
	else if((opt==2)||(opt==3))
	{
		Display_Account(B);
		if(opt==3)
		{}
		goto label;
	}


	else if(opt==5)
	{
		cout<<"Total Number of accounts can be created : ";
		Bank_Account::showcount();
		cout<<endl;
		goto label;
	}
	else if(opt==6)
	{
		Main_menu(B);
	}
	else if(opt==7)
	{
		exit(0);
	}
}

int Search_Account(Bank_Account B[],int Svalue) //
{
	for(int i=0;i<Size;i++)
	{
		int AccNumber1=B[i].getaccno();
		if(Svalue==AccNumber1)
		{
			break;}

	}
	return i;
}
/*int beg=0;
	int index;
	int end=size;
	int mid;
	int flag=0,i=0;
	while((i<size)||(flag))
	{
		mid=(beg+end)/2;
		int AccNumber=B[mid].getaccno();
		if(Svalue==AccNumber)
		{	flag=1;
			index=mid;
		}
		else if(Svalue>AccNumber)
		{	beg=mid;
		}
		else if(Svalue<AccNumber)
		{	end=mid;
		}
		i++;

	}
	return index;*/

void Account_Holder_Top()                    //
{
	cout<<"###################################################ACCOUNT-HOLDER\n";
	}
void Account_Holder(Bank_Account B[])         //
{       int opt=0,index,AccNumber;
	int amt;
	clrscr();
	Account_Holder_Top();
	cout<<"#################################################################\n";
	cout<<"(1)	Balance Enquiry \n";
	cout<<"(2)	Withdraw Money  \n";
	cout<<"(3)	Deposit Money	\n";
	cout<<"(4)	Log Out		\n";
	cout<<"#################################################################\n";
	cout<<"Choose your option : ";
	cin>>opt;

	cout<<"Enter your Account No.";
	cin>>AccNumber;
	index=Search_Account(B,AccNumber);
       //	if(opt==1)

		cout<<"Your Balance is  $ "<<B[index].getbalance()<<endl;

	if(opt==2)
	{
		cout<<"Enter the amount to be withdrawl";
		cin>>amt;
		B[index].withdraw(amt);
	}
	else if(opt==3)
	{
		cout<<"Enter the amoun to be deposited";
		cin>>amt;
		B[index].deposit(amt);
	}
	else if(opt==4)
	{       Main_menu(B);
	}
}
void main()
{
	clrscr();
	Bank_Account B[Size];
	Display_Account(B);
	getch();
	Main_menu(B);
	getch();

}