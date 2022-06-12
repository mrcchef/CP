//Concept
//our aim is to calculate a^n
//if n is even it can be written in the form (a^2)^(n/2)
//if n is odd it can be written in the from a*a^(n-1)
//this process continue until n becomes 0
//time complexibility if log n

#include <iostream>

using namespace std;

int Fast_Modular(int a,int n,int mod)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return Fast_Modular(1LL*a*a,n/2,mod);
    return 1LL*a*Fast_Modular(a,n-1,mod)%mod;
}

int main()
{
    int a,n,mod;
    cin>>a>>n>>mod;
    cout<<Fast_Modular(a,n,mod);
    return 0;
}
