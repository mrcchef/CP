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
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll fact(ll n,ll m)
{
    ll res=1;
    for(ll i=n;i>1;i--)
    {
        res=(res*(i%m))%m;
    }
    return res;
}

// fermat's little therorem is very useful when you need to calculate modular inverse of a w.r.t p where p is prime number

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,r,p=1,k=1;
    cin>>n>>r;
    r=min(r,n-r);
    if(r!=0)
    {
        ll nf=fact(n,mod),rf=fact(r,mod),nmrf=fact(n-r,mod);
        ll rfi=fxp(rf,mod-2,mod)%mod;
        ll nmrfi=fxp(nmrf,mod-2,mod)%mod;
        p=((nf*rfi%mod)*(nmrfi))%mod;

    }
    else
    {
        p=1;
    }
    cout<<p<<endl;
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
}
ll m_m(ll a,ll b,ll m) 
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            res+=a; 
            res=res%m;
        }
        a=(a*2)%m;
        b=b/2;
    }
    return res;
}