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
#define pb puah_back
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

// https://www.youtube.com/watch?v=9y7bTW90BCo&list=PLEJXowNB4kPwa5VPvdQ1U3B2yaogEGDjX&index=3
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,l,r;
        cin>>n>>l>>r;
        ll bits=log2(n)+1;
        // cout<<bits<<endl;
        ll i=1;
        ll val=0;
        while(i<=bits)
        {
            if(i>=r && i<=l)
            {
                if(!(n&1))
                {
                    val+=(1<<(i-1));
                }
            }
            else
            {
                if(n&1)
                {
                    val+=(1<<(i-1));
                }
            }
            i++;
            n=n>>1;
        }   
        cout<<val<<endl;
    }
 return 0;
}
