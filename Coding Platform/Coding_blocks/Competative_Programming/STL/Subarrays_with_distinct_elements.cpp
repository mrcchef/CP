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

// https://online.codingblocks.com/app/player/138764/content/108213/5173/code-challenge#
// Main concept of the question is to use to pointer i and j among them j is free to move and i will only move if there is a certain condition
// encouters. Here we find the a sub array of numbers starting from i and ends j-1. j is is not included in that subarray.

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll i=0,j=0,ans=0;
    fo(i,n) cin>>a[i];
    unordered_set<ll> s;
    i=0;
    fo(i,n)
    {
        while(j<n && s.find(a[j])==s.end()) // j is not included b/c this while loop only terminates if element at j does not satisfy this condition
        {                                   // so j can not be in that subarray where actually those elements are present which satisfy the condition
            s.insert(a[j]);
            j++;
        }
        ll sz=j-i;
        ans+=(sz*(sz+1))/2;
        s.erase(a[i]);
    }
    cout<<ans<<endl;
 return 0;
}
