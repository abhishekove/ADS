#include <iostream>
#include<cstring>
#define size 10
using namespace std;
struct Telephone
{
    long long int phone;
    string name;
};


class Hashtable
{
     struct Telephone Tel[20];
     int flag[20];
public:
    Hashtable()
{
        for(int i=0;i<size;i++)
        {
            flag[i]=0;
        }
}
    long long int Hashfunction(long long int key);
    void Insert(long long int key,string name);
    void search_by_name(string name);
    void search(long long int);
    void Delete(long long int);
    void Display();
};
long long int Hashtable::Hashfunction(long long int key)
{
    return(key%size);
}
void Hashtable::Insert(long long int key,string name)
{
    long long int p;
    p=Hashfunction(key);
    for(int i=0;i<size;i++)
    {
        if(flag[p]==0)
        {
            Tel[p].phone=key;
            Tel[p].name=name;
            flag[p]=1;
            return;
        }
        else
        {
            p=(p+1)%size;
        }

    }
    cout<<"\n Hashtable is full!!!!!!!";
}
void Hashtable::search(long long int key)
{
    long long int p;
    p=Hashfunction(key);
    for(int i=0;i<size;i++)
    {
        if(Tel[p].phone==key && flag[p]==1)
        {
            cout<<"\n key found at "<<p<<"location";
            return;
        }
        else
        {
            p=(p+1)%size;
        }

    }
    cout<<"\n Key Not Found!!";
}
void Hashtable::search_by_name(string name)
{

    int flag1=0;
    for(int i=0;i<size;i++)
    {
        if(Tel[i].name==name)
        {
            flag1=1;
            cout<<"\n Customer found!!!"<<"at"<<i<<"location whose phone number is:"<<Tel[i].phone<<endl;
            break;

        }
    }
    if(flag1==0)
        cout<<"\n Not Found!!!!";
}
void Hashtable::Delete(long long int key)
{
    long long int p;
    p=Hashfunction(key);
    for(int i=0;i<size;i++)
    {
        if(Tel[p].phone==key && flag[p]==1)
        {
            flag[p]=0;
            Tel[p].phone=-100;
            return;
        }
        else
        {
            p=(p+1)%size;
        }

    }
    cout<<"\n Key Not Found!!";
}
void Hashtable::Display()
{
    for(int i=0;i<size;i++)
    {
        if(flag[i]==1)
        {
           cout<<"["<<i<<"]"<<"=>"<<Tel[i].phone<<endl;
        }
        else
        {
               cout<<"["<<i<<"]"<<"=>"<<"NO VALUE"<<endl;
        }
    }
}


int main()
{
    Hashtable obj;
    int ch;
    long long int key1;
    string name;
    do{
    cout<<"\n ************MENU***********";
    cout<<"\n 1.Insert Phone number in Hashtable: ";
    cout<<"\n 2.Search phone number in Hashtable: ";
    cout<<"\n 3.Delete Key from Hashtable: ";
    cout<<"\n 4.Display Hashtable: ";
    cout<<"\n 5.Search by name: ";
    cout<<"\n 6.Exit";
    cin>>ch;
    switch(ch)
    {
    case 1:
             cout<<"\n Enter phone number and name of the sim owner to be inserted: ";
             cin>>key1>>name;
              obj.Insert(key1,name);
              break;
    case 2:
               cout<<"\n Enter value to be searched: ";
               cin>>key1;
               obj.search(key1);
               break;
    case 3:
                cout<<"\n Enter value to be Deleted: ";
                cin>>key1;
                obj.Delete(key1);
                break;
    case 4:
               obj.Display();
               break;
    case 5:
               cout<<"\n Enter name you want to search: ";
               cin>>name;
               obj.search_by_name(name);
               break;

    }
    }while(ch!=5);

    return 0;
}
