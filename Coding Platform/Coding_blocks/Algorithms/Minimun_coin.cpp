#include<climits>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

ll fxp(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}

void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,j;
        cin>>n;
        int f[n+1];
        f[0]=0;
        for(ll j=1;j<=n;j++)
        {
            ll op1,op2,op3;
            op1=op2=op3=INT_MAX;
            if(j-1>=0)
            {
                op1=f[j-1]+1;
            }
            if(j-7>=0)
            {
                op2=f[j-7]+1;
            }
            if(j-10>=0)
            {
                op3=f[j-10]+1;
            }
            f[j]=min(min(op1,op2),op3);
        }
        cout<<f[n]<<endl;
    }    
    return 0;
}
