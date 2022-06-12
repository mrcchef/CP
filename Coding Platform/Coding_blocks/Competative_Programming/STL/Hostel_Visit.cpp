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

bool compare(pair<ll,ll> p1,pair<ll,ll> p2)
{
    ll x1,y1,x2,y2;
    x1=p1.first;
    y1=p1.second;
    x2=p2.first;
    y2=p2.second;
    
    return (x1+y1) < (x2+y2);
}

// https://online.codingblocks.com/app/player/138764/content/108213/5368/code-challenge
// with the help of priority queue we are maintaing an sorted array of length k and when we require to print the kth maximum number we 
// can directly use that element that it is more efficient method than set container or vector using sort function

int main()
{
    ll n,k,sz=0;
    cin>>n>>k;
    priority_queue<ll> p;
    for(ll i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll a,b;
            cin>>a>>b;
            ll val=a*a+b*b;
            if(p.size()==k)
            {
                if(val<p.top())
                {
                    p.pop();
                    p.push(val);
                }
            }
            else
            {
                p.push(val);
            }
        }
        else
        {
            cout<<p.top()<<endl;
        }
    }
 return 0;
}
