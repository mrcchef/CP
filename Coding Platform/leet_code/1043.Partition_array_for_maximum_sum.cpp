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
    ll n,k;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    cin>>k;
    ll m=k;
    ll mx[n+1]={0};
    for(ll i=1;i<=n;i++)
    {
        if(i<=m)
            mx[i]=max(mx[i-1],a[i]);
        else if(i==m+1)
        {
            mx[i]=a[i];
            m=m+k;
        }
    }
    sort(mx,mx+n+1,greater<int>());
    
 return 0;
}
