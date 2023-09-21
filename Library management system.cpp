#include<iostream>
#include<conio.h>
#include<limits>
#include<stdio.h>
#include<fstream>
#include<string>
#include <ctype.h>
using namespace std;
//  class Start from here //
class bookshop
{
	private:           //  attribute are declare for private just for use in class   //
		int no_copy;
		char a_name[50];
		char b_name[20];
		int  b_id;
	public:
		//members functions declare inside the class to use in whole programv  //
		void menu();
		void control_panel(); 
		void add_book();
		void show_book();
		void check_book();
		void update_book();
		void del_book();
		
};//class End Here
	void bookshop :: menu()  //  Function defintion to show menu  //
{
		system("cls");
	    cout << "\n\n\n";
	    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
	    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
	    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
	    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
	    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
	    cout<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
	    cout<<"\t\t\t\tBOOK MANEGEMENT SYSTEM"<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
	    cout<<"press any key to go to Control Panel...";
	    cin.ignore();
	    
	}
	void bookshop::control_panel()//function definition to show Control Panel 
	{
		system("cls");
		cout<<"\t\t\t\t============================================="<<endl;
	    cout<<"\t\t\t\tBOOK MANEGEMENT SYSTEM"<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
		cout<<"\n\n\t\t\t\tControl Panel";
		cout<<"\n\n \t\t\t1. Add New Book";
		cout<<"\n \t\t\t2. Display Books";
		cout<<"\n \t\t\t3. Check Specific Book";
		cout<<"\n \t\t\t4. Update Book";
		cout<<"\n \t\t\t5. Delete Book";
		cout<<"\n \t\t\t6. Exit";
	
}
	void bookshop::add_book()//function definition to Add books 
	{
		bool flag=false;
		system("cls");
		cout<<"\t\t\t\t============================================="<<endl;
	    cout<<"\t\t\t\tTHIS IS BOOK SHOP MANEGEMENT SYSTEM"<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
		cout<<"\n\n\t\t\t\t ADD New Book";
		start3:		 
		cout << "\n\n Book ID :" ;
  while (true)
  {
    cin >> b_id;
    if (!cin)
    {
      cout << "Sorry!Book ID contain only Integers.......\nPlease Re-Enter Book ID: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    else break;
  }
  		cin.ignore();
  		start:
    	cout<<"\n\n Book Name : ";
		cin.ignore();
		cin.getline(b_name,50); 
    for(int i=0; b_name[i]!='\0';++i) 
    { 
        if(! (b_name[i]>='A'&& b_name[i]<='Z'|| b_name[i]>='a'&& b_name[i]<='z')) 
        { 
            flag=true; 
            cout<<"Sorry! Book name should contain Aplahbets  "<<endl; 
       	 	goto start;
            break;   
        } 
    } 
		start2:
		cout<<"\n\n Author Name : ";
		cin.getline(a_name,50);
	for(int i=0; a_name[i]!='\0';++i) 
    { 
        if(! (a_name[i]>='A'&& a_name[i]<='Z'|| a_name[i]>='a'&& a_name[i]<='z')) 
        { 
            flag=true; 
            cout<<"Sorry! Author name should contain Aplahbets  "<<endl; 
       	 	goto start2;
            break;   
        } 
    } 
		cout<<"\n\n No. of Copies : ";
	while (true)
  {
    cin >> no_copy;
    if (!cin)
    {
      cout << "Sorry!No of Copy Conatin only Integers.......\nPlease Re-Enter No of copys: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    else break;
  }
		ofstream file;
		file.open("book.txt",ios::out|ios::app);
		file<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
		file.close();
	}

	void bookshop::show_book()//function definition to show Show book 
	{
		system("cls");
		cout<<"\t\t\t\t============================================="<<endl;
	    cout<<"\t\t\t\tTHIS IS BOOK SHOP MANEGEMENT SYSTEM"<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
		int no_copy;
		string b_name,b_id,a_name;
		cout<<"\n\n\t\t\t\tShow All Books";
		ifstream file;
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID        Book      Author        No. of Copies\n\n";
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				cout<<"   "<<b_id<<"\t\t"<<b_name<<"\t"<<a_name<<"\t\t"<<no_copy<<"\n\n";
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
		}
	}
	
	void bookshop::check_book()//function definition to show check Specific Book
	{
		system("cls");
		cout<<"\t\t\t\t============================================="<<endl;
	    cout<<"\t\t\t\tTHIS IS BOOK SHOP MANEGEMENT SYSTEM"<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
		fstream file;
		int no_copy,count=0;
		int b_id,b_idd;
		cout<<"\n\n\t\t\t\tCheck Specific Book";
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_idd;
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tCheck Specific Book";
					cout<<"\n\n Book ID : "<<b_id;
					cout<<"\n\nName : "<<b_name;
					cout<<"\n\n Author : "<<a_name;
					cout<<"\n\nNo. of Copies : "<<no_copy;
					count++;
					break;	
				}
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
	}
	
	void bookshop::update_book()//function definition to show update Book
	{
		system("cls");
		cout<<"\t\t\t\t============================================="<<endl;
	    cout<<"\t\t\t\tTHIS IS BOOK SHOP MANEGEMENT SYSTEM"<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
		int no_copy,no_co,count=0;
		string b_id,b_idd;
		char b_na[50];
		char a_na[50];
		cout<<"\n\n\t\t\t\tUpdate Book Record";
		fstream file,file1;
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tUpdate Book Record";
					cout<<"\n\n New Book Name : ";
					cin.ignore();
					cin.getline(b_na,50);
					cout<<"\n\nAuthor Name : ";
					cin.getline(a_na,50);
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}
	
	void bookshop::del_book()//function definition to show Delete Book 
	{
		system("cls");
		cout<<"\t\t\t\t============================================="<<endl;
	    cout<<"\t\t\t\tTHIS IS BOOK SHOP MANEGEMENT SYSTEM"<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
		int no_copy,count=0;
		string b_id,b_idd,b_name,a_name;
		cout<<"\n\n\t\t\t\tDelete Book Record";
		fstream file,file1;
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}
int main()
{
	//program excution start from here 
	int choice;
	char x;
	while(1){
	bookshop *b,c ;//here we have declare pointer object of bookshop class
	b=&c;// here we have pass  object address  to another variable 
	b->menu();//calling of menu function 
	b->control_panel();//calling of control pannel
	cout<<"\n\nPlease Enter  Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			do
			{
			b->add_book(); //calling of add book
			cout<<"\n\n Do You Want to Add another Book (y,n) : ";
			cin>>x;
		    }while(x == 'y');
			break;
		case 2:
			b->show_book();//calling of show book
			break;
		case 3:
			b->check_book();//calling of check book
			break;
		case 4:
			b->update_book();//calling of update book
			break;
		case 5:
			b->del_book();//calling of delete book
			break;
		case 6:
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
	}
	cout<<"\n\t\t\tEnter any key to go to Menu\n";
	getch();
}
return 0;
}
