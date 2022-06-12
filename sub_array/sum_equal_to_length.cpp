#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }

ll fxp(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}

void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll v[n];
        ll j,i;
        for(i=0;i<n;i++)
        {
            cin>>v[i];
        }
        ll s[n];
        s[0]=(v[0]%n+n)%n;
        for(i=1;i<n;i++)
        {
            s[i]=s[i-1]+v[i]; // Creating partial sum array
            s[i]=(s[i]%n+n)%n; // since we want (s[b]-s[a])%n==0 this implies that s[b]%n=s[a]%n
        }
        ll c[n]={0};
        c[0]=1; // B/c the sum of empty subarray will be zero.
        for(i=0;i<n;i++)
        {
            c[s[i]]++; // Here we are counting frequency remainders which are b/w 0 and n-1. If there are 2 or more than 2 similar modular then
            // we can use them to find our result.
        }
        ll res=0;
        for(i=0;i<n;i++)
        {
            if(c[i]>=2)
            {
                res+=(c[i]*(c[i]-1))/2; // for freq. greator than 2 we have to select to 2 values from c[i]>=2 i.e c[i]C2 
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
