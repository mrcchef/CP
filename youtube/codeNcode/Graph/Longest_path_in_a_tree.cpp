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

const ll N=1e5+5;

vector<vi> g(N);
ll visited[N];
ll node1,node2;
ll dis1=INT_MIN,dis2=INT_MIN;

ll tmx=INT_MIN;

void dfs(ll cur,ll dep)
{
    visited[cur]=1;
    if(dep>tmx)
    {
        tmx=dep;
        dis1=tmx;
        node1=cur;
    }
    for(auto node:g[cur])
    {
        if(visited[node]==0)
        {
            dfs(node,dep+1);
        }
    }
}

void dfs2(ll cur,ll dep)
{
    // deb(cur);
    visited[cur]=1;
    if(dep>tmx)
    {
        tmx=dep;
        node2=cur;
        dis2=tmx;
    }
    
    for(auto node:g[cur])
    {
        if(visited[node]==0)
            dfs2(node,dep+1);
    }
}


void init()
{
    tmx=INT_MIN;
    for(int i=0;i<N;i++)
        visited[i]=false;
}

void solve()
{
    ll n,i;
    cin>>n;
    fo(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    init();
    dfs(1,0);
    init();
    // for(int i=1;i<=n;i++)
    //     cout<<visited[i]<<" ";
    // deb(node1);
    dfs2(node1,0);
    cout<<dis2<<endl;

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