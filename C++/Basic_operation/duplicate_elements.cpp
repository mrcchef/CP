#include<bits/stdc++.h>
using namespace std;

void duplicate(int a[],int l)
{
    int lastdup=a[0],j;
    for(int i=0;i<l-1;i++)
    {
        if(a[i]==a[i+1] && a[i]!=lastdup)
        {

            cout<<a[i]<<" ";
            lastdup=a[i];
        }
    }
}
void dulpicate_count(int a[],int l)
{
    int j;
    for(int i=0;i<l-1;i++)
    {
        if(a[i]==a[i+1])
        {
            j=i+1;
            while(a[j]==a[i])
                j++;
        cout<<"count of "<<a[i]<<" is "<<j-i<<endl;
        i=j-1;
        }
    }
}

int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];
duplicate(a,n);
dulpicate_count(a,n);
}