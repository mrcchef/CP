#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define deb(x) cout << #x << "=" << x << endl
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

ll BIT[10000]={0};
ll n;

void update(ll val,ll i)
{
    while(i<=n)
    {
        BIT[i]=max(val,BIT[i]);
        i+=(i&(-i));
    }
}

ll query(ll i)
{
    ll val=INT_MIN;
    while(i>0)
    {
        val=max(val,BIT[i]);
        i-=(i&(-i));
    }
    return val;
}

int main()
{
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        update(a[i],i);
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll ed;
        cin>>ed;
        ll res=query(ed);
        cout<<res<<endl;
    }
    // we can also update our BIT
    update(10,5);
    cin>>q;
    while(q--)
    {
        ll ed;
        cin>>ed;
        ll res=query(ed);
        cout<<res<<endl;
    }

 return 0;
}
