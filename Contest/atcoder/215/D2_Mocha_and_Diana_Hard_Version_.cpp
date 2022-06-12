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
#define ll int
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
// const ll inf=1e18;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

// // debugging code
// // ---------------------------------------------------------------------------------------------------------------------------------
// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// // ---------------------------------------------------------------------------------------------------------------------------------

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

void swap(ll &a,ll &b);
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
ll msum(ll a,ll b,ll m);
ll msub(ll a,ll b,ll m);
ll mpro(ll a,ll b,ll m);

// const ll N=1e5+5;

ll find_set(ll i,vi &parent)
{
    if(parent[i]==-1)
        return i;
    return parent[i]=find_set(parent[i],parent);
}

bool union_set(ll i,ll j,vi &parent,vi &rank)
{
    ll s1=find_set(i,parent);
    ll s2=find_set(j,parent);
    if(s1!=s2)
    { 
        if(rank[i]<rank[j])
        {
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }
        else
        {
            parent[s2]=s1;
            rank[s1]+=rank[s2];
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool isCyclePresent(ll i,ll j,vi &parent)
{
    ll s1=find_set(i,parent);
    ll s2=find_set(j,parent);

    return s1==s2;
}

void solve()
{
    ll n,m1,m2,i;
    cin>>n>>m1>>m2;

    vector<ll> p1(n+1,-1),p2(n+1,-1);
    vector<ll> r1(n+1,1),r2(n+1,1);

    if(m1==m2 && m1==0)
    {
        cout<<n-1<<endl;
        for(i=1;i<n;i++)
            cout<<i<<" "<<i+1<<endl;
        return;
    }

    fo(i,m1)
    {
        ll x,y;
        cin>>x>>y;

        union_set(x,y,p1,r1);
    }

    fo(i,m2)
    {
        ll x,y;
        cin>>x>>y;
        union_set(x,y,p2,r2);
    }


    vector<pii> res;
    ll j;

    Fo(j,2,n)
    {
        ll isCycle1=isCyclePresent(1,j,p1);
        ll isCycle2=isCyclePresent(1,j,p2);
        if(!isCycle1 && !isCycle2)
        {
            union_set(1,j,p1,r1);
            union_set(1,j,p2,r2);
            res.pb({1,j});

        } 
    }

    ll node1=1,node2=1;    
    vector<bool> vis(n+1);

    vis[1]=1;

    while(node1<=n && node2<=n)
    {
        while(node1<=n && (isCyclePresent(i,node1,p1)|| vis[find_set(node1,p1)])) node1++;

        while(node2<=n && (isCyclePresent(i,node2,p2) || vis[find_set(node2,p2)])) node2++;

        if(node1>n || node2>n)
        {
            break;
        }

        union_set(node1,node2,p1,r1);
        union_set(node1,node2,p2,r2);

        vis[find_set(node1,p1)]=vis[find_set(node2,p2)]=1;

        res.pb({node1,node2});

    }

    cout<<res.size()<<endl;
    for(auto val:res)
        cout<<val.first<<" "<<val.second<<endl;
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