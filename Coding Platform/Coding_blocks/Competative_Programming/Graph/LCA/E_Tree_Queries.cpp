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

vector<vi> g(N);

vi level(N);
ll mx=20;
vector<vi> up(N,vi(mx));

void binary_lifting(ll node,ll par,ll lvl)
{
    up[node][0]=par;
    level[node]=lvl;

    for(ll i=1;i<mx;i++)
    {
        if(up[node][i-1]==-1)
            up[node][i]=-1;
        else
            up[node][i]=up[up[node][i-1]][i-1];
    }

    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;
        binary_lifting(nbr,node,lvl+1);
    }
}


ll up_lift(ll node,ll lvl)
{
    ll des=node;

    for(ll i=mx-1;i>=0;i--)
    {
        if(node==-1 || lvl==0)
            return node;

        if(lvl>=(1<<i))
        {
            node=up[node][i];
            lvl-=(1<<i);
        }
    }

    return node;
}

ll getLca(ll node1,ll node2)
{
    if(level[node1]>level[node2])
    {
        swap(node1,node2);
    }

    node2=up_lift(node2,level[node2]-level[node1]);

    if(node2==node1)
        return node1;

    for(ll i=mx-1;i>=0;i--)
    {
        if(up[node1][i]!=up[node2][i])
        {
            node1=up[node1][i];
            node2=up[node2][i];
        }
    }

    return up[node1][0];
}

bool compare(ll &node1,ll &node2)
{
    return level[node1]>level[node2];
}

void solve()
{
    ll n,q;
    cin>>n>>q;

    ll i;

    fo(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    binary_lifting(1,-1,1);

    fo(i,q)
    {
        ll sz;
        cin>>sz;
        vi v(sz);

        ll j;
        for(j=0;j<sz;j++)
        {
            cin>>v[j];
        }

        sort(all(v),compare);

        bool flag=true;
        for(j=1;j<sz;j++)
        {
            ll node1=v[j-1];
            ll node2=v[j];

            ll lca=getLca(node1,node2);

            if(level[node2]-level[lca]>1)
            {
                flag=false;
                break;
            }
        }

        if(flag)
        {
            cout<<"YES";
        }
        else
            cout<<"NO";
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