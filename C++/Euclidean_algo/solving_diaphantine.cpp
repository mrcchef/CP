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

// https://codeforces.com/problemset/problem/1244/C

void extended(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    ll x1,y1;
    extended(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
}

ll modulo_inverse(ll a,ll b)
{
    ll x,y;
    extended(a,b,x,y);
    x=(x+b)%b;
    return x;
}

int main()
{
    ll n,p,w,d,t=1;
    cin>>n>>p>>w>>d;
    ll x,y,g,z;
    g=__gcd(w,d);
    if(p%g!=0)
    {
        cout<<-1;
        return 0;
    }
    if(w*n<p)
    {
        cout<<-1;
        return 0;
    }
    w/=g;
    d/=g;
    p/=g;
    y=((p%w)*(modulo_inverse(d,w)))%w;
    x=(p-y*d)/w;
    // cout<<"Hello\n";
    if(x<0)
    {
        cout<<-1;
        return 0;
    }
    // cout<<"Hello\n";
    if(x+y>n)
    {
        cout<<-1;
        return 0;
    }
    // cout<<"Hello\n";
    
    z=n-x-y;
    cout<<x<<" "<<y<<" "<<z<<endl;
 return 0;
}
