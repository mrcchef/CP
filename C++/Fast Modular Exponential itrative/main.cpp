#include <iostream>

using namespace std;

int clac_expo_itrative(int a,int n,int mod)
{
    int ans=1;
    while(n!=0)
    {
        if(n%2==0)
        {
            a=1LL*a*a;
            n=n/2;
        }
        else
        {
            n=n-1;
            ans=ans*a;
        }
    }
    return ans%mod;
}

int main()
{
    int a,n,mod;
    cin>>a>>n>>mod;
    cout<<clac_expo_itrative(a,n,mod);
    return 0;
}
