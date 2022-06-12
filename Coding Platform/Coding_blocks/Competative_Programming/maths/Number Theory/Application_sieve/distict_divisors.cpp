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

const ll n=10000000;
ll pr[n+1]={0}; // Here this array is used to store the number of distinct divisors ith no. have

void sieve()
{
    
    for(ll i=2;i<=n;i++)
    {
        if(!pr[i]) // if pr[i] is zero it means it is a prime number b/c till now it has zero divisors;
        {
            for(ll j=i;j<=n;j+=i)
            {
                pr[j]++;
            }
        }
    }
}


int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        cout<<pr[x]<<endl;
    }
 return 0;
}
