//============================================================================
// Name        : Symbol_Table.cpp
// Author      : Ashley.J.George
// Version     : ~ Pro Wala!!! ~
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#define MAX 30
using namespace std;

class Symbol_Table
{
	int line_no[10],line_used;
	string ID_name,type,ini_val;

public:
		void Get();
		void Display();
		void Search_Display();
		string Get_Name();
};


void Symbol_Table :: Get()
{
	cout<<"Enter The Identifier Name: ";
	cin>>ID_name;
	cout<<"Enter The Type Identifier: ";
	cin>>type;
	cout<<"Enter The Initial Value Of The Identifier: ";
	cin>>ini_val;
	cout<<"Enter The Number Of Lines Used By The Identifier: ";
	cin>>line_used;
	cout<<"Enter The Line Numbers Where Identifier Has Appeared"<<endl;
	for(int i=0;i<line_used;i++)
	{
		cout<<"Enter The Line Number: ";
		cin>>line_no[i];
	}

	cout<<endl;
}



void Symbol_Table :: Display()
{
	cout<<ID_name<<"\t\t"<<type<<"\t\t"<<ini_val<<"\t\t\t\t"<<line_used<<"\t\t\t";
	for(int i=0;i<line_used;i++)
		cout<<line_no[i]<<" ";

	cout<<endl;
}


void Symbol_Table :: Search_Display()
{
    cout<<"\nName Of The Identifier: "<<ID_name<<endl;
    cout<<"\nType Of The Identifier: "<<type<<endl;
    cout<<"\nInitial Value Of The Identifier: "<<ini_val<<endl;
    cout<<"\nNumber Of Lines The Identifier Has Appeared: "<<line_used<<endl;
    cout<<"\nLines Where The Identifier Has Appeared: ";
    for(int i=0;i<line_used;i++)
		cout<<line_no[i]<<" ";

	cout<<endl;
}


inline string Symbol_Table :: Get_Name()
{
    return ID_name;
}

int main()
{
	Symbol_Table a[30];
	int count=-1,j;
	char choice;
	string sea;
	do
	{
		int flag=0;
		cout<<"\n\n======================== ~ Symbol Table ~ =============================\n\n";
		cout<<"1. Enter An Element Into The Symbol Table.\n";
		cout<<"2. Display The Symbol Table.\n";
		cout<<"3. Search An Element In The Symbol Table.\n";
		cout<<"4. Update An Element In The Symbol Table.\n";
		cout<<"5. Delete An Element From The Symbol Table.\n";
		cout<<"6. Exit.\n";
		cout<<"Enter Your Choice: ";
		cin>>choice;
        cout<<endl;
		switch(choice)
		{
            case '1':
                    if(count<MAX)
                    {
                        count++;
                        a[count].Get();
                    }
                    else
                        cout<<"The Symbol Table Is Full"<<endl;
                    break;

            case '2':

                    cout<<"Name\t\tType\t\tInitial Value\t\tNumber Of Lines Used\t\tLine Numbers\n";
                    for(int i=0;i<=count;i++)
                        a[i].Display();
                    break;

            case '3':
                    cout<<"Enter The Name Of The Identifier You Want To Search: ";
                    cin>>sea;

                    for(int i=0;i<=count;i++)
                    {
                        if(sea == a[i].Get_Name())
                        {
                            cout<<"The Identifier Is Present In The Symbol Table!!!"<<endl;
                            cout<<"Identifier Details:"<<endl;
                            a[i].Search_Display();
                            flag=1;
                            break;
                        }
                    }

                    if(flag!=1)
                        cout<<"The Identifier Is Not Present In The Symbol Table!!!"<<endl;

                    break;

            case '4':
                    cout<<"Enter The Name Of The Identifier You Want To Update: ";
                    cin>>sea;

                    for(int i=0;i<=count;i++)
                    {
                        if(sea == a[i].Get_Name())
                        {
                            flag=1;
                            a[i].Get();
                            break;
                        }
                    }

                    if(flag!=1)
                        cout<<"The Identifier Is Not Present In The Symbol Table!!!"<<endl;

                    break;

            case '5':
                    cout<<"Enter The Name Of The Identifier You Want To Delete: ";
                    cin>>sea;

                    for(int i=0;i<=count;i++)
                    if(sea == a[i].Get_Name())
                    {
                        cout<<"The Identifier \""<<sea<< "\" Has Been Deleted From The Symbol Table!!!"<<endl;
                        j=i;
                        flag=1;
                        break;
                    }

                    if(flag==1)
                    {
                        for(int i=j;i<count;i++)
                            a[i]=a[i+1];

                        count--;
                    }
                    else
                        cout<<"The Identifier Is Not Present In The Symbol Table!!!"<<endl;

                    break;

            case '6':
                    cout<<"You Have Exited Successfully!!!"<<endl;
                    break;

            default: cout<<"Invalid Input, Enter The Correct Input"<<endl;
		}

		cout<<"========================================================================\n\n";

	}while(choice!='6');


	return 0;
}
