#include<iostream>
using namespace std;

struct tree
{
    tree *lchild,*rchild;
    int data;
}*root;

struct queue
{
    queue *next;
    tree *data;
}*front=NULL,*rear=NULL;

void enqueue(tree *key)
{
    queue *t=new queue;
    if(!t)
    {
        cout<<"Queue Overflow\n";
        return;
    }
    t->data=key;
    t->next=NULL;
    if(front==NULL)
        front=rear=t;
    else
    {
        rear->next=t;
        rear=t;
    }   
}

tree *dequeue()
{
    tree *x=NULL;
    queue *t;
    if(front==NULL)
        return x;
    t=front;
    x=t->data;
    front=front->next;
    delete t;
    return x;
}

bool isQEmpty()
{
    if(front==NULL)
        return true;
    return false;
}

void insert()
{
    tree *p=root,*q;
    int x;
    cout<<"Enter Root Value:";
    cin>>x;
    if(!root)
    {
        tree *t=new tree;
        t->data=x;
        t->lchild=t->rchild=NULL;
        root=t;
        enqueue(root);
    }
    while(!isQEmpty())
    {
        q=dequeue();
        cout<<"Enter left child of "<<q->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            tree *t=new tree;
            t->data=x;
            t->lchild=t->rchild=NULL;
            q->lchild=t;
            enqueue(q->lchild);
        }
        cout<<"Enter Right child of "<<q->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            tree *t=new tree;
            t->data=x;
            t->lchild=t->rchild=NULL;
            q->rchild=t;
            enqueue(q->rchild);
        }
    }
}

tree *inpre(tree *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}

tree *insucc(tree *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}

int height(tree *p)
{
    if(p==NULL)
        return 0;
    return height(p->lchild)+height(p->rchild)+1;
}

tree *del(tree *p,int key)
{
    if(p==NULL)
        return NULL;
    else if(!p->lchild && !p->rchild)
    {
        if(p==root)
            root=NULL;
        delete(p);
        return NULL;
    }   
    if(key<p->data)
        p->lchild=del(p->lchild,key);
    else if(key>p->data)
        p->rchild=del(p->rchild,key);
    else
    {
        tree *q;
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=del(p->lchild,q->data);
        }
        else
        {
            q=insucc(p->rchild);
            p->data=q->data;
            p->rchild=del(p->rchild,q->data);
        }
    }
    return p;
}

void display(tree *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        display(p->lchild);
        display(p->rchild);
    }
}

int main()
{
    int x,t;
    insert();
    display(root);
    do
    {
        cout<<"Enter element to be deleted:";
        cin>>x;
        del(root,x);
        display(root);
        cout<<"\nPress 1 to delete again:";
        cin>>t;
    }while(t==1);
    

}
