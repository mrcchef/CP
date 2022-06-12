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

ll getDist(ll x1,ll y1,ll x2,ll y2,ll r)
{

    ll t1=abs((x1-x2));
    ll t2=abs((y1-y2));
    lld val=(t1)*(t1)+t2*t2;
  
    if(t1!=0)
        t1++;
    
    if(t2!=0)
        t2++;
    lld sval=sqrt(val);
    lld tr=r;

    if(sval<=tr)
        return true;
    
        return false;
}

void updateGrid(ll n,ll m,ll x,ll y,ll r,vector<vi> &grid)
{
    ll i,j,k;
    for ( i = 1; i <= n; i++) 
    {
        for ( j = 1; j <= m; j++)
        {
            if(getDist(i,j,x,y,r))
            {
                // debug(mp(i,j));
                grid[i][j]=0;
            }    
        }
    }
}

bool check(ll x,ll y,ll n,ll m)
{
    return (x>0 && y>0 && x<=n&& y<=m);
}

void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<vi> grid(n+1,vi(m+1,1));

    ll k;
    cin>>k;

    ll i;
    fo(i,k)
    {
        ll x,y,r;
        cin>>x>>y>>r;
        // debug(mp(x,y));
        updateGrid(n,m,x,y,r,grid);
    }

    queue<pii> q;
    q.push({1,1});
    if(grid[1][1]==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    grid[1][1]=2;

    // Fo(i,1,n)
    // {
    //     debug(grid[i]);
    // }

    while(!q.empty())
    {
        pii p=q.front();
        q.pop();
        ll x,y;
        x=p.first;
        y=p.second;
        
        fo(i,4)
        {
            ll nx,ny;
            nx=dx[i]+x;
            ny=dy[i]+y;
            if(check(nx,ny,n,m) && grid[nx][ny]==1)
            {
                grid[nx][ny]=2;
                q.push({nx,ny});
            }
        }
    }

    if(grid[n][m]==2)
    {
        cout<<"YES";
    }
    else
        cout<<"NO";
    cout<<endl;
    // return 

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