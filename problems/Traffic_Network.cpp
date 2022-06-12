//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/
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

vector<vector<pii>> g1(N),g2(N);

vector<vi> dist(N,vi(2,inf));

void init()
{
    ll i;
    fo(i,N)
    {
        g1[i].clear();
        g2[i].clear();
    }

    dist.assign(N,vi(2,inf));
}

void solve()
{
    init();
    ll n,m,k,src,des,i;
    cin>>n>>m>>k>>src>>des;

    fo(i,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        g1[x].pb({y,w});
    }

    fo(i,k)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        g2[x].pb({y,w});
        g2[y].pb({x,w});
    }

    priority_queue<vi,vector<vi>,greater<vi>> pq; 
    pq.push({0,src,0}); // wie,node,isUsed

    dist[src][0]=0;

    while(!pq.empty())
    {
        vi p=pq.top();
        pq.pop();

        ll wie=p[0];
        ll u=p[1];
        ll isUsed=p[2];

        // debug(p);

        if(dist[u][isUsed]<wie) 
            continue;
        
        for(auto nbr:g1[u])
        {
            ll v=nbr.first;
            ll w=nbr.second;

            if(dist[v][isUsed]>dist[u][isUsed]+w)
            {
                dist[v][isUsed]=dist[u][isUsed]+w;
                pq.push({dist[v][isUsed],v,isUsed});
            }
        }

        if(!isUsed)
        {
            for(auto nbr:g2[u])
            {
                ll v=nbr.first;
                ll w=nbr.second;
                
                if(dist[v][1]>dist[u][0]+w)
                {
                    dist[v][1]=dist[u][0]+w;
                    pq.push({dist[v][1],v,1});
                }
            }
        }
    }

    ll ans=min(dist[des][0],dist[des][1]);

    if(ans==inf)
        ans=-1;

    cout<<ans<<endl;
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
         freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
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
        return fxp((a*a)%m,b/2,m);
    return (fxp(a,b-1,m)*a)%m;
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