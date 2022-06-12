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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll w[n+1],p[n+1];
        for(ll i=1;i<=n;i++)
            cin>>w[i];
        for(ll i=1;i<=n;i++)
            cin>>p[i];
        ll dp[n+1][m+1]={0};
        for(ll i=0;i<=m;i++)
            dp[0][i]=0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                if(j<w[i])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
            }
        }
        for(ll i=0;i<=n;i++)
        {
            for(ll j=0;j<=m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }   

        ll i=n,j=m;
        ll cnt[n+1]={0};
        while(i>0)
        {
            if(dp[i-1][j]!=dp[i][j])
            {
                cnt[i]=1;
                j=j-w[i];
            }
            i--;
        }
        for(ll k=1;k<=n;k++)
        {
            if(cnt[k]==1)
                cout<<w[k]<<" "<<p[k]<<endl;
        }
    }
 return 0;
}
