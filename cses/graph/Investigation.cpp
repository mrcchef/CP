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

vector<vector<pii>> g(N);

vi dist(N,inf);
vi minPath(N,0);
vi mxFlight(N,0);
vi mnFlight(N,0);


void dijkstra(ll src)
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,src});
    minPath[src]=1;
    dist[src]=0;
    mnFlight[src]=1;
    mxFlight[src]=1;
    while(!pq.empty())
    {
        pii p=pq.top();
        pq.pop();

        ll node=p.second;
        ll wie=p.first;

        if(wie>dist[node])
            continue;

        for(auto nbr:g[node])
        {
            ll dest=nbr.first;
            ll cost=nbr.second;

            debug(dest);
            if(dist[dest]>dist[node]+cost)
            {
                debug("relax");    
                dist[dest]=dist[node]+cost;
                pq.push({dist[dest],dest});
                minPath[dest]=minPath[node];
                mxFlight[dest]=mxFlight[node]+1;
                mnFlight[dest]=mnFlight[node]+1; 
            }
            else if(dist[dest]==(dist[node]+cost))
            {
                debug("equal");
                minPath[dest]+=minPath[node];
                minPath[dest]%=MOD;
                mxFlight[dest]=max(mxFlight[node]+1,mxFlight[dest]);
                mnFlight[dest]=min(mnFlight[dest],mnFlight[node]+1);
            }
        }
    }
}

void solve()
{
    ll n,m,i,j;
    cin>>n>>m;
    fo(i,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});
    }    

    dijkstra(1);

    cout<<dist[n]<<" "<<minPath[n]<<" "<<mnFlight[n]-1<<" "<<mxFlight[n]-1<<endl;

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