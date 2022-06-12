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
const long long mod = 1e9;

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

ll n,k;
vi b(k),c(k);

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B)
{
    vector<vector<ll>> sol(k,vector<ll>(k));
    for(ll i=0;i<k;i++)
    {
        for(ll j=0;j<k;j++)
        {
            for(ll x=0;x<k;x++)
            {
                sol[i][j]=(sol[i][j]+(A[i][x]*B[x][j])%mod)%mod;
                // sol[i][j]=sol[i][j]%mod;
            }
        }
    }
    return sol;
}

vector<vector<ll>> pow(vector<vector<ll>> T,ll n)
{
    if(n==1)
        return T;
    if(n&1)
        return multiply(T,pow(T,n-1));
    return pow(multiply(T,T),n/2);
}

ll solve(vector<vector<ll>> T,ll n)
{
    for(ll i=0;i<k;i++)
    {
        for(ll j=0;j<k;j++)
        {
            if(i<k-1)
            {
                if(i+1==j)
                {
                    T[i][j]=1;
                }
                else
                    T[i][j]=0;
            }
            else
            {
                T[i][j]=c[k-j-1];
            }
        }
    }
    T=pow(T,n-1);
    ll res=0;
    for(ll i=0;i<k;i++)
    {
        res=(res+(T[0][i]*b[i])%mod)%mod;
        // res=res%mod;
    }
    return res%mod;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>k;
        for(ll i=0;i<k;i++)
        {
            ll x;
            cin>>x;
            b.pb(x);
        }
        for(ll i=0;i<k;i++)
        {
            ll x;
            cin>>x;
            c.pb(x);
        }
        cin>>n;
        vector<vector<ll>> T(k,vector<ll>(k));
        ll ans=solve(T,n);
        cout<<ans<<endl;   
        b.clear();
        c.clear();
    }
 return 0;
}
