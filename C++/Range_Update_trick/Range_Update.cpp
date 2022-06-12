#include<iostream>
using namespace std;
int trace[10],temp[10];
void update(int x, int y, int value)
{
    trace[x-1]+=value;
    trace[y]-=value;
    temp[0]=trace[0];
    for(int i=1;i<10;i++)
        temp[i]=temp[i-1]+trace[i];
}

int main()
{   
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int x,y,v;
    cout<<"Enter range of elements to be updated\nEnter Value";
    cin>>x>>y>>v;
    update(x,y,v);
    for(int i=0;i<10;i++)
        a[i]+=temp[i];
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
}