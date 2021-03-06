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
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll p=a[1],i,s;  
    ll res=INT_MIN;
    for(i=2;i<=n;i++)
    {
        s=p+a[i];
        res=max(res,s);
        if(s<0)
        {
            p=0;
        }
        else
            p=s;
    }
    cout<<res<<endl;
    
 return 0;
}
