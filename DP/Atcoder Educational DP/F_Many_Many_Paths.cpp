#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
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
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

const int N=2e6+5;
#define PRIME mod

ll fact[N],invfact[N];
void init(){
    ll p=PRIME;
    fact[0]=1;
    ll i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=fxp(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}

ll ncr(ll n,ll r)
{
    if(n<0 || r<0 || n<r) 
        return 0;
    return fact[n]*invfact[n-r]%PRIME*invfact[r]%PRIME;
}

ll nCr(ll n,ll r)
{
    if(n<0 || r<0 || n<r) 
        return 0;   
}


void solve()
{
    ll r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    ll ans=0;
    for(ll i=r1;i<=r2;i++)
    {
        ll st=i+c1;
        ll ed=i+c2;
        // cout<<st<<" "<<ed<<endl;
        // ll fr=0,sd=0;
        // if(st>N)
            
        ll val=ncr(ed+1,i+1)-ncr(st,i+1);
        ans+=((val+mod)%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
}

int main()
{
    fastio
    int t=1;
    // cin>>t;
    init();
    while(t--)
    {
        solve();   
    }
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