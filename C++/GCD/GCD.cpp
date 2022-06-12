#include<iostream>
using namespace std;

int main()
{
    int a,b,mod;
    cin>>a>>b;
    if(a<b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    while(a%b!=0)
    {
        mod=a%b;
        a=b;
        b=mod;
    }
    cout<<b;
    

}