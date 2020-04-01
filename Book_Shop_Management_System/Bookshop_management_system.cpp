#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

void Mine()
{
    cout<<endl<<"\t\t\t\t************************************* "<<endl;
    cout<<endl<<" \t\t\t\t       :-TARUN BOOK STORE:-         "<<endl;
    cout<<endl<<" \t\t\t\t     NAME :- TARUN SINGH MAHAR      "<<endl;
    cout<<endl<<" \t\t\t\t  	 REG.NO.:-1160         "<<endl;
    cout<<endl<<" \t\t\t\t       	 ROLL.NO:-B42                 "<<endl;
    cout<<endl<<" \t\t\t\t	  SECTION:-K1612                 "<<endl;
    cout<<endl<<" \t\t\t\t************************************** "<<endl;
}


class bookshop
{
	private:
		char bname[30];
		char baname[30];
		int bid;
		int tnob;
		float bprice;
	public:
		void all_input()
		{
			fflush(stdin);
			cout<<"Enter Book name:";
			gets(bname);
			fflush(stdin);
			cout<<"Enter Book Author name:";
			gets(baname);
			fflush(stdin);
			cout<<"Enter Book ID:";
			cin>>bid;
			fflush(stdin);
			cout<<"Enter Book price:";
			cin>>bprice;
			fflush(stdin);
			cout<<"Enter total number of book:";
			cin>>tnob;
		}
		void displayall()
		{
			cout<<"Book name="<<bname<<endl;
	    	cout<<"Book Author name="<<baname<<endl;
			cout<<"Book ID="<<bid<<endl;
			cout<<"Book price="<<bprice<<endl;
			cout<<"Total no. of book="<<tnob<<endl;
			cout<<endl<<endl;
		}
		void insert()
		{
			ofstream f;
    		f.open("file.txt",ios::app);
			fflush(stdin);
			cout<<"Enter Book name:";
			gets(bname);
			fflush(stdin);
			cout<<"Enter Book Author name:";
			gets(baname);
			fflush(stdin);
			cout<<"Enter Book ID:";
			cin>>bid;
			fflush(stdin);
			cout<<"Enter Book price:";
			cin>>bprice;
			fflush(stdin);
			cout<<"Enter total number of book:";
			cin>>tnob;
			f.write((char*)this,sizeof(*this));
			f.close();
			cout<<" Data Stored Sucessfully";
		}
		void display()
		{
			ifstream f;
			f.open("file.txt",ios::in);
			if(!f)
			{
				cout<<endl<<"\t\t\tNo file is present."<<endl;
			}
			else
			{
				f.read((char*)this,sizeof(*this));
				while(!f.eof())
				{
					cout<<"Book name="<<bname<<endl;
					cout<<"Book Author name="<<baname<<endl;
					cout<<"Book ID="<<bid<<endl;
					cout<<"Book price="<<bprice<<endl;
					cout<<"Total no. of book="<<tnob<<endl;
					cout<<endl<<endl;
					f.read((char*)this,sizeof(*this));
				}
			}
    		f.close();
		}
		void searchdata(char *n)
        {
        	int t=0;
	        ifstream f;
	        f.open("file.txt",ios::in|ios::binary);
        	if(!f)
        	{
	        	cout<<endl<<"\t\t\tNo file is present."<<endl;
        	}
	        else
        	{
        		f.seekg(sizeof(*this),ios::beg);
	        	f.read((char*)this,sizeof(*this));
            	while(!f.eof())
            	{
            		if(!strcmp(n,bname))
                	{
        	        	displayall();
        		        t++;
                	}
                	f.read((char*)this,sizeof(*this));
        		}
        		if(t==0)
        		{
	        		cout<<endl<<"\t\t\tData not found."<<endl;
        		}
	        	f.close();
	        }

}
    	void update(char *d)
        {
        	fstream f;
        	f.open("file.txt",ios::in|ios::out|ios::ate|ios::binary);
        	f.seekg(0);
        	f.read((char*)this,sizeof(*this));
	        while(!f.eof())
        	{
	        	if(!strcmp(d,bname))
	        	{
	        		cout<<"\n\t\t\tId Found\n";
	        		all_input();
	        		int b=f.tellg();
        			f.seekg(b-sizeof(*this));
        			f.write((char*)this,sizeof(*this));
        		}
        		f.read((char*)this,sizeof(*this));
        	}
        	f.close();
        }
        void deletedata(char *n)
        {
        	ifstream fin;
        	ofstream fout;
        	fin.open("file.txt",ios::in|ios::binary);
        	if(!fin)
        	{
        		cout<<endl<<"File not found."<<endl;
        	}
        	else
        	{
        		fout.open("temporary.txt",ios::out|ios::binary);
            	fin.read((char*)this,sizeof(*this));
        		while(!fin.eof())
        		{
        			if(strcmp(n,bname))
	    		    fout.write((char*)this,sizeof(*this));
	        		fin.read((char*)this,sizeof(*this));
        		}
        		fin.close();
        		fout.close();
        		remove("file.txt");
        		rename("temporary.txt","file.txt");
        		cout<<endl<<"Data deleted Sucessfully."<<endl;
        	}
        }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class password
{
	public:
		void show()
		{
		string pass;
		pass="";
		for(int i=1;i<=3;i++)
		{
			if(i==3)
			cout<<endl<<"\n\t\t YOU HAVE "<<4-i<<" CHANCE LEFT\n\n\t\t ENTER THE PASSWORD : ";
			else
			cout<<endl<<"\n\t\t YOU HAVE "<<4-i<<" CHANCES LEFT\n\n\t\t ENTER THE PASSWORD : ";
			char ch=getch();
			while(ch!=13)
			{
				if(ch!=8)
				{
				cout<<"*";
				pass=pass+ch;
				}
				ch=getch();
			}
			if(pass=="tarun")
			{
			cout<<endl<<"\t>>>>>>>>>>> CORRECT PASSWORD  <<<<<<<<<<<<<"<<endl<<endl;
			cout<<endl<<"\t\t\tPress any key to continue...";
			getch();
			break;
			}
			else
			{
				if(i==3)
				{
				cout<<"\n\n\t>>>>>>>>>>> Wrong Password <<<<<<<<<<<<<"<<endl;
				cout<<"\n\t LOGIN AFTER 5 MIN."<<endl;
				}
				else
				{
				cout<<endl<<"\t>>>>>>>>>>> Wrong Password Please Try Again <<<<<<<<<<<<<"<<endl<<endl;
				}
				pass="";
			}
		}
	}
};
void menu()
{
 	cout<<"\nCHOOSE YOUR OPTION\n1. INSERT\n2. DISPLAY\n3. SEARCH\n4. DELETE\n5. UPDATE\n6. EXIT\n";
}

main()
{
	Mine();
	cout<<"ENTER PASSWORD ='tarun' ";
	password p1;
	p1.show();
	int option;
	while(1)
	{

    	system("cls");
    	menu();
		cout<<"ENTER THE OPTION NUMBER :";
		cin>>option;
		bookshop b1;
		if(option==1)										//insert
		{
			system("cls");
    		b1.insert();
    		cout<<"\n\nPress any key to go to Main Menu:";
    		getch();
    		system("cls");
		}
		else if(option==2)        //display
		{
            system("cls");
	    	b1.display();
	    	cout<<"\n\nPress any key to go to Main Menu:";
    		getch();


		}
		else if(option==3)         //search
		{
			system("cls");
			char name[30];
			cout<<"Enter the name of book you want to search : ";
			fflush(stdin);
			gets(name);
    		b1.searchdata(name);
    		getch();
    		system("cls");
		}
		else if(option==5)              	  //update
		{
			system("cls");
			char c[30];
			cout<<"Enter Book name to update:";
		    fflush(stdin);
		    gets(c);
		    b1.update(c);
		    cout<<"\n\nPress any key to go to Main Menu:";
    		getch();
		    system("cls");
		}
	    else if(option==4)              //delete
	    {
	    	system("cls");
	    	char c[30];
			cout<<"Enter Book name to delete:";
		    fflush(stdin);
		    gets(c);
		    b1.deletedata(c);
		    cout<<"\n\nPress any key to go to Main Menu:";
    		getch();
		    system("cls");
		}
		else if(option==6)					//exit
		{
			system("cls");
			cout<<" \t\t\t\t\t\tThanks for visiting.Press any key to exit ";
			getch();
			exit(0);
		}
	}
}
