//============================================================================
// Name        : Symbol_Table.cpp
// Author      : Ashley.J.George
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#define MAX 10
using namespace std;

typedef struct node
{
    int line_no[MAX],lines_used;
	string ID_name,type,ini_val;
	node *next;
}Node;

class Symbol_Table
{
    Node *hn;

public:
        Symbol_Table(){ hn = NULL; }
        void Insert();
        void Display();
        void Search(string);
        void Update(string);
        void Delete(string);
};


void Symbol_Table :: Insert()
{
    Node *nn,*cn;

    nn = new node;
    cout<<"Enter The Identifier Name: ";
	cin>>nn->ID_name;
	cout<<"Enter The Type Identifier: ";
	cin>>nn->type;
	cout<<"Enter The Initial Value Of The Identifier: ";
	cin>>nn->ini_val;
	cout<<"Enter The Number Of Lines Used By The Identifier: ";
	cin>>nn->lines_used;
	cout<<"Enter The Line Numbers Where Identifier Has Appeared"<<endl;
	for(int i=0;i<nn->lines_used;i++)
	{
		cout<<"Enter The Line Number: ";
		cin>>nn->line_no[i];
	}

	cout<<endl;

	nn->next=NULL;

	if(hn==NULL)
        hn=nn;
    else
    {
        for(cn=hn;cn->next!=NULL;cn=cn->next);
        cn->next=nn;
    }
}


void Symbol_Table :: Display()
{
    Node *cn;

    for(cn=hn;cn!=NULL;cn=cn->next)
    {
        cout<<cn->ID_name<<"\t\t"<<cn->type<<"\t\t"<<cn->ini_val<<"\t\t\t\t"<<cn->lines_used<<"\t\t\t";
        for(int i=0;i<cn->lines_used;i++)
		cout<<cn->line_no[i]<<" ";
		cout<<endl;
    }

    cout<<endl;

}


void Symbol_Table :: Search(string key)
{
    int flag=0;
    Node *cn;
    for(cn=hn;cn!=NULL;cn=cn->next)
    {
        if(key==cn->ID_name)
        {
            flag=1;
            break;
        }

    }

    if(flag==1)
    {
        cout<<"The Identifier Is Present In The Symbol Table!!!"<<endl;
        cout<<"Identifier Details:"<<endl;
        cout<<"\nName Of The Identifier: "<<cn->ID_name<<endl;
        cout<<"\nType Of The Identifier: "<<cn->type<<endl;
        cout<<"\nInitial Value Of The Identifier: "<<cn->ini_val<<endl;
        cout<<"\nNumber Of Lines The Identifier Has Appeared: "<<cn->lines_used<<endl;
        cout<<"\nLines Where The Identifier Has Appeared: ";
        for(int i=0;i<cn->lines_used;i++)
		cout<<cn->line_no[i]<<" ";

        cout<<endl;
    }
    else
        cout<<"The Identifier Is Not Present In The Symbol Table!!!"<<endl;
}


void Symbol_Table :: Update(string key)
{
    int flag=0;
    Node *cn;
    for(cn=hn;cn!=NULL;cn=cn->next)
    {
        if(key==cn->ID_name)
        {
            flag=1;
            break;
        }

    }

    if(flag==1)
    {
        cout<<"Enter The Identifier Name: ";
        cin>>cn->ID_name;
        cout<<"Enter The Type Identifier: ";
        cin>>cn->type;
        cout<<"Enter The Initial Value Of The Identifier: ";
        cin>>cn->ini_val;
        cout<<"Enter The Number Of Lines Used By The Identifier: ";
        cin>>cn->lines_used;
        cout<<"Enter The Line Numbers Where Identifier Has Appeared"<<endl;
        for(int i=0;i<cn->lines_used;i++)
        {
            cout<<"Enter The Line Number: ";
            cin>>cn->line_no[i];
        }

        cout<<endl;
    }
    else
        cout<<"The Identifier Is Not Present In The Symbol Table!!!"<<endl;
}



void Symbol_Table :: Delete(string key)
{
    int flag=0;
    Node *cn,*t;
    for(cn=hn;cn!=NULL;cn=cn->next)
    {
        if(key==cn->next->ID_name)
        {
            flag=1;
            break;
        }

        if(key==hn->ID_name)
        {
            hn=hn->next;
            break;
        }


    }


    if(flag==1)
    {
        t=cn->next;
        cn->next=t->next;
        delete t;
    }
    if(cn==NULL)
        cout<<"The Identifier Is Not Present In The Symbol Table!!!"<<endl;
}



int main()
{
    Symbol_Table S;
    char choice;
	string sea;
	do
	{

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
                    S.Insert();
                    break;

            case '2':
                    cout<<"Name\t\tType\t\tInitial Value\t\tNumber Of Lines Used\t\tLine Numbers\n";
                    S.Display();
                    break;

            case '3':
                    cout<<"Enter The Name Of The Identifier You Want To Search: ";
                    cin>>sea;
                    S.Search(sea);
                    break;

            case '4':
                    cout<<"Enter The Name Of The Identifier You Want To Update: ";
                    cin>>sea;
                    S.Update(sea);
                    break;

            case '5':
                    cout<<"Enter The Name Of The Identifier You Want To Delete: ";
                    cin>>sea;
                    S.Delete(sea);
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
