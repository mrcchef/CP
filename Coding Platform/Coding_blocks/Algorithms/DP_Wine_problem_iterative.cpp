#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

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
       ll n;
       cin>>n;
       ll p[n];
       for(ll i=0;i<n;i++) cin>>p[i];
       ll dp[n][n]={0};
       ll k=n;
       for(ll i=0;i<n;i++) dp[i][i]=p[i]*k;
       for(ll j=1;j<n;j++)
       {
           ll i=0,m=j;
           k--;
           while(i<n && m<n)
           {
               ll res=0;
               if(dp[i][m-1]>dp[i+1][m])
               {
                   res=p[m]*k;
               }
               else
               {
                   res=p[i]*k;
               }
               dp[i][m]=res+max(dp[i][m-1],dp[i+1][m]);
               i++;
               m++;
           }
       }
       for(ll i=0;i<n;i++)
       {
           for(ll j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
       }
       cout<<dp[0][n-1];
    }
 return 0;
}