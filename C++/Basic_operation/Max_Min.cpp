#include<bits/stdc++.h>
using namespace std;

void cal(int a[],int l)
{
    int Max,Min,i;
    Max=Min=a[0];
    for(i=1;i<l;i++)
    {
        if(a[i]<Min)
            Min=a[i];
        else if(a[i]>Max)
            Max=a[i];
    }
    cout<<"Max : "<<Max<<endl<<"Min : "<<Min;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cal(a,n);
}