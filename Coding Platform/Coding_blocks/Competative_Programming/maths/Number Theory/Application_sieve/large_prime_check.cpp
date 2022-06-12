#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include<bitset>
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

// of the order around 10^14

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

const ll n=100000000;
bitset<n+1> b;
vi primes;

void sieve()
{
    b.set();// It sets all the n+1 bits 
    b[0]=b[1]=0;
    for(ll i=2;i<=n;i++)
    {
        if(b[i])
        {
            primes.pb(i);
            for(ll j=i*i;j<=n;j+=i)
            {
                b[j]=0;
            }
        }
    }
}

bool large(ll no)
{
    if(no<=n)
    {
        return b[no]==1?true:false;
    }
    
    for(ll i=0;primes[i]*primes[i]<=no;i++)
    {
        if(no%primes[i]==0)
            return false;
    }
    return true;
}

int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(large(n))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
 return 0;
}
