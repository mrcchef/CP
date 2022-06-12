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
}*top=NULL;

struct queue
{
    tree *data;
    queue *next;
}*front=NULL,*rear=NULL;

void push(tree *key)
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
        if(top==NULL)
        {
            top=t;
        }   
        else
        {
            t->next=top;
            top=t;
        }
    }
}

tree *pop()
{
    stack *t;
    tree *x=NULL;
    if(top==NULL)
        return x;
    x=top->data;
    t=top;
    top=top->next;
    delete t;
    return x;
}

bool isSEmpty()
{
    if(top==NULL)
        return true;
    return false;
}

tree *stackTop()
{
    if(top==NULL)
        return NULL;
    return top->data;
}

void Sdisplay()
{
    stack *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void enqueue(tree *val)
{
    queue *t=new queue;
    if(t==NULL)
    {
        cout<<"Queue Overflow";
    }
    else
    {
        t->data=val;
        t->next=NULL;
        if(front==NULL)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
    
}

tree *dequeue()
{
    tree *x=NULL;
    queue *t=new queue;
    if(front==NULL)
        return x;
    t=front;
    if(front==rear)
        front=rear=NULL;
    else
        front=front->next;
    x=t->data;
    delete t;
    return x;
}

bool isQEmpty()
{
    if(front==NULL)
        return true;
    return false;
}

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

void preorder(tree *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);

    }
}

void inorder(tree *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

int leafcount(tree *p)
{
    int x,y;
    if(p)
    {
        x=leafcount(p->lchild);
        y=leafcount(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        return x+y;
    }
    return 0;
}

int internalcount(tree *p)
{
    int x,y;
    if(p)
    {
        x=internalcount(p->lchild);
        y=internalcount(p->rchild);
        if(p->lchild || p->rchild)
            return x+y+1;
        return x+y;
    }
    return 0;
}

int height(tree *p)
{
    int x,y;
    if(p)
    {
        x=height(p->lchild);
        y=height(p->rchild);

        if(x>y)
            return ++x;
        return ++y;
    }
    return 0;
}

void Iter_preorder(tree *p)
{
    while(!isSEmpty() || p )
    {
        if(p)
        {
            cout<<p->data<<" ";
            push(p);
            p=p->lchild;
        }
        else
        {
            p=pop();
            p=p->rchild;
        }
    }
}

void Iter_inorder(tree *p)
{
    while(!isSEmpty() || p )
    {
        if(p)
        {
            push(p);
            p=p->lchild;
        }
        else
        {
            p=pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }    
}

void Iter_levelorder(tree *p)
{
    if(p==NULL)
        return;
    cout<<p->data<<" ";
    enqueue(p);
    while(!isQEmpty())
    {
        p=dequeue();
        if(p->lchild)
        {
            enqueue(p->lchild);
            cout<<p->lchild->data<<" ";
        }
        if(p->rchild)
        {
            enqueue(p->rchild);
            cout<<p->rchild->data<<" ";
        }  
    }
}

tree *inorder_preccesor(tree *p)
{
    while(p && p->rchild)
        p=p->rchild;
    return p;
}

tree *inorder_successor(tree *p)
{
    while(p && p->lchild)
        p=p->lchild;
    return p;
}

tree* delTree(tree *p,int key)
{
    tree *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        delete(p);
        return NULL;
    }
    if(key<p->data)
        p->lchild=delTree(p->lchild,key);
    else if(key>p->data)
        p->rchild=delTree(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inorder_preccesor(p->lchild);
            p->data=q->data;
            p->lchild=delTree(p->lchild,q->data);
        }
        else
        {
            q=inorder_successor(p->rchild);
            p->data=q->data;
            p->rchild=delTree(p->rchild,q->data);
        }
    }
    return p;
}

void Iter_postorder(tree *p)
{
    long int temp;
    while(p!=NULL || !isSEmpty())
    {
        if(p!=NULL)
        {
            if(p->rchild!=NULL)
                push(p->rchild);
            push(p);
            p=p->lchild;
        }
        else
        {   
            tree *q;
            p=pop();
            if(p->rchild!=NULL)
            {
                if(p->rchild->data==stackTop()->data)
                {
                    q=pop();
                    push(p);
                    p=q;
                }
                else
                {
                    cout<<p->data<<" ";
                    p-NULL;
                }
                
            } 
            else
            {
               cout<<p->data<<" ";
               p=NULL; 
            }
                           
        }
        
    }
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
    cout<<"preorder of tree:";
    preorder(root);
    cout<<endl;
    Iter_preorder(root);
    cout<<"\ninorder of tree:";
    Iter_inorder(root);
    cout<<endl;
    inorder(root);
    cout<<"\nLevel Order of tree:";
    Iter_levelorder(root);
    // cout<<"\nPost Order of tree:";
    // Iter_postorder(root);
    cout<<"\nNumber of leaf nodes:"<<leafcount(root);
    cout<<"\nNumber of internal nodes:"<<internalcount(root);
    n=height(root);
    cout<<"\nHeight of Tree:"<<--n;
    cout<<"\nEnter element to be deleted:";
    cin>>n;
    delTree(root,n);
    preorder(root);
}