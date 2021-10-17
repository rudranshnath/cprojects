#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
class BankAccount
{
	int AccountNo;
	char name[20];
	float balance;
	static int count;
	public:
	     BankAccount()
	     {
		 count++;
	     }
	     void Enter()
	     {
		 cout<<"Enter Accoount Holder Name :";
		 gets(name);
		 cout<<"Enter Account No :";
		 cin>>AccountNo;
		 cout<<"Enter the initial amount deposited :";
		 cin>>balance;
	     }
	     void Withdraw()
	     {   int withdrawAmt,i;
		 cout<<"Enter account No : ";
		 cin>>AccountNo;
		 for(i=0;i<=5;i++)
		  {
		   if (B[i].AccountNo==AccountNo)
			{  cout<<"Enter amount withdraw : ";
			   cin>>withdrawAmt;
			   B[i].balance=B[i].balance-withdrawAmt;
			}
		   else
		      {
			cout<<"Error !!";
			Withdraw();
		      }
		    }
	     }
	      void deposite()
	     {   int depositeAmt,i;
		 cout<<"Enter account No : ";
		 cin>>AccountNo;
		 for(i=0;i<=5;i++)
		   if (B[i].AccountNo==AccountNo)
			{  cout<<"Enter amount Deposite : ";
			   cin>>depositeAmt;
			   B[i].balance=B[i].balance+depositeAmt;
			}
		   else
		       {
			cout<<"Error !!";
			deposite();
		       }
	     }
	     void Display()
	     {
	       cout<<AccountNo<<"\t"<<balance<<"\t"<<name<<endl;
	     }
}B[5];
int BankAccount::count;
void main()
{
clrscr();

for(int x=0;x<=2;x++)
  {
   B[x].Enter();
  }

for(x=0;x<=2;x++)
  {
   B[x].Display();
  }
getch();
}
