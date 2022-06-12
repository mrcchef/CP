#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a Number:";
    cin>>n;
    int a[n+1];
    a[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0 && i%3==0)
            a[i]=min(min(a[i/2],a[i/3]),a[i-1])+1;
        else if(i%2==0)
            a[i]=min(a[i/2],a[i-1])+1;
        else if(i%3==0)
            a[i]=min(a[i/3],a[i-1])+1;
        a[i]=a[i-1]+1;
        
    }
    cout<<"Result:"<<a[n];
}