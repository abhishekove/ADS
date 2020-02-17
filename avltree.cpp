//============================================================================
// Name        : AVL_Tree_Dictionary.cpp
// Author      : Ashley.J.George
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *lf,*rt;
};

class AVL
{
public:
        node* root;

    AVL()
    {
        root=NULL;
    }
    int height(node *temp);
    int B_Factor(node *temp);
    void preOrder(node*);
    void inOrder(node*);
    void postOrder(node*);
    node* insert_node(node* root,int value);
    node* balance(node *T);
    node* rotate_right(node *parent);
    node* rotate_left(node *parent);
    node* RL(node *parent);
    node* RR(node *parent);
    node* LR(node *parent);
    node* LL(node *parent);
    node* getroot()
    {
        return root;
    }
};
void AVL::preOrder(node *cn)
{
    if(cn != NULL)
    {
        cout<<cn->data<<" ";
        preOrder(cn->lf);
        preOrder(cn->rt);
    }

}


void AVL::inOrder(node *cn)
{
    if(cn != NULL)
    {

        inOrder(cn->lf);
        cout<<cn->data<<" ";
        inOrder(cn->rt);
    }
}


void AVL::postOrder(node *cn)
{
    if(cn != NULL)
    {
        postOrder(cn->lf);
        postOrder(cn->rt);
        cout<<cn->data<<" ";
    }
}

node* AVL::insert_node(node* root,int value)
{

    if(root==NULL)
    {
         root=new node;
         root->data=value;
         root->lf=root->rt=NULL;
         return root;
    }
    else if(value<root->data)
    {
        root->lf=insert_node(root->lf,value);
        root=balance(root);
    }
    else if(value>root->data)
        {
            root->rt=insert_node(root->rt,value);
            root=balance(root);
        }

    return root;
}


int AVL::height(node* temp)
{
    int h=0;
    if(temp!=NULL)
    {
        int l_height=height(temp->lf);
        int r_height=height(temp->rt);
        int max_height=max(l_height,r_height);
        h=max_height+1;
    }
    return h;
}


int AVL::B_Factor(node* temp)
{
    int l_height=height(temp->lf);
    int r_height=height(temp->rt);
    int b_factor=l_height-r_height;
    return b_factor;
}

node* AVL::rotate_right(node* parent)
{
    node* temp;
    temp=parent->lf;
    parent->lf=temp->rt;
    temp->rt=parent;

    return temp;

}


node* AVL::rotate_left(node* parent)
{
    node* temp;
    temp=parent->rt;
    parent->rt=temp->lf;
    temp->lf=parent;

    return temp;

}


node* AVL::LL(node* parent)
{
    node *temp;
    temp=parent->rt;
    parent=rotate_right(parent);
    return parent;
}


node* AVL::RR(node* parent)
{
    node *temp;
    temp=parent->lf;
    parent=rotate_left(parent);
    return parent;
}


node* AVL::LR(node* parent)
{
    node* temp;
    temp=parent->lf;
    parent->lf=rotate_left(temp);
    temp=rotate_right(parent);
    return temp;
}


node* AVL::RL(node* parent)
{
    node* temp;
    temp=parent->rt;
    parent->rt=rotate_right(temp);
    temp=rotate_left(parent);

    return temp;
}


node* AVL::balance(node* T)
{
    int bal_factor=B_Factor(T);
    if(bal_factor>1)
    {
        if(B_Factor(T->lf)>0)
        {
            T=LL(T);
        }
        else
            T=LR(T);
    }
    else if(bal_factor<-1)
    {
        if(B_Factor(T->rt)>0)
            T=RL(T);
        else
            T=RR(T);
    }
    else
    {

    }
    return T;
}


int main()
{
    AVL obj;
    int ch,value;
    node* r;

    do
    {
        cout<<"\n=============== ~ AVL Tree ~ ===============";
        cout<<"\n1. Add A Node.";
        cout<<"\n2. In-order Traversal.";
        cout<<"\n3. Pre-order Traversal.";
        cout<<"\n4. Post-order Traversal.";
        cout<<"\n5. Exit.";
        cin>>ch;
        switch(ch)
        {
        case 1:
                cout<<"\n Enter Value You Want To Enter: ";
                cin>>value;
                obj.root=obj.insert_node(obj.getroot(),value);
                break;
        case 2:
                obj.inOrder(obj.getroot());
                break;
        case 3:
                 obj.preOrder(obj.getroot());
                 break;
        case 4:
                 obj.postOrder(obj.getroot());
                 break;

        }

    }while(ch!=5);

    return 0;
}
