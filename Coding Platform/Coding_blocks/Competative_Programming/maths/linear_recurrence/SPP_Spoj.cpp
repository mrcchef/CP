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
long long mod = 1e9;

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

ll n,k,m;
vi b(k+1),c(k+1);

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B)
{
    vector<vector<ll>> sol(k+1,vector<ll>(k+1));
    for(ll i=0;i<=k;i++)
    {
        for(ll j=0;j<=k;j++)
        {
            for(ll x=0;x<=k;x++)
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

ll solve(vector<vector<ll>> T)
{
    for(ll i=0;i<=k;i++)
    {
        for(ll j=0;j<=k;j++)
        {
            if(i==0 || i==k)
            {
                if(j==0 && i==0)
                    T[i][j]=1;
                else if(j==0 && i==k)
                    T[i][j]=0;
                else
                {
                    T[i][j]=c[k-j+1];
                }
            }
            else
            {
                if(i+1==j)
                {
                    T[i][j]=1;
                }
                else
                    T[i][j]=0;
            }
        }
    }
    for(ll i=0;i<=k;i++)
    {
        for(ll j=0;j<=k;j++)
            cout<<T[i][j]<<" ";
        cout<<endl;
    }
    vector<vector<ll>> T2=T;
    T=pow(T,n-1);
    ll res1=0,res2=0;
    for(ll i=0;i<=k;i++)
    {
        res1=(res1+(T[0][i]*b[i])%mod)%mod;
        // res=res%mod;
    }
    T2=pow(T2,m-2);
    for(ll i=0;i<=k;i++)
    {
        res2=(res2+(T2[0][i]*b[i])%mod)%mod;
        // res=res%mod;
    }
    return (res2-res1)%mod;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>k;
        b.pb(0);
        c.pb(1); //coefficent of Sum of first k terms
        for(ll i=0;i<k;i++)
        {
            ll x;
            cin>>x;
            deb(x);
            b.pb(x);
        }
        for(ll i=0;i<k;i++)
        {
            ll x;
            cin>>x;
            deb(x);
            c.pb(x);
        }
        ll sum=0;
        for(ll i=1;i<=k;i++)
        {
            sum+=b[i]*c[i];
        }
        // b[0]=sum;
        cin>>m>>n>>mod;
        for(ll i=0;i<=k;i++)
            cout<<b[i]<<" ";
        cout<<endl;
        for(ll i=0;i<=k;i++)
            cout<<c[i]<<" ";
        cout<<endl;
        vector<vector<ll>> T(k+1,vector<ll>(k+1));
        ll ans=solve(T);
        cout<<ans<<endl;   
        b.clear();
        c.clear();
    }
 return 0;
}
