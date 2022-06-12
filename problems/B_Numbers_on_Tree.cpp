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
vi c(N);
vi depth(N,0);
bool check=true;

// This is to cal depth of each node 
void dfs(ll node,ll par)
{
    depth[node]=1;
    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;

        dfs(nbr,node);
        depth[node]+=depth[nbr];
    }

    if(depth[node]-1<c[node])
        check=false;
}

// solution is based on divide and conqure 
// below dfs2 will return a vector consisting of node and thier index+1 is the 
// value that we will assign to that node

// for any given node, it can have childrens
// vectors returned by them are independented to each other as 
// they aren't subtree of each other 

// now we can use the vectors returned from the child nodes to construct 
// a vector for current node
// for that we will simply concatinate the vectors returned by them in any order

// let say the c[node]=x i.e. there should exist exactly x elemnets in the 
// subtree of current node, whose values are less than the value of current node
// i.e. we can insert the current node in the xth position 
// reason: as we want exactly x nodes less than the current node and elements inside
// the vectors are the subtree nodes and all the nodes in the left of the xth position
// will have index less than x i.e. the value assigned to them is less than x 
// 

// Using this idea of divide and conqure we can solve the problem in O(N^2)
// O(N) for dfs and O(N) for merging
vi dfs2(ll node,ll par)
{
    vi v;
    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;
        // appending the resulting vectors 
        vi temp=dfs2(nbr,node);
        for(auto val:temp)
            v.push_back(val);
    }

    vi res;
    bool done=false;
    // finding the xth(c[node]th) position and then inserting the current node
    for(ll i=0;i<v.size();i++)
    {
        if(i==c[node])
        {
            done=true;
            res.pb(node);
        }

        res.pb(v[i]);
    }

    if(!done)
        res.pb(node);

    return res;
}

void solve()
{
    ll n,i;
    cin>>n;
    ll root;

    fo(i,n)
    {
        ll x,y;
        cin>>x>>y;

        if(x==0)
            root=i+1;
        else
        {
            g[i+1].pb(x);
            g[x].pb(i+1);
        }
        c[i+1]=y;
    }

    dfs(root,0);

    if(!check)
        cout<<"NO"<<endl;
    else
    {
        vi res=dfs2(root,0);
        vi arr(n+1);
        
        fo(i,n)
        {
            arr[res[i]]=i+1;
        }

        cout<<"YES"<<endl;
        Fo(i,1,n)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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