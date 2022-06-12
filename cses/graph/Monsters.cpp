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

const int N=1005;

vector<vi> dp(N,vi(N,inf));
vector<vector<pii>> parent(N,vector<pii>(N,{inf,inf}));

void multiSourceBfs(vector<string> &vs,int n,int m)
{
    queue<pii> Q;
    vector<vi> visited(n,vi(m,0));

    int i,j;
    fo(i,n)
    {
        fo(j,m)
        {
            if(vs[i][j]=='M')
            {
                Q.push({i,j});
                dp[i][j]=0;
                visited[i][j]=1;
            }
        }
    }

    while(!Q.empty())
    {
        pii ele=Q.front();
        Q.pop();

        for(int k=0;k<4;k++)
        {
            int nx=dx[k]+ele.first;
            int ny=dy[k]+ele.second;

            if(nx<0 || ny<0 || nx==n || ny==m)
                continue;

            dp[nx][ny]=min(dp[nx][ny],dp[ele.first][ele.second]+1);

            if(visited[nx][ny]==1 || vs[nx][ny]=='#')
                continue;
            
            visited[nx][ny]=1;

            Q.push({nx,ny});
        }
    }
}

void bfs(vector<string> vs,int sx,int sy,int n,int m)
{
    queue<pii> Q;
    vector<vi> visited(n,vi(m,0));
    vector<vi> dis(n,vi(m,inf));
    Q.push({sx,sy});
    visited[sx][sy]=1;
    dis[sx][sy]=0;

    

    int flag=0;
    int desx,desy;

    if(sx==0 || sy==0 || sx==n-1 || sy==m-1)
    {
        flag=1;
        desx=sx;
        desy=sy;
    }
    else
    while(!Q.empty())
    {
        pii ele=Q.front();
        Q.pop();

        for(int k=0;k<4;k++)
        {
            int nx=dx[k]+ele.first;
            int ny=dy[k]+ele.second;

            if(nx<0 || ny<0 || nx==n || ny==m)
                continue;

            if(visited[nx][ny]==1 || vs[nx][ny]=='#')
                continue;
            
            
            int tmp=min(dis[nx][ny],dis[ele.first][ele.second]+1);

            if(tmp>=dp[nx][ny])
                continue;
            
            dis[nx][ny]=tmp;
            parent[nx][ny]={ele.first,ele.second};

            visited[nx][ny]=1;

            if(nx==0 || ny==0 || nx==n-1 || ny==m-1)
            {
                flag=1;
                desx=nx;
                desy=ny;
                break;
            }

            Q.push({nx,ny});
        }
    }


    if(!flag)
    {
        cout<<"NO";
        cout<<endl;
        return;
    }

    string path;
    pii p={inf,inf};
    while(parent[desx][desy].first!=inf && parent[desx][desy].second!=inf)
    {   
        int px=parent[desx][desy].first;
        int py=parent[desx][desy].second;

    
        if(px-desx==0)
        {
            if(py-desy==1)
            {
                path+='L';
            }
            else
            {
                path+='R';
            }
        }
        else
        {
            if(px-desx==1)
            {
                path+='U';
            }
            else
            {
                path+='D';
            }
        }

        desx=px;
        desy=py;
    }

    reverse(path.begin(),path.end());

    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    int i;
    vector<string> vs(n);

    fo(i,n)
        cin>>vs[i];

    multiSourceBfs(vs,n,m);

    int j;
    fo(i,n)
    {
        fo(j,m)
        {
            if(vs[i][j]=='A')
            {
                bfs(vs,i,j,n,m);
                break;
            }
        }

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