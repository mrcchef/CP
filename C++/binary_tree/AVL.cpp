#include<iostream>
using namespace std;

struct tree
{
    tree *lchild,*rchild;
    int data,h;
}*root;

int height(tree *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->h:0;
    hr=p && p->rchild?p->rchild->h:0;
    return hl>hr?hl+1:hr+1;
}

int BF(tree *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->h:0;
    hr=p && p->rchild?p->rchild->h:0;
    return hl-hr; 
}

tree *LLRotation(tree *p)
{
    tree *pl=p->lchild;
    tree *plr=pl->rchild;
    p->lchild=plr;
    pl->rchild=p;
    if(p==root)
        root=pl;
    return pl;
}

tree *RRRotation(tree *p)
{
    tree *pr=p->rchild;
    tree *prl=pr->lchild;
    p->rchild=prl;
    pr->lchild=p;
    if(p==root)
        root=pr;
    return pr;
}

tree *LRRotation(tree *p)
{
    tree *pl=p->lchild;
    tree *plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    if(p==root)
        root=plr;
    return plr;
}

tree *RLRotation(tree *p)
{
    tree *pr=p->rchild;
    tree *prl=pr->lchild;
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;
    prl->lchild=p;
    prl->rchild=pr;
    if(p==root)
        root=prl;
    return prl;
}

tree *AVLinsert(tree *p,int key)
{
    if(p==NULL)
    {
        tree *t=new tree;
        t->data=key;
        t->h=1;
        t->lchild=t->rchild=NULL;
        if(root==NULL)
            root=t;
        return t;
    }
    if(key<p->data)
        p->lchild=AVLinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=AVLinsert(p->rchild,key);
    p->h=height(p);
    if(BF(p)==2 && BF(p->lchild)==1)
        return LLRotation(p);
    else if(BF(p)==2 && BF(p->lchild)==-1)
        return LRRotation(p);
    else if(BF(p)==-2 && BF(p->rchild)==-1)
        return RRRotation(p);
    else if(BF(p)==-2 && BF(p->rchild)==1)
        return RLRotation(p);
    return p;
}

tree *inorder_preccesor(tree *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}

tree *inorder_successor(tree *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}

tree *AVLDelete(tree *p,int key)
{
    if(p==NULL)
        return NULL;
    if(!p->lchild && !p->rchild  && key==p->data)
    {
        if(p==root)
            root=NULL;
        delete(p);
        return NULL;
    }
    tree *q;
    if(key<p->data)
        p->lchild=AVLDelete(p->lchild,key);
    else if(key>p->data)
        p->rchild=AVLDelete(p->rchild,key);
    else if(key==p->data)
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inorder_preccesor(p->lchild);
            p->data=q->data;
            p->lchild=AVLDelete(p->lchild,q->data);
        }
        else
        {
            q=inorder_successor(p->rchild);
            p->data=q->data;
            p->rchild=AVLDelete(p->rchild,q->data);   
        }
    }
    p->h=height(p);
    if(BF(p)==2 && BF(p->lchild)==1)
        return LLRotation(p);
    else if(BF(p)==2 && BF(p->lchild)==-1)
        return LRRotation(p);
    else if(BF(p)==-2 && BF(p->rchild)==-1)
        return RRRotation(p);
    else if(BF(p)==-2 && BF(p->rchild)==1)
        return RLRotation(p);
    return p;
}
    
tree *preorder(tree *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void create()
{
    int i=0;
    cout<<"Enter -1 When Creation is done\n";
    while (true)
    {
        cout<<"Enter Data: ";
        cin>>i;
        if(i==-1)
            break;
        AVLinsert(root,i);
    }
    
}

int main()
{
    tree *p;
    int i,j;
    do
    {
        cout<<"Press 1 to Create\nPress 2 to Insert\nPress 3 to delete\nPress 4 to preorder:\n";
        cin>>i;
        switch(i)
        {
            case 1 : create();break;
            case 2 : int key;cout<<"Enter Data:";cin>>key;AVLinsert(root,key);break;
            case 3 : cout<<"Enter Data:";cin>>key;AVLDelete(root,key);break;
            case 4 : cout<<"Preorder Transversal:";preorder(root);break;
            default : exit(0);
        };
        cout<<"Press 1 to continue:";
        cin>>j;
    }while(j--);
}