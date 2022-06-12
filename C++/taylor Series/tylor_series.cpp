#include<iostream>
using namespace std;

double tylor(int x,int n)
{   
    double r;
    static double p=1,f=1;
    if(n==0)
        return 1;
    else
    {   
        r=tylor(x,n-1) ;
        p*=x;
        f*=n;
        return r + p/f;   
    }
    
    
}
int main()
{
    int x,n;
    cin>>x>>n;
    cout<<tylor(x,n);
}