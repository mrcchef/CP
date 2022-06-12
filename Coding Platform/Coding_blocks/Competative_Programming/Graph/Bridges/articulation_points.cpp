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

vector<vi> g(N);

vi inTime(N);
vi lowestInTime(N,inf);
vi visited(N,0);
ll timer=0;

set<ll> articulationPoints;

void calArticulationPoints(ll node,ll par)
{
    timer++;
    visited[node]=1;
    inTime[node]=timer;
    lowestInTime[node]=timer;
    ll branches=0;

    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;
        
        if(visited[nbr])
        {
            lowestInTime[node]=min(lowestInTime[node],inTime[nbr]);
            continue;
        }

        branches++;

        calArticulationPoints(nbr,node);
        lowestInTime[node]=min(lowestInTime[node],lowestInTime[nbr]);

        // check inTime[node]<=lowestInTime[nbr]
        // simply check whether the nbrs of node can reach
        // anchestors node
        // if yes then node can not be the articulation point as removing
        // it does not break the graph b/c nbr can reach the anchestor of node

        // if nbr can not then the nbrs depends upon current node
        // to reach the anchestors of node, in that case 
        // removing the current node will disconnects the graph

        // This condition is only valid for non root nodes 
        // as root node always has the smallest inTime value
        // then root will always be a articulation point but
        // that's not true. 
        // eg: 1->2->3->1 
        // let say 1 is root then 1 is not a articulation point  
        if(par!=0 && inTime[node]<=lowestInTime[nbr])
        {
            // A node can be inserted multiple times 
            // that's why we are storing in a set
            articulationPoints.insert(node);
        }
    }

    // this is to check root is a articulation point
    // and any root is a articulation point if it alteast who
    // dfs call i.e. two branches 
    if(par==0 && branches>1)
        articulationPoints.insert(node);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    ll i;
    fo(i,m)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    Fo(i,1,n)
    {
        if(!visited[i])
            calArticulationPoints(i,0);
    }

    for(auto val:articulationPoints)
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