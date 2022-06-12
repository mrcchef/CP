#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
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
    ll digits=log10(n)+1;
    vector <ll> v;
    for(ll i=1;i<=(1<<digits);i++)
    {
        ll n=i,val=0,k=digits;
        while(k>0)
        {
            if(n&1)
            {
                val=val*10+7;
            }
            else
            {
                val=val*10+4;
            }
            n=n>>1;
            k--;
        }
        v.push_back(val);   
    }
    ll res=0;
    for(ll i=1;i<digits;i++)
    {
        res+=1<<i;
    }
    sort(v.begin(),v.end());
    ll i;
    for(i=0;i<v.size();i++)
    {   
        if(n==v[i])
            break;
    }    
    res+=i+1;
    cout<<res;
 return 0;
}
