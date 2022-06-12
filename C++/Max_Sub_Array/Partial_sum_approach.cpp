#include<iostream>
using namespace std;

int max_sum_subarray(int p[],int n)
{
    int i,ans,*s,j,min=p[0];
    s= new int[n];
    s[0]=p[0];
    for(i=1;i<n;i++)
        s[i]=s[i-1]+p[i];
    ans=s[0];   
    for(i=1;i<n;i++)
    {
        if(s[i]-min>ans)
            ans=s[i]-min;
        if(s[i]<min) // if s[i] is negative then only value of min will change.
            min=s[i];
    }
    return ans;
}

int main()
{
    int n,*p;
    cout<<"Enter size ";
    cin>>n;
    p= new int[n];
    cout<<"Enter elements ";
    for(int i=0;i<n;i++)
        cin>>p[i];
    cout<<"max sum of sub array is "<<max_sum_subarray(p,n);
}