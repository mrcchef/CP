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

// Logic:-
// l=6 ,r =7
// l=110 and r=111
// now few observations
// 1. If any bit is flipped b/w the range l and r then all the bits to the right must also be flipped.
// 2. If any bit in a column is flipped the bitwise and of that column is 0
// Here we will eleminate bits from left side which are unequal then set 0 on their positions.
// https://www.youtube.com/watch?v=-qrpJykY2gE&list=PLEJXowNB4kPwa5VPvdQ1U3B2yaogEGDjX&index=6

int main()
{
    ll l,r;
    cin>>l>>r;
    ll cnt=0;
    while(l!=r)
    {
        l=l>>1;
        r=r>>1;
        cnt++;
    }
    l=l<<cnt;
    cout<<l;
    
 return 0;
}
