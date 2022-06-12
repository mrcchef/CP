#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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

ll cntbits(ll n)
{
    ll cnt=0;
    while(n)
    {
        cnt++; // count and then remove
        n=n&(n-1); // This removes last bit in very iteration.
    }
    return cnt;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll x=cntbits(n);
        ll y=__builtin_popcount(n);
        cout<<x<<" "<<y;
    }
 return 0;
}
