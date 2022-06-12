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
    ll a[t];
    for(ll i=0;i<t;i++)
        cin>>a[i];
    ll k;
    cin>>k;
    for(ll i=1;i<t;i++)
    {
        ll sm,k,j;
        j=0;
        k=i;
        while(j<k && j<t)
        {
            sm+=a[j];
            if(j==k-1)
            {
                if(sm==k)
                    cout<<
            }
        }

    }
 return 0;
}
