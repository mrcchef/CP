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
vi depth(N,0);
vi isLeaf(N,0);
vi level(N,0);
ll black,white,mxlevel;

void init()
{
    ll i;
    fo(i,N)
    {
        g[i].clear();
    }

    depth.assign(N,0);
    isLeaf.assign(N,0);
    black=white=0;
    level.assign(N,0);
    mxlevel=0;
}

// col=0 black, col=1 white

void dfs(ll node,ll par,ll dep,ll col)
{
    mxlevel=max(mxlevel,dep);
    if(col==0)
        black++;
    else
        white++;
    depth[node]=dep;
    level[dep]++;
    bool flag=true;
    for(auto val:g[node])
    {
        if(val==par)
            continue;
        flag=false;
        dfs(val,node,dep+1,col^1);
    }

    isLeaf[node]=flag;
}


void solve()
{
    ll n,i,q;
    cin>>n>>q;

    fo(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }    

    dfs(1,0,1,0);
    // debug(g);
    // debug(isLeaf);
    // debug(depth);
    ll cnt=0;
    ll ans;
    if(q==1)
    {
        Fo(i,1,n)
        {
            if(isLeaf[i])
            {
                if(depth[i]&1)
                {
                    // debug(i);
                    cnt++;
                }
            }
        }

        black-=cnt;
        white+=cnt;

        ans=abs(black-white);
    }
    else
    {
        vector<vi> dp(mxlevel+1,vi(2,0));
        vector<vi> blackDp(mxlevel+1,vi(2,0));
        vector<vi> whiteDp(mxlevel+1,vi(2,0));
        dp[1][0]=dp[1][1]=level[1];
        blackDp[1][0]=whiteDp[1][1]=level[1];
        blackDp[1][1]=whiteDp[1][0]=0;
        Fo(i,2,mxlevel)
        {
            debug(i);
            // ll tb=blackDp[i-2][0]+level[i];
            // ll tw=whiteDp[i-2][0]+level[i-1];
            // ll res=abs(tb-tw);
            // dp[i][0]=res;
            // blackDp[i][0]=tb;
            // whiteDp[i][0]=tw;
            // debug(res);
            // debug(mp(tb,tw));
            // tb=blackDp[i-2][1]+level[i];
            // tw=whiteDp[i-2][1]+level[i-1];
            // res=abs(tb-tw);
            // debug(res);
            // debug(mp(tb,tw));
            // if(res<dp[i][0])
            // {
            //     dp[i][0]=res;
            //     blackDp[i][0]=tb;
            //     whiteDp[i][0]=tw;   
            // }

            // tb=blackDp[i-2][0]+level[i-1];
            // tw=whiteDp[i-2][0]+level[i];

            // res=abs(tb-tw);
            // dp[i][1]=res;
            // blackDp[i][1]=tb;
            // whiteDp[i][1]=tw;

            // debug(res);
            // debug(mp(tb,tw));

            // tb=blackDp[i-2][1]+level[i-1];
            // tw=whiteDp[i-2][1]+level[i];

            // res=abs(tb-tw);
            // debug(res);
            // debug(mp(tb,tw));

            // if(res<dp[i][1])
            // {
            //     dp[i][1]=res;
            //     blackDp[i][1]=tb;
            //     whiteDp[i][1]=tw; 
            // }

            ll tb;
            ll tw;

            // black
            ll res=(level[i]+blackDp[i-1][0]-whiteDp[i-1][0]);
            dp[i][0]=res;
            blackDp[i][0]=level[i]+blackDp[i-1][0];
            whiteDp[i][0]=whiteDp[i-1][0];

            tb=level[i]+blackDp[i-1][1];
            tw=whiteDp[i-1][1];
            res=abs(tb-tw);

            if(res<dp[i][0])
            {
                res=dp[i][0];
                blackDp[i][0]=tb;
                whiteDp[i][0]=tw;
            }

            tb=blackDp[i-1][1];
            tw=level[i]+whiteDp[i-1][1];
            res=abs(tb-tw);

            dp[i][1]=res;
            blackDp[i][1]=tb;
            whiteDp[i][1]=tw;
            

            tb=blackDp[i-1][0];
            tw=level[i]+whiteDp[i-1][0];
            res=abs(tb-tw);
            if(res<dp[i][1])
            {
                res=dp[i][1];
                blackDp[i][1]=tb;
                whiteDp[i][1]=tw;
            }

            debug(dp[i]);
        }
        
        ans=min(dp[mxlevel][0],dp[mxlevel][1]);
    }
    // ll ans=abs(black-white);
    // debug(mp(black,white));
    // debug(cnt);
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