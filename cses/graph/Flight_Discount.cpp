#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define debug(x);
#endif
 
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ull unsigned long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
const ll MOD = 1e9+7;
const ll MOD1= 998244353;
const ll inf=1e18;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

// debugging code
// ---------------------------------------------------------------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// ---------------------------------------------------------------------------------------------------------------------------------

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

void swap(ll &a,ll &b);
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
ll msum(ll a,ll b,ll m);
ll msub(ll a,ll b,ll m);
ll mpro(ll a,ll b,ll m);

const ll N=1e5+5;

// vector<vi> g(N);
// // vector<vi> cost(N,vi(N,-1));
// map<pii,ll> cost;
// vi dist(N,inf);

void dijkstra(vector<vi> &g,map<pii,ll> &cost,vi &dist,ll src)
{
    vi visited(N,0); 
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    
    dist[src]=0;
    pq.push(mp(0,src));

    while(!pq.empty())
    {
        ll ele=pq.top().second;
        pq.pop();

        if(visited[ele]==1)
            continue;
        
        visited[ele]=1;

        for(auto nbr:g[ele])
        {
            if(dist[nbr]>dist[ele]+cost[{ele,nbr}])
            {
                dist[nbr]=dist[ele]+cost[{ele,nbr}];
                pq.push({dist[nbr],nbr});
            }
        }
    }
}

void solve()
{
    ll n,m,i;
    cin>>n>>m;
    vector<vi> g1(N),g2(N);
    vector<ll> dist1(N,inf),dist2(N,inf);
    map<pii,ll> cost1,cost2;
    fo(i,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        // debug(mp(x,y))
        if(cost1[{x,y}]==0)
        {
            g1[x].pb(y);
            cost1[{x,y}]=w;
            g2[y].pb(x);
            cost2[{y,x}]=w;
        }
        else
        {
            cost1[{x,y}]=min(cost1[{x,y}],w);
            cost2[{y,x}]=cost1[{x,y}];
        }
        
    }

    dijkstra(g1,cost1,dist1,1);
    dijkstra(g2,cost2,dist2,n);
    // debug(dist1)
    // debug(dist2)
    ll ans=inf;
    for(auto p:cost1)
    {   
        // debug(p.first);
        // debug(mp(dist1[p.first.first],dist2[p.first.second]));
        ll val=dist1[p.first.first]+(p.second/2)+dist2[p.first.second];
        ans=min(ans,val);
    }

    cout<<ans<<endl;

}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
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
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}
ll msum(ll a,ll b,ll m) { return ((a%m+b%m)+m)%m; }
ll msub(ll a,ll b,ll m) { return ((a%m-b%m)+m)%m; }
ll mpro(ll a,ll b,ll m) { return (((a%m)*(b%m)+m))%m; }