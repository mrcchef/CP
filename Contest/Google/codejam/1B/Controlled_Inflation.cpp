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

int tc;

void printG(ll val)
{
    cout<<"Case #"<<tc<<": "<<val<<endl;
}

ll helper(ll i,ll prev,vector<vi> &v,ll n,ll sz)
{
    if(i==n)
        return 0;
    
    ll ans=inf;

    do {
        ll cost=0;
        ll tprev=prev;
        for(ll j=0;j<sz;j++)
        {
            cost+=abs(tprev-v[i][j]);
            tprev=v[i][j];
        }
        ll help=helper(i+1,v[i][sz-1],v,n,sz);
        ans=min(ans,cost+help);
    } while (next_permutation(v[i].begin(),v[i].end()));

    return ans;
}

void solve()
{
    ll n,k,i,j;
    cin>>n>>k;

    vector<vi> v(n,vi(k));

    vi mnV(n);
    vi mxV(n);

    fo(i,n)
    {
        ll mn=inf;
        ll mx=-inf;
        fo(j,k)
        {
            cin>>v[i][j];
            mn=min(mn,v[i][j]);
            mx=max(mx,v[i][j]);
        }

        mnV[i]=mn;
        mxV[i]=mx;
    }

    vector<vi> dp(n,vi(2,0));

    dp[0][0]=mxV[0];
    dp[0][1]=mxV[0]+(mxV[0]-mnV[0]);
    debug(mp(dp[0][0],dp[0][1]));
    for(i=1;i<n;i++)
    {
        ll fixScore=mxV[i]-mnV[i];
        dp[i][0]=min(dp[i-1][0]+abs(mxV[i-1]-mnV[i]),dp[i-1][1]+abs(mnV[i-1]-mnV[i]))+fixScore;
        dp[i][1]=min(dp[i-1][0]+abs(mxV[i-1]-mxV[i]),dp[i-1][1]+abs(mnV[i-1]-mxV[i]))+fixScore;

        debug(mp(dp[i][0],dp[i][1]));
    } 
    // ll ans=helper(0,0,v,n,k);

    ll ans=min(dp[n-1][0],dp[n-1][1]);

    printG(ans);
}

int main()
{
    fastio
    #ifdef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
    int t;
    cin>>t;
    tc=0;
    while(tc<t)
    {
        tc++;
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