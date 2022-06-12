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
        ll m=mod;
        ll n;
        cin>>n;
        ll inv[n+1];
        inv[1] = 1;
        for(int i = 2; i < n; ++i)
            inv[i] = (m - (m/i) * inv[m%i] % m) % m;
        for(ll i=1;i<=n;i++)
            cout<<inv[i]<<" ";
    }
 return 0;
}
