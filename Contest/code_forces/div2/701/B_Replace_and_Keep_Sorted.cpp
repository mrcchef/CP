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

void solve()
{
    ll n,q,k;
    cin>>n>>q>>k;
    ll i;
    vi v(n);
    fo(i,n)
    {
        cin>>v[i];
    }
    ll sm[n+1]={0};
    if(n>1)
    fo(i,n)
    {
        ll val;
        if(i==0)
        {
            val=v[i+1]-2;
        }
        else if(i==n-1)
        {
            val=k-v[i-1]-1;
        }
        else
        {
            val=v[i+1]-v[i-1]-1-1;
        }
        // deb(i);
        // deb(val);
        
        sm[i+1]=val+sm[i];
        // deb(sm[i+1])
    }
    // fo(i,n+1)
    //     cout<<sm[i]<<" ";
    // cout<<endl;

    ll cnt=0;
    fo(i,q)
    {
        ll x,y;
        cin>>x>>y;
        ll ans;
        if(n==1)
        {
            ans=k-1;
        }
        else
        {
        ans=sm[y-1]-sm[x];
        ans+=v[x]-1-1;
        // cout<<v[x]-1-1<<endl;
        ans+=k-v[y-2]-1;

        }
        // cout<<k-v[y-2]-1<<endl;
        cout<<ans<<endl;
    }
}

int main()
{
    fastio
    int t=1;
    // cin>>t;
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