#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void reverse(int a[],int l)
{
    int i,b[l];
    i=l-1;
    int j=0;
    while(i>=0)
        b[j++]=a[i--];
    for(i=0;i<l;i++)
    a[i]=b[i];
}

void insert(int a[],int l,int val)
{
    for(int i=l-1;i>=0;i--)
        if(val<a[i])
            a[i+1]=a[i];
        else
        {
             a[i+1]=val;
             break;
        }           
}

void sep(int a[],int l)
{
    for(int i=0;i<l;i++)
    {
        int j,temp;
        if(a[i]<0)
        {
            temp=a[i];
            j=i-1;
            while(j>=0)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=temp;
        }
    }
}

void sep1(int a[],int l)
{
    int i=0,j=l-1;
    while(j>i)
    {
        while(a[i]<0)
            i++;
        while(a[j]>=0)
            j--;
        if(j>i)
        swap(a[i],a[j]);
    }
}

void output(int a[],int l)
{
    int i=0;
    for(i;i<l;i++)
        cout<<a[i]<<" ";
}

int main()
{
    int n,val;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //reverse(a,n);
    //cin>>val;
    //insert(a,n,val);
    sep1(a,n);
    output(a,n);

}
