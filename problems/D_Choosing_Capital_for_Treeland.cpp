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

const ll N=2e5+5;

vector<vi> g(N),invG(N);
vector<pii> res;
ll minInv=inf;
vi dp(N,0),arrInv(N);

// rerooting problem 
void dfs(ll node,ll par)
{
    ll inv=0;

    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;
        dfs(nbr,node);
        inv+=dp[nbr];
    }

    for(auto nbr:invG[node])
    {
        if(nbr==par)
            continue;
        dfs(nbr,node);
        inv+=dp[nbr]+1;
    }

    dp[node]=inv;
}

// type==1 
// reached to node with forward edge
void dfs2(ll node,ll par,ll type)
{
    ll inv=0;
    ll childContribution=0;
    
    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;
        childContribution+=dp[nbr];
    }
    
    for(auto nbr:invG[node])
    {
        if(nbr==par)
            continue;
        childContribution+=dp[nbr]+1;
    }
    
    inv+=childContribution;
    if(par!=0)
    {
        ll parentContribution=arrInv[par]-dp[node];
        
        // modification done according to the changes done while rerooting
        if(type==0)
            inv-=1;
        else
            inv+=1;
        inv+=parentContribution;
    }
    
    res.pb({inv,node});
    minInv=min(minInv,inv);
    arrInv[node]=inv;

    for(auto nbr:g[node])
        if(nbr!=par)
            dfs2(nbr,node,1);
    
    for(auto nbr:invG[node])
        if(nbr!=par)
            dfs2(nbr,node,0);
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
        invG[y].pb(x);
    }


    dfs(1,0);

    dfs2(1,0,0);

    vi nodes;

    for(auto val:res)
    {
        if(val.first==minInv)
            nodes.pb(val.second);
    }

    sort(all(nodes));

    cout<<minInv<<endl;
    for(auto val:nodes)
        cout<<val<<" ";
    cout<<endl;

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