#include<iostream>
using namespace std;

int sub_array(int a[],int n)
{
    int i,sum=0,ans=a[0];
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum > ans)
            ans=sum;
        if(sum<0)
            sum=0;
    }
    return ans;
}

int main()
{
    int n,*p;
    cout<<"enter size of array";
    cin>>n;
    p=new int[n];
    cout<<endl<<"enter elements";
    for(int i=0;i<n;i++)
        cin>>p[i];
    cout<<"maximum sum of subarray is "<<sub_array(p,n);
}