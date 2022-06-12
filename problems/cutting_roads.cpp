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

struct data{
    ll x,y;
    ll degree;

    // data()
    // {}

    // data(ll _x,ll _y,ll _degree)
    // {
    //     x=_x;
    //     y=_y;
    //     degree=_degree;
    // }

    static bool operator<(const data &d)
    {
        return this->degree>d.degree;
    }
};

// static bool compare(data &d1,data &d2)
// {
//     return d1.degree>d2.degree;
// }

bool check(ll x,ll y,ll n,ll m)
{
    return (x>=0 && x<n && y>=0 && y<m);
}

ll getDegree(ll x,ll y,ll n,ll m,vector<string> &vs)
{

    int deg=0;
    for(int i=0;i<4;i++)
    {
        ll nx=dx[i]+x;
        ll ny=dy[i]+y;

        if(!check(nx,ny,n,m))
            continue;
        deg++;
    }

    return deg;
}

bool isConnected(vector<string> &vs,ll n,ll m)
{
    pii stNode={-1,-1};
    ll i,j;

    fo(i,n)
    {
        fo(j,m)
        {
            if(vs[i][j]=='#')
            {
                stNode={i,j};
                
                break;
            }
        }

        if(stNode.first!=-1 && stNode.second!=-1)
            break;
    }

    vector<vi> vis(n,vi(m,0));
    queue<pii> q;

    q.push({i,j});
    vis[i][j]=1;

    while(!q.empty())
    {
        pii p=q.front();
        q.pop();

        ll x=p.first;
        ll y=p.second;

        for(i=0;i<4;i++)
        {
            ll nx=dx[i]+x;
            ll ny=dy[i]+y;

            if(!check(nx,ny,n,m))
                continue;

            vis[nx][ny]=1;
            if(vs[nx][ny]=='#')
            {
                q.push({nx,ny});
            }
        }
    }

    fo(i,n)
    {
        fo(j,m)
        {
            if(vs[i][j]=='#' && vis[i][j]==0)
                return false;
        }
    }

    return true;

    
}

void solve()
{
    ll n,m,i,j;
    cin>>n>>m;

    vector<string> vs(n);

    fo(i,n)
        cin>>vs[i];

    map<pii,ll> hm;

    set<data> pq;
    fo(i,n)
    {
        fo(j,m)
        {
            if(vs[i][j]=='.')
                continue;
            hm[{i,j}]=getDegree(i,j,n,m,vs);
            data d;
            d.x=i;
            d.y=j;
            d.degree=hm[{i,j}];
            // pq.insert(data(i,j,hm[{i,j}]));
            pq.insert(d);
        }
    }
    
    // priority_queue<data,vector<data>,compare> pq;

    int cnt=0;

    while(isConnected(vs,n,m))
    {
        auto it=pq.begin();
        data node=*it;
        pq.erase(it);
        ll x=node.x;
        ll y=node.y;
        ll degree=node.degree;

        for(i=0;i<4;i++)
        {
            ll nx=dx[i]+x;
            ll ny=dy[i]+y;

            if(!check(nx,ny,n,m))
            {
                continue;
            }

            if(vs[nx][ny]=='#')
            {
                data d1;
                d1.x=nx;
                d1.y=ny;
                d1.degree=hm[{nx,ny}];

                pq.erase(d1);
                // pq.erase(data(nx,ny,hm[{nx,ny}]));
                hm[{nx,ny}]--;
                d1.degree=hm[{nx,ny}];
                pq.insert(d1);
                // pq.insert(data(nx,ny,hm[{nx,ny}]));
            }
        }  
    }

    cout<<cnt<<endl;

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