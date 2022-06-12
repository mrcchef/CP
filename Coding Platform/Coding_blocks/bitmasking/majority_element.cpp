// https://www.youtube.com/watch?v=0s3zqYaDInE&list=PLEJXowNB4kPwa5VPvdQ1U3B2yaogEGDjX&index=5
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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,mx=0;
        cin>>n;
        vi v;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            v.pb(x);
            mx=max(mx,v[i]);
        }
        ll mn=n/2;
        ll mask=1;
        ll len=log2(mx)+1;
        ll i=0;
        ll val=0;
        ll cnt=0;
        while(i<len)
        {
            cnt=0;
            for(ll j=0;j<n;j++)
            {
                if(mask&v[j])
                {
                   cnt++; 
                }
            }
            if(cnt>mn)
            {
                val+=(1<<i);
            }
            i++;
            mask=1<<i;
        }
        cnt=0;
        for(ll j=0;j<n;j++)
        {
            if(v[j]==val)
                cnt++;
        }
        if(cnt>mn)
            cout<<"Majority Element:"<<val<<endl;
        else 
            cout<<"Does not exist"<<endl;
    }
 return 0;
}
