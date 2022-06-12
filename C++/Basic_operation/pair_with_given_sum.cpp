#include<bits/stdc++.h>
using namespace std;
int Max=0;
int f[100];

void cal(int a[],int l)
{
    int Min,i;
    Max=Min=a[0];
    for(i=1;i<l;i++)
    {
        if(a[i]<Min)
            Min=a[i];
        else if(a[i]>Max)
            Max=a[i];
    }
}



void freq(int a[],int n)
{
for(int i=0;i<n;i++)
{
    if(f[a[i]]!=1)
        f[a[i]]=1;
}

}

void search(int a[],int l,int k)
{
    for(int i=0;i<l;i++)
    {
        if(f[k-a[i]]==1)
        {
            cout<<a[i]<<" "<<k-a[i]<<endl;
            f[k-a[i]]=f[a[i]]=-1;            
        }   
    }
}

int main()
{
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"ENter Sum:";
    cin>>k;
    cal(a,n);
    freq(a,n);
    search(a,n,k);
}