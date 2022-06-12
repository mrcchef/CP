#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
using namespace std;
#define ll long long int
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll dp[105][105][2];

int AdjP(ll n,ll k,ll bit)
{
    if(n==0) return 0;

    if(n==1)
    {
        if(k==0)
            return 1;
        else if(k<0 || k>0)
            return 0;
    }

    if(dp[n][k][bit]!=-1)
        return dp[n][k][bit];
    
    ll res=-1;
    if(bit==1)
    {
        res=AdjP(n-1,k-1,1)+AdjP(n-1,k,0);
        return dp[n][k][bit]=res;
    }
    
    res=AdjP(n-1,k,0)+AdjP(n-1,k,1);
    return dp[n][k][bit]=res;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,n,k;
        cin>>x>>n>>k;
        memset(dp,-1,sizeof(dp));
        ll res=AdjP(n,k,1);
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<k;j++)
            {
                for(ll m=0;m<2;m++)
                    cout<<dp[i][j][m]<<" ";
                cout<<endl;
            }
        }
        res+=AdjP(n,k,0);
        cout<<x<<" "<<res<<endl;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<k;j++)
            {
                for(ll m=0;m<2;m++)
                    cout<<dp[i][j][m]<<" ";
                cout<<endl;
            }
            
        }
    return 0;
    }
    

 return 0;
}
