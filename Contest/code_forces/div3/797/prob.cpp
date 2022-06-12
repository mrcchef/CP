//LinkedIn:https://www.linkedin.com/in/abhijeettamrakar/
//GitHub:https://github.com/mrcchef/
#include <bits/stdc++.h>

// policy based data structure 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
// find_by_order : finding ith element, order_of_key : number of element smaller than key

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

class DSU{
    public:
    ll n;
    vi parent;
    vi rank;
    
    DSU(ll n)
    {
        this->n=n;
        parent=vi(n+1,-1);
        rank=vi(n+1,1);
    }

    ll getParent(ll node)
    {
        if(parent[node]==-1)
            return node;
        return parent[node]=getParent(parent[node]);
    }

    bool isCyclePresent(ll node1,ll node2)
    {
        ll par1=getParent(node1);
        ll par2=getParent(node2);

        return par1==par2;
    }

    bool mergeSet(ll node1,ll node2)
    {
        ll par1=getParent(node1);
        ll par2=getParent(node2);

        if(par1==par2)
            return false;
        
        if(rank[par1]<rank[par2])
        {
            parent[par1]=par2;
            rank[par2]+=rank[par1];
        }
        else
        {
            parent[par2]=par1;
            rank[par1]+=rank[par2];
        }

        return true;
    }
};

int N;
vector<int> parent;
// vector<int> rank;
vector<int> nodeVal;
vector<int> mxNodeVal;

void init(int A,vector<int> &C)
{
    N=A;
    parent.assign(N,-1);
    // rank.assign(N,1);
    mxNodeVal=nodeVal=C;
}

int getParent(int node)
{
    if(parent[node]==-1)
        return node;
    
    return parent[node]=getParent(parent[node]);
}

bool mergeSet(int node1,int node2)
{
    int par1=getParent(node1);
    int par2=getParent(node2);
    debug(mp(node1,par1));
    debug(mp(node2,par2));
    if(par1==par2)
        return false;
        
    int newVal=nodeVal[par1]+nodeVal[par2];
    
    mxNodeVal[par1]=max(mxNodeVal[par1],newVal);
    debug(newVal);
    if(newVal<0)
        return false;
        
    nodeVal[par1]=newVal;
    parent[par2]=par1;

    return true;
}



void solve(int A, vector<vector<int> > &B, vector<int> &C) {

    init(A,C);
    
    vector<vector<pair<int,int>>> g(A);
    
    int i;
    for(i=0;i<B.size();i++)
    {
        int x=B[i][0];
        int y=B[i][1];
        g[x].push_back({C[y],y});
        g[y].push_back({C[x],x});
                
    }
    
    vector<pair<int,int>> vp(A);
    
    for(i=0;i<A;i++)
    {
        vp[i]={C[i],i};
    }
    
    sort(vp.begin(),vp.end(),greater<pair<int,int>>());
    
    for(int i=0;i<A;i++)
    {
        sort(g[i].begin(),g[i].end(),greater<pair<int,int>>());
    }
    
    for(i=0;i<A;i++)
    {
        int node=vp[i].second;
        for(int j=0;j<g[node].size();j++)
        {
            int nbr=g[node][j].second;
            mergeSet(node,nbr);
        }
    }
    
    int ans=-1e9;
    
    debug(mxNodeVal);
    for(i=0;i<A;i++)
    {
        // cout<<mxNodeVal[i]<<" ";
        ans=max(ans,mxNodeVal[i]);
    }
    
    debug(ans);
    // return ans;
}


int main()
{
    fastio
    #ifdef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
    int t=1;
    // cin>>t;
    while(t--)
    {
        int A=4;
        vector<vector<int>> B={{0,1},{0,2},{0,3},{1,3}};
        vector<int> C={35,-48,21,45};
        solve(A,B,C);   
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
