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

const ll N=2e3+5;
const ll M=2e5+5;


struct edge{
    int id;
    int w;
    int u,v;
};

vi parent(N);
vi depth(N);
vector<vi> edge_id(N,vi(N,0));
list<pii>:: iterator edge_it[M];
vi state(M,0);
vector<edge> edges(M);
vector<edge> tedges; 
vector<edge> idToEdge(M);

void init()
{
    parent.assign(N,-1);
    depth.assign(N,1);
}

bool compare(edge &e1,edge &e2)
{
    return e1.w<e2.w;
}

ll getParent(ll node)
{
    if(parent[node]==-1)
        return node;
    
    return parent[node]=getParent(parent[node]);
}

ll mergeSet(ll node1,ll node2)
{
    ll par1=getParent(node1);
    ll par2=getParent(node2);

    if(par1==par2)
        return 0;
    
    if(depth[par1]<depth[par2])
    {
        parent[par1]=par2;
        depth[par2]+=depth[par1];
    }
    else
    {
        parent[par2]=par1;
        depth[par1]+=depth[par2];
    }    

    return 1;
}

void solve()
{
    ll n,m,q,i;
    cin>>n>>m>>q;

    fo(i,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        if(x>y)
            swap(x,y);

        edge e;
        e.u=x;
        e.v=y;
        e.id=i+1;
        e.w=w;

        edges[i]=e;
        tedges.pb(e);
        edge_id[x][y]=i;
    }    

    init();

    sort(all(tedges),compare);
    
    list<pii> mstEdges;
    ll mst=0;

    fo(i,m)
    {
        if(mergeSet(tedges[i].u,tedges[i].v))
        {
            mstEdges.push_back({tedges[i].w,tedges[i].id});
            mst+=tedges[i].w;
        }

        if(mstEdges.size()==n-1)
            break;
    }

    // debug(mst);

    bool recalculateMst=false;

    fo(i,q)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll u,v;
            cin>>u>>v;
            
            if(u>v)
                swap(u,v);
            
            ll eid=edge_id[u][v];

            if(state[eid]==0)
            {
                mstEdges.push_front({0,eid});
                edge_it[eid]=mstEdges.begin();
                state[eid]=1;
                recalculateMst=true;
            }
        }
        else if(type==2)
        {
            ll u,v;
            cin>>u>>v;
            
            if(u>v)
                swap(u,v);
            
            ll eid=edge_id[u][v];

            if(state[eid]==1)
            {
                mstEdges.erase(edge_it[eid]);
                state[eid]=0;
                recalculateMst=true;
            }
        }
        else
        {
            if(recalculateMst)
            {
                mst=0;
                init();
                ll cnt=0;
                for(auto it=mstEdges.begin();it!=mstEdges.end() && cnt<n-1;it++)
                {
                    ll eid=it->second;
                    ll w=it->first;
                    ll u=edges[eid].u;
                    ll v=edges[eid].v;

                    if(mergeSet(u,v))
                    {
                        cnt++;
                        mst+=w;
                    }
                }

                recalculateMst=false;
            }

            cout<<mst<<endl;
        }
    }
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