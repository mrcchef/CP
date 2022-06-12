#include<bits/stdc++.h>
using namespace std;
int binary[100001];
void Union(int *p,int *q,int n,int m)
{
    int i;
    for(i=0;i<n;i++)
    {
        binary[p[i]]=1;
        cout<<p[i]<<" ";
    }   
    for(i=0;i<m;i++)
        if(binary[q[i]]==0)
            cout<<q[i]<<" ";   
}

void Inter(int p[],int q [],int n,int m)
{
    int i;
    for(i=0;i<n;i++)
        binary[p[i]]=1;
    for(i=0;i<m;i++)
        if(binary[q[i]]==1)
            cout<<q[i]<<" ";
}
using namespace std;
int main()
{
    int n,m,i,ch;
    cout<<"Enter size of Set 1 ";
    cin>>n;
    int *p=new int[n];
    for(i=0;i<n;i++)
        cin>>p[i];
    cout<<"Enter size of set 2 ";
    cin>>m;
    int *q=new int[m];
    for(i=0;i<m;i++)
        cin>>q[i];
    cout<<"Enter 1 for Union"<<endl<<"Enter 2 for Intersection ";
    cin>>ch;
    if(ch==1)
    {
        Union(p,q,n,m);
    }
    else if(ch==2)
    {
        Inter(p,q,n,m);
    }
    else 
        cout<<"Invalid Input";
}