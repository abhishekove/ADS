//============================================================================
// Name        : File_Handling.cpp
// Author      : Ashley.J.George
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Student
{
    char name[20];
    int rno;
    char dob[10];

public:
    void accept();
    void display();
    inline const char* getName(){return name;}
    inline int getRno(){return rno;}
};


void Student::accept()
{
    cout<<"\nEnter Details Of Student: \n";
    cout<<"Name: ";
    cin>>name;
    cout<<"Roll Number: ";
    cin>>rno;
    cout<<"Date Of Birth: ";
    cin>>dob;
}


void Student::display()
{

    cout<<"Name: "<<name<<endl;
    cout<<"Roll Number: "<<rno<<endl;
    cout<<"Date Of Birth: "<<dob<<endl<<endl;
}


void Create_File()
{
    Student T;
    int n;

    cout<<"\nEnter Number Of Entries: ";
    cin>>n;

    ofstream fout;
    fout.open("Data.txt",ios::out);

    for(int i=0;i<n;i++)
    {
        T.accept();
        fout.write( (char*)&T , sizeof(T));
    }

    fout.close();
}


void Display_File()
{
    ifstream fin;
    Student T1;

    fin.open("Data.txt",ios::in);

    while(fin)
    {
        fin.read((char*)&T1, sizeof(T1));

        if(fin.eof()!=0)
            break;

        T1.display();
        cout<<endl;
    }

    fin.close();
}


void Add_Record()
{
    ofstream fout;
    Student T1;

    fout.open("Data.txt", ios::app);
    T1.accept();
    fout.write((char*)&T1, sizeof(T1));
    fout.close();
}


void Search_Record()
{
    void Search_name();
    void Search_rno();

    int para;

    cout<<"\n1. Search By Name"<<endl;
    cout<<"2. Search By Roll No"<<endl;
    cout<<"Enter Parameter By Which You Want To Search : ";
    cin>>para;

    switch(para)
    {
        case 1 :    Search_name();
                    break;
        case 2 :    Search_rno();
                    break;
    }

}


void Search_name()
{
    char name[20];
    int flag;
    ifstream fin;
    Student T1;
    flag=0;

    cout<<"Enter Name To Be Searched: ";
    cin>>name;

    fin.open("Data.txt", ios::in);

    while(fin)
    {
        fin.read((char*) &T1, sizeof(T1));

        if(fin.eof()!=0)
            break;

        if(!strcmp(T1.getName(),name))
        {
            cout<<"\nStudent's Record Is Found!!!"<<endl;
            T1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0)
        cout<<"~~~ Record Not Found!!! ~~~"<<endl;

}


void Search_rno()
{
    int rno;
    int flag;
    ifstream fin;
    Student T1;
    flag=0;

    cout<<"Enter Roll Number To Be Searched: ";
    cin>>rno;

    fin.open("Data.txt", ios::in);

    while(fin)
    {
        fin.read((char*) &T1, sizeof(T1));

        if(fin.eof()!=0)
            break;


        if(T1.getRno() == rno)
        {
            cout<<"\nStudent's Record Is Found!!!"<<endl;
            T1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0)
        cout<<"~~~ Record not found!!! ~~~"<<endl;

}


void Modify_Record()
{
    void Modify_name();
    void Modify_rno();

    int para;

    cout<<"\n1. Modify By Name"<<endl;
    cout<<"2. Modify By Roll no"<<endl;
    cout<<"Enter The Parameter By Which You Want To Modify The Record: ";
    cin>>para;

    switch(para)
    {
        case 1 :    Modify_name();
                    break;
        case 2 :    Modify_rno();
                    break;
    }

}


void Modify_name()
{
    char name[20];
    int flag,pos;
    fstream file;
    Student T1;
    flag=0;

    cout<<"Enter name to be modified : ";
    cin>>name;

    file.open("Data.txt", ios::in|ios::out);

    while(file)
    {
        file.read((char*) &T1, sizeof(T1));

        if(file.eof()!=0)
            break;

        if(!strcmp(T1.getName(),name))
        {
            cout<<"\nStudent record found."<<endl;
            T1.accept();

            pos=-1*sizeof(T1);
            file.seekp(pos, ios::cur);
            file.write((char*)&T1, sizeof(T1));
            flag=1;
            break;
        }
    }
    file.close();

    if(flag==0)
        cout<<"Record not found."<<endl;

}


void Modify_rno()
{
    int rno;
    int flag,pos;
    fstream file;
    Student T1;
    flag=0;

    cout<<"Enter phone number to be modified : ";
    cin>>rno;

    file.open("Data.txt", ios::in|ios::out);

    while(file)
    {
        file.read((char*) &T1, sizeof(T1));

        if(file.eof()!=0)
            break;

        if(T1.getRno() == rno)
        {
            cout<<"\nStudent record found."<<endl;
            T1.accept();

            pos=-1*sizeof(T1);
            file.seekp(pos, ios::cur);
            file.write((char*)&T1, sizeof(T1));
            flag=1;
            break;
        }
    }
    file.close();

    if(flag==0)
        cout<<"~~~ Record not found!!! ~~~"<<endl;

}



int main()
{

    int ch;

    do{
        cout<<"\n======== ~~~ Student Database ~~~ ========="<<endl;
        cout<<"1. Create Database."<<endl;
        cout<<"2. Display Details."<<endl;
        cout<<"3. Add New Record."<<endl;
        cout<<"4. Search For A Record."<<endl;
        cout<<"5. Modify A Record."<<endl;
        cout<<"6. Exit."<<endl;

        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1 :    Create_File();
                        break;

            case 2 :    Display_File();
                        break;

            case 3 :    Add_Record();
                        break;

            case 4 :    Search_Record();
                        break;

            case 5 :    Modify_Record();
                        break;

            default:    cout<<"Invalid Input, Please Enter A Valid Option!!!"<<endl;
                        break;
        }

    }while(ch!=6);

    return 0;
}

