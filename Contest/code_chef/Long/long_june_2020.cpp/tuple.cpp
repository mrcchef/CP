#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
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

bool sum_check(ll x,ll y,ll a,ll b)
{
    if(a-x==b-y)
        return true;
    return false;
}

bool pro_check(ll x,ll y,ll a,ll b)
{
    if(x!=0 && y!=0 && a%x==0 && b%y==0 && a/x==b/y)
        return true;
    return false;
}

ll check(vi v,vi V,ll c)
{
    v.pb(v[0]);
    V.pb(V[0]);
    for(ll i=0;i<4;i++)
    {
        bool t;
        if(c==1)
            t=sum_check(v[i],v[i+1],V[i],V[i+1]);
        else
            t=pro_check(v[i],v[i+1],V[i],V[i+1]);
        if(t)
            return 1;
    }
    return 2;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vi v,V;
        ll res=0;
        for(ll i=0;i<3;i++)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        for(ll i=0;i<3;i++)
        {
            ll x;
            cin>>x;
            V.pb(x);
        }
        ll cnt=0;
        for(ll i=0;i<3;i++)
        {
            if(v[i]!=V[i])
                cnt++;
        }
        if(cnt==0)
            res=0;
        else if(cnt==1)
            res=1;
        else if(cnt==2)
        {
            res=check(v,V,1);
            res=min(res,check(v,V,0));
        }
        else
        {
            
        }
        
        cout<<res<<endl;
        
    }
 return 0;
}
