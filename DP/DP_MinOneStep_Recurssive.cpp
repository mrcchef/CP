#include<bits/stdc++.h>
using namespace std;

int check(int a[],int n)
{
    if(n==1)
    {
        return 0;
    }
    
    if(a[n]!=0)
        return a[n];
    
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;

    if(n%2==0)
        op1=check(a,n/2)+1;
    else if(n%3==0)
        op2=check(a,n/3)+1;
    op3=check(a,n-1)+1;

    int ans=min(min(op1,op2),op3);
    return a[n]=ans;
}

int main()
{
    int n;
    cout<<"Enter a Number:";
    cin>>n;
    int a[n+1]={0};
    cout<<"Result:"<<check(a,n);}