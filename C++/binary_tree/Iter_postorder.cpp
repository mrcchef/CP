#include<iostream>
using namespace std;

struct tree
{
    tree *lchild,*rchild;
    int data;
}*root=NULL;

struct stack
{
    struct tree *data;
    struct stack *next;
}*top=NULL,*top1=NULL;

void push(stack **p,tree *key)
{
    stack *t=new stack;
    if(t==NULL)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }   
    else 
    {
        t->data=key;
        t->next=NULL;
        if(*p==NULL)
        {
            *p=t;
        }   
        else
        {
            t->next=*p;
            *p=t;
        }
    }
}

tree *pop(stack **p)
{
    stack *t;
    tree *x=NULL;
    if(*p==NULL)
        return x;
    x=(*p)->data;
    t=*p;
    *p=(*p)->next;
    delete t;
    return x;
}

bool isSEmpty(stack *p)
{
    if(p==NULL)
        return true;
    return false;
}

tree *stackTop(stack *p)
{
    if(p==NULL)
        return NULL;
    return p->data;
}

void Sdisplay(stack *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Iter_postorder(tree *p)
{
    tree *t;
    if(root==NULL)
        return;
    if(p==root)
        push(&top,p);
    while(!isSEmpty(top))
    {
        t=pop(&top);
        if(t->lchild)  
            push(&top,t->lchild);
        if(t->rchild)
            push(&top,t->rchild);
        push(&top1,t);
    }
    while(!isSEmpty(top1))
    {
        cout<<pop(&top1)->data<<" ";
    }
}

// void Iter_postorder(tree *p)
// {
//     if(root==NULL)
//         return ;
//     while(p!=NULL || !isSEmpty())
//     {
//         if(p!=NULL)
//         {
//             if(p->rchild!=NULL)
//                 push(p->rchild);
//             push(p);
//             p=p->lchild;
//         }
//         else
//         {   
//             tree *q;
//             p=pop();
//             if(p->rchild!=NULL)
//             {
//                 if(!stackTop() && p->rchild->data==stackTop()->data)
//                 {
//                     q=pop();
//                     push(p);
//                     p=q;
//                 }
//                 else
//                 {
//                     cout<<p->data<<" ";
//                     p=NULL;
//                 }    
//             } 
//             else
//             {
//                cout<<p->data<<" ";
//                p=NULL; 
//             }                  
//         }   
//     }
// }

void Insert(int key)
{
    tree *t=new tree;
    t->lchild=t->rchild=NULL;
    t->data=key;
    if(root==NULL)
    {
        root=t;
        return ;
    }
    tree *p=root,*q=NULL;
    while(p!=NULL)
    {
        q=p;
        if(key<p->data)
            p=p->lchild;
        else if(key>p->data)
            p=p->rchild;
        else
        {
            return ;
        }
    }
    if(key<q->data)
        q->lchild=t;
    else 
        q->rchild=t;
}

int main()
{
    int n,key;
    cout<<"Enter no. of elements:";
    cin>>n;
    cout<<"Enter Elements:";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        Insert(key);
    }  
    cout<<"\nPost Order of tree:";
    Iter_postorder(root);  

}