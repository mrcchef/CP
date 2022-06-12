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

const ll N=2e4+5; 

vi parent(N);
vi depth(N);

void init()
{
    parent.assign(N,-1);
    depth.assign(N,1);
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
    ll n,i;
    cin>>n;
    
    vector<pii> edges(n-1); 
    fo(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        edges[i]={x,y};
    }

    ll q;
    cin>>q;
    vector<vector<string>> queries(q);

    mii hm;

    fo(i,q)
    {
        string ch;
        cin>>ch;
        queries[i].pb(ch);
        
        if(ch=="R")
        {
            string num;
            cin>>num;
            
            hm[stoll(num)]=1;
            
            queries[i].pb(num);
        }
    }

    Fo(i,1,n-1)
    {
        if(hm[i]==1)
            continue;

        mergeSet(edges[i-1].first,edges[i-1].second);
    }

    vi ans;

    ll connectedPairs=0;

    Fo(i,1,n)
    {
        if(getParent(i)==i)
        {
            connectedPairs+=(depth[i]*(depth[i]-1))/2;
        }
    }

    ll disconnetedPair=(n*(n-1))/2-connectedPairs;

    for(i=q-1;i>=0;i--)
    {
        if(queries[i].size()==1)
        {
            ans.pb(disconnetedPair);
        }
        else
        {
            ll  edgeIndex=stoll(queries[i][1]);
            
            ll n1=edges[edgeIndex-1].first;
            ll n2=edges[edgeIndex-1].second;

            ll contri=depth[getParent(n1)]*depth[getParent(n2)];
            ll isMerged=mergeSet(n1,n2);
            if(isMerged)
            {
                disconnetedPair-=contri;
            }
        }
    }

    while(!ans.empty())
    {
        cout<<ans.back()<<endl;
        ans.pop_back();
    }

    cout<<endl;
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
        init();
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