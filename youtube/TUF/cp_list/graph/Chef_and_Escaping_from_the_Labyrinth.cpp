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

const ll N=5;




void solve()
{
    ll n,m,i,j;
    cin>>n>>m;
    // queue<data> q;
    priority_queue<pair<ll,pii>> pq;
    vector<vi> g(n,vi(m));
    vector<vector<char>> res(n,vector<char>(m,'N'));
    vector<vi> visited(n,vi(m,0));
    fo(i,n)
    {
        fo(j,m)
        {
            cin>>g[i][j];
            if(g[i][j]>0)
            {
                // data d;
                // d.i=i;
                // d.j=j;
                // d.val=g[i][j];
                // q.push(d);
                pq.push({g[i][j],{i,j}});
                visited[i][j]=2;
                res[i][j]='Y';
            }
            else if(g[i][j]==-1)
            {
                res[i][j]='B';
            }
        }
    }

    while(!pq.empty())
    {
        pair<ll,pii> d=pq.top();
        pq.pop();
        ll w=d.first;
        ll x=d.second.first;
        ll y=d.second.second;
        visited[x][y]=1;
        // debug(res)
        // debug(w);
        ll k;
        fo(k,4)
        {
            ll nx,ny;
            nx=dx[k]+x;
            ny=dy[k]+y;

            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;

            if(visited[nx][ny]==1)
                continue; 

            visited[nx][ny]=1;
            
            if(g[nx][ny]==-1)
            {
                res[nx][ny]='B';
            }
            else
            {
                if(w-1>=0)
                {
                    res[nx][ny]='Y';
                    pq.push({w-1,{nx,ny}});
                }
                else
                    res[nx][ny]='N';
                // if(w-1>0)
            }
        }
    }

    vector<string> ans(n);
    fo(i,n)
    {
        fo(j,m)
        {
            ans[i]+=res[i][j];
            // cout<<res[i][j];
        }
        // cout<<endl;
    }

    fo(i,n)
        cout<<ans[i]<<endl;


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
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
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