#include<iostream>
using namespace std;

void search(int a[],int l)
{
    int i=0,diff=a[0];
    while(i<l)
    {
        if(a[i]-i!=diff)
        {     
            while(diff<a[i]-i)
            {
                cout<<i+diff<<" ";
                diff++;
            }
            cout<<endl;
        }
        i++;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    search(a,n);
}