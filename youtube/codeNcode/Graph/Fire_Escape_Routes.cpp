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

ll timse;

void dfs(ll cur,vector<vi> &g,ll visited[],ll in[],ll out[])
{
    visited[cur]=1;
    in[cur]=timse++;
    for(auto node:g[cur])
    {
        if(visited[node]==0)
        {
            dfs(node,g,visited,in,out);
        }
    }
    out[cur]=timse++;
}

void solve()
{
    ll n,e,i;
    cin>>n>>e;
    vector<vi> g(n+1);
    ll visited[n+1]={0};

    fo(i,e)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    ll cnt=0,ans=1;
    ll in[n+1]={0};
    ll out[n+1]={0};
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            timse=1;
            cnt++;
            dfs(i,g,visited,in,out);
            ans=(ans*((out[i]-in[i]+1)/2))%mod;
        }
    }
    // for(i=1;i<=n;i++)
    // {
    //     deb(i);
    //     cout<<in[i]<<" "<<out[i]<<endl;
    // }
    cout<<cnt<<" "<<ans<<endl;
}

int main()
{
    fastio
    int t;
    cin>>t;
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