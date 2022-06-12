//https://online.codingblocks.com/app/player/84316/content/80983/6321/lecture
#include <iostream>
#include <vector>
#include <list>
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
//DP approch is applied when performinig any operration ot an iteration may affect the other iterations.

int cal(ll p[], ll i,ll j,ll y,ll dp[][100])
{
    if(i>j)
        return 0;
    if(dp[i][j]!=0)
        return dp[i][j];
    ll op1,op2;
    op1=p[i]*y+cal(p,i+1,j,y+1,dp);
    op2=p[j]*y+cal(p,i,j-1,y+1,dp);
    dp[i][j]=max(op1,op2);
    return dp[i][j];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll p[n];
        ll j;
        ll dp[100][100]={0}; // This makes time complexity to be O(n^2) b/c it reduces cal. of multiple vaules more than one time.
        for(ll i=0;i<n;i++)
        {
            cin>>p[i];
        }
        ll res=cal(p,0,n-1,1,dp);
        cout<<res<<endl;
    }
 return 0;
}
