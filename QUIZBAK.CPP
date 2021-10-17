/*                                      
			   Name      : Rudransh Nath Tripathi
			   Class     : XII - A
		       Date Created  : 13/05/2019
		       Date Modified : 18/05/2019
		      Date QUIZBAK created :12/06/2019
                                       */
//-----------------------H E A D E R--F I L E s-------------------------------
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
//----------------------------------------------------------------------------
//--------------------C L A S S--D E F I N I T I O N s------------------------
class Question                            //Class "Question" is defined
{  //----private-data-members---------------------//
	char ques[150];
	char optA[70];
	char optB[70];
	char optC[70];
	char optD[70];
	char Answer;
   //---------------------------------------------//
      public:
   //----public-member-functions------------------//
	void getques()
	{
	       cout<<"Enter your Question : \n";
		gets(ques);
	       cout<<"Enter Option A : \n";
		gets(optA);
	       cout<<"Enter Option B :\n";
		gets(optB);
	       cout<<"Enter Option C :\n";
		gets(optC);
	       cout<<"Enter Option D :\n";
		gets(optD);
	       cout<<"Which option is correct : ";
		cin>>Answer;
	}
	void adminoutput()
	{
		cout<<"Question -> "<<ques<<'\n';
		cout<<"(A) "<<optA<<'\n';
		cout<<"(B) "<<optB<<'\n';
		cout<<"(C) "<<optC<<'\n';
		cout<<"(D) "<<optD<<'\n';
		cout<<"The answer is option "<<Answer<<'\n';
	}
	void output()
	{
		cout<<"\tQuestion ->\n\t"<<ques<<'\n';
		cout<<"\t (A) "<<optA<<'\n';
		cout<<"\t (B) "<<optB<<'\n';
		cout<<"\t (C) "<<optC<<'\n';
		cout<<"\t (D) "<<optD<<'\n';
	}
	char getanswer()
	{
		return Answer;
	}
    //-------------------------------------------//
};
class Player                              //class "Player" is defined
{  //------private-data-members------------------//
	int id;
	char name[30];
	int age;
	char gender;
	double points;
   //--------------------------------------------//
      public:
   //-----public-member-functions----------------//
	Player()                          //constructor
	{
		strcpy(name,"N-I-L");
		age=0;
		points=0;
	}
	void getdata()
	{       cout<<"\tEnter Player id: ";
		 cin>>id;
		cout<<"\tEnter Your Name : ";
		 gets(name);
		cout<<"\tEnter Your Age : ";
		 cin>>age;
		cout<<"\tEnter Your Gender (M/F): ";
		 cin>>gender;
	}
	void putdata()
	{
		cout<<id<<'\t'<<name<<'\t'<<age<<'\t'<<gender<<'\t'<<points<<'\n';
	}
	void putpoints(double x)
	{
		points=x;
	}
	char* getname()
	{
		return name;
	}
	int getid()
	{
		return id;
	}
   //--------------------------------------------//
}p;                                       //class definition ends here
//------------------------------------------------------------------------------
//----------------F U N C T I O N--P R O T O T Y P E s--------------------------
void Admin();
void Player();
void See_Questions(int x);
void Modify_Questions(int x);
void Add_Questions(int x);
void Delete_Questions(int x);
void Money_list();
void StartGame(char name[],int id);
void Boundary();
void Check(int id);
//------------------------------------------------------------------------------
//-------------------------M A I N--F U N C T I O N-----------------------------
void main()
{       menu:
	clrscr();
	int user;
	gotoxy(4,6);
	cout<<"\t##############################################################\n";
	cout<<"\t\t#1. Admin   \n";
	cout<<"\t\t#2. Player  \n";
	cout<<"\t##############################################################\n";
	cout<<"\tChoose the user : "; Boundary();
	gotoxy(28,10);
	cin>>user;
	if(user==1)
	{       char pass[20];
		clrscr();
		cout<<"\n\n\n\n\n\tP A S S W O R D  :  "; Boundary(); gotoxy(29,6);
		gets(pass);
		if((strcmpi(pass,"HELLO-MOTO"))==0)
			Admin();
		else
		{	cout<<"Wrong Password ";
			getch();
			goto menu;
		}
	}
	else if(user==2)
	{
		Player();
	}
	else exit(1);
}
//------------------------------------------------------------------------------
//------------------F U N C T I O N--D E F I N I T I O N s----------------------
//------------------------------------------------------------------------------
void Admin()                              //function defined for admin operation
{       int opt=0;
	int quess_set=0;
	while(1)
	{	clrscr();
		gotoxy(4,6);
		cout<<"\t##############################################################\n";
		gotoxy(57,7);
		cout<<"rudra2106\n";
		cout<<"\t##############################################################\n";
		cout<<"\t\t#1. See Questions    \n";
		cout<<"\t\t#2. Modify Questions \n";
		cout<<"\t\t#3. Add Questions    \n";
		cout<<"\t\t#4. Delete Questions \n";
		cout<<"\t\t#5. Records of Players\n";
		cout<<"\t##############################################################\n";
		cout<<"\tChoose a option : ";
		Boundary();
		gotoxy(28,15);
		 cin>>opt;
		if(opt==1)
		{       clrscr();
			gotoxy(4,3);
			cout<<"Which of the following type question did u want to see ?\n";
			Money_list();
			gotoxy(9,20);
			cout<<"Choose set of Questions : ";
			gotoxy(37,20);
			 cin>>quess_set;
			clrscr();
			See_Questions(quess_set);

		}
		else if(opt==2)
		{       clrscr();
			gotoxy(4,3);
			cout<<"Which set of Questions u want to modify ?\n";
			Money_list();
			gotoxy(9,20);
			cout<<"Choose set of Questions : ";
			gotoxy(37,20);
			cin>>quess_set;
			clrscr();
			Modify_Questions(quess_set);
		}
		else if(opt==3)
		{       clrscr();
			gotoxy(4,3);
			cout<<"Which type of Questions did u want to add ?\n";
			Money_list();
			gotoxy(9,20);
			cout<<"Choose type of Question : ";
			gotoxy(37,20);
			cin>>quess_set;
			clrscr();
			Add_Questions(quess_set);
		}
		else if(opt==4)
		{       clrscr();
			gotoxy(4,3);
			cout<<"Which type of Questions did u want to delete ?\n";
			Money_list();
			gotoxy(9,20);
			cout<<"Choose Your option : ";
			gotoxy(37,20);
			cin>>quess_set;
			clrscr();
			Delete_Questions(quess_set);
		}
		else if(opt==5)
		{
			clrscr();
			fstream file;
			int i=3;
			file.open("Player.dat",ios::in|ios::binary);
			gotoxy(4,i);
			cout<<"\t################################################\n";
			cout<<"\tId      Name            Age  Gender Points  \n";
			cout<<"\t################################################\n";
			i=5;
			while(1)
			{       i++;
				file.read((char*)&p,sizeof(p));
				if(file.eof())
					break;
				gotoxy(4,i);
				cout<<"\t";p.putdata();
				Boundary();
				getch();
			}
			file.close();
		getch();}
		else
			exit(1);
	     }
}
//------------------------------------------------------------------------------
void Player()                            //Function defined for player
{       clrscr();
	int id;
	char name[30];
	gotoxy(4,6);
	cout<<"\t#############################################################\n";
	cout<<"\t       Q U I Z      \n";
	cout<<"\t       G A M E      \n";
	cout<<"\t            - game banayega name \n";
	cout<<"\t#############################################################\n";
	cout<<"\t     W   E  L   C  O  M  E                      \n";
	cout<<"\t                                               \n";
	cout<<"\t              T O                             \n";
	cout<<"\t                                               \n";
	cout<<"\t  Q  U  I  Z      G  A  M  E                    \n";
	cout<<"\t#############################################################\n";
	Boundary();
	getch();
	clrscr();
	Boundary();
	gotoxy(4,6);
	p.getdata();
	strcpy(name,p.getname());
	id=p.getid();
	fstream file;
	file.open("Player.dat",ios::app|ios::binary);
	file.write((char*)&p,sizeof(p));
	file.close();
	cout<<"\n\n\n\tPress any key to start the game \n";
	Boundary();
	getch();
	clrscr();
	StartGame(name,id);
}
//------------------------------------------------------------------------------
void Boundary()
{
	for(int i=2; i<=78; i=i+2)
	{
		gotoxy(i,2);
		cout<<"";
	}
	for(i=2; i<=22; i++)
	{
		gotoxy(78,i);
		cout<<"";
	}
	for(i=78; i>=2; i=i-2)
	{
		gotoxy(i,22);
		cout<<"";
	}
	for(i=22; i>=2; i--)
	{
		gotoxy(2,i);
		cout<<"";
	}
}
//------------------------------------------------------------------------------
void Money_list()
{
	gotoxy(4,4);
	cout<<"\t#1.  Rs       1,000 \n";
	cout<<"\t#2.  Rs       2,000 \n";
	cout<<"\t#3.  Rs       3,000 \n";
	cout<<"\t#4.  Rs       5,000 \n";
	cout<<"\t#5.  Rs      10,000 \n";
	cout<<"\t#6.  Rs      20,000 \n";
	cout<<"\t#7.  Rs      40,000 \n";
	cout<<"\t#8.  Rs      80,000 \n";
	cout<<"\t#9.  Rs    1,60,000 \n";
	cout<<"\t#10. Rs    3,20,000 \n";
	cout<<"\t#11. Rs    6,40,000 \n";
	cout<<"\t#12. Rs   12,50,000 \n";
	cout<<"\t#13. Rs   25,00,000 \n";
	cout<<"\t#14. Rs   50,00,000 \n";
	cout<<"\t#15. Rs 1,00,00,000 \n";
	cout<<"\t#16. Rs 5,00,00,000 \n";
	Boundary();
	getch();
}
//------------------------------------------------------------------------------
void Add_Questions(int x)
{
	int num;
	Question Q;
	fstream file;
    switch(x)
    {
	case 1:   file.open("Q1000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 1 \n";
		  break;
	case 2:   file.open("Q2000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 2 \n";
		  break;
	case 3:   file.open("Q3000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 3 \n";
		  break;
	case 4:   file.open("Q5000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 4 \n";
		  break;
	case 5:   file.open("Q10000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 5 \n";
		  break;
	case 6:   file.open("Q20000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 6 \n";
		  break;
	case 7:   file.open("Q40000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 7 \n";
		  break;
	case 8:   file.open("Q80000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 8 \n";
		  break;
	case 9:   file.open("Q160000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 9 \n";
		  break;
	case 10:  file.open("Q320000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 10 \n";
		  break;
	case 11:  file.open("Q640000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 11 \n";
		  break;
	case 12:  file.open("Q1250000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 12 \n";
		  break;
	case 13:  file.open("Q2500000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 13 \n";
		  break;
	case 14:  file.open("Q5000000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 14 \n";
		  break;
	case 15:  file.open("Q10000000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 15 \n";
		  break;
	case 16:  file.open("Q50000000.dat",ios::app|ios::binary);
		  cout<<"Q. No. 16 \n";
		  break;
	default:  cout<<"Wrong Input!!\n"; getch(); exit(1);

     }
	cout<<"How many questions you want to enter ?\nAnswer : ";
	cin>>num;
	for(int i=0; i<num; i++)
	{       clrscr();
		Q.getques();
		file.write((char*)&Q,sizeof(Q));
	}
	file.close();
}
//------------------------------------------------------------------------------
void See_Questions(int x)
{
	Question Q;
	fstream file;
    switch(x)
    {
      case 1:  file.open("Q1000.dat",ios::in|ios::binary);
	       break;
      case 2:  file.open("Q2000.dat",ios::in|ios::binary);
	       break;
      case 3:  file.open("Q3000.dat",ios::in|ios::binary);
	       break;
      case 4:  file.open("Q5000.dat",ios::in|ios::binary);
	       break;
      case 5:  file.open("Q10000.dat",ios::in|ios::binary);
	       break;
      case 6:  file.open("Q20000.dat",ios::in|ios::binary);
	       break;
      case 7:  file.open("Q40000.dat",ios::in|ios::binary);
	       break;
      case 8:  file.open("Q80000.dat",ios::in|ios::binary);
	       break;
      case 9:  file.open("Q160000.dat",ios::in|ios::binary);
	       break;
      case 10: file.open("Q320000.dat",ios::in|ios::binary);
	       break;
      case 11: file.open("Q640000.dat",ios::in|ios::binary);
	       break;
      case 12: file.open("Q1250000.dat",ios::in|ios::binary);
	       break;
      case 13: file.open("Q2500000.dat",ios::in|ios::binary);
	       break;
      case 14: file.open("Q5000000.dat",ios::in|ios::binary);
	       break;
      case 15: file.open("Q10000000.dat",ios::in|ios::binary);
	       break;
      case 16: file.open("Q50000000.dat",ios::in|ios::binary);
	       break;
      default: cout<<"Question set not available\n"; getch(); exit(1);
    }
	for(int i=0; i>-1; i++)
	{
		file.read((char*)&Q,sizeof(Q));
		if(file.eof())
			break;
		Q.adminoutput();
		getch();
	}
	file.close();
}
//------------------------------------------------------------------------------
void StartGame(char name[],int id)
{
	Question Q[5];
	int qno=1;
	double points=0;
	char ans;
	int randomsize=0,max=2;
	fstream file;
	label:
	clrscr();
	gotoxy(5,1);
	cout<<"Id : "<<id<<'\n';
	gotoxy(55,1);
	cout<<"Name : "<<name<<"\n\n";
	getch();
	switch(qno)
	{  case 1:  	file.open("Q1000.dat",ios::in|ios::binary);
			break;
	   case 2:      file.open("Q2000.dat",ios::in|ios::binary);
			break;
	   case 3:      file.open("Q3000.dat",ios::in|ios::binary);
			break;
	   case 4:      file.open("Q5000.dat",ios::in|ios::binary);
			break;
	   case 5:      file.open("Q10000.dat",ios::in|ios::binary);
			break;
	   case 6:      file.open("Q20000.dat",ios::in|ios::binary);
			break;
	   case 7:      file.open("Q40000.dat",ios::in|ios::binary);
			break;
	   case 8:      file.open("Q80000.dat",ios::in|ios::binary);
			break;
	   case 9:      file.open("Q160000.dat",ios::in|ios::binary);
			break;
	   case 10:	file.open("Q320000.dat",ios::in|ios::binary);
			break;
	   case 11:     file.open("Q640000.dat",ios::in|ios::binary);
			break;
	   case 12:     file.open("Q1250000.dat",ios::in|ios::binary);
			break;
	   case 13:     file.open("Q2500000.dat",ios::in|ios::binary);
			break;
	   case 14:     file.open("Q5000000.dat",ios::in|ios::binary);
			break;
	   case 15:     file.open("Q10000000.dat",ios::in|ios::binary);
			break;
	   case 16:     file.open("Q50000000.dat",ios::in|ios::binary);
			break;
	   default:  	cout<<"Closing the application";
			getch();
			exit(1);
	}
	for(int i=0; i<5; i++)
	{
		file.read((char*)&Q[i],sizeof(Q[i]));
		if(file.eof())
		{      	break;
		}
	}
	file.close();
	randomize();
	randomsize=random(max);
	gotoxy(6,4);
	Q[randomsize].output();
	Boundary();
	gotoxy(9,15);
	cout<<"Which option is correct : ";
	 cin>>ans;
	 cout<<"Correct ans is "<<Q[randomsize].getanswer()<<'\n';
	 getch();
	if(ans==Q[randomsize].getanswer())
	{      	clrscr();
		cout<<"\n\n\n\n\n\n\t\t\tC O N G R A T U L A T I O Ns!!! \n";
		switch(qno)
		{   case 1: cout<<"\n\n\t\t\tY o u  W o n  \"1000 points\" \n";
			    points=1000;      Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 2: cout<<"\n\n\t\t\tY o u  W o n  \"2000 points\" \n";
			    points=2000;      Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 3: cout<<"\n\n\t\t\tY o u  W o n  \"3000 points\" \n";
			    points=3000;      Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 4: cout<<"\n\n\t\t\tY o u  W o n  \"5000 points\" \n";
			    points=5000;      Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 5: cout<<"\n\n\t\t\tY o u  W o n  \"10000 points\" \n";
			    points=10000;     Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 6: cout<<"\n\n\t\t\tY o u  W o n  \"20000 points\" \n";
			    points=20000;     Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 7: cout<<"\n\n\t\t\tY o u  W o n  \"40000 points\" \n";
			    points=40000;     Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 8: cout<<"\n\n\t\t\tY o u  W o n  \"80000 points\" \n";
			    points=80000;     Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 9: cout<<"\n\n\t\t\tY o u  W o n  \"160000 points\" \n";
			    points=160000;    Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 10:cout<<"\n\n\t\t\tY o u  W o n  \"320000 points\" \n";
			    points=320000;    Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 11:cout<<"\n\n\t\t\tY o u  W o n  \"640000 points\" \n";
			    points=640000;    Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 12:cout<<"\n\n\t\t\tY o u  W o n  \"1250000 points\" \n";
			    points=1250000;   Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 13:cout<<"\n\n\t\t\tY o u  W o n  \"2500000 points\" \n";
			    points=2500000;   Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 14:cout<<"\n\n\t\t\tY o u  W o n  \"5000000 points\" \n";
			    points=5000000;   Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 15:cout<<"\n\n\t\t\tY o u  W o n  \"100000000 points\" \n";
			    points=10000000;  Boundary();
			    getch();
			    qno++;
			    goto label;
		    case 16:cout<<"\n\n\t\t\tY o u  W o n  \"500000000 points\" \n";
			    points=50000000;  Boundary();
			    cout<<"Total points = "<<points<<'\n';
			    getch();
			    qno++;
			    break;
		    default: break;
		}
	}
	else
	{       clrscr();
		cout<<"\n\n\n\n\n\n\t\t\t\t B a d   L u c k   !!!  \n";
		cout<<"\n\n\t\t\t Total points gained = "<<points<<'\n';  Boundary();
		getch();
	}
	fstream temp;
	file.open("Player.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	for( i=0; i>-1; i++)
	{
		file.read((char*)&p,sizeof(p));
		if(file.eof())
			break;
		if(id==p.getid())
		{	p.putpoints(points);
			temp.write((char*)&p,sizeof(p));
		}
		else
			temp.write((char*)&p,sizeof(p));
	}
	file.close();
	temp.close();
	remove("Player.dat");
	rename("temp.dat","Player.dat");

}
//============================================================================
// ___________             _______       _______   __            _   _
//|___________| ||     || | ______|     | ______| |  \          | | |  \
//	||      ||     || ||            ||        | |\ \        | | | |\ \
//	||      ||_____|| ||____        ||____    | |  \ \      | | | |  \ \
//	||      | _____ | | ____|       | ____|   | |    \ \    | | | |   | |
//	||      ||     || ||            ||        | |      \ \  | | | |  / /
//	||      ||     || ||______      ||______  | |        \ \| | | |/ /
//	||      ||     || |_______|     |_______| |_|          \__| |_ /
//
//=============================================================================