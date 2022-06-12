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

vector<string> vs;
ll n,m;

struct data{
    ll i,j;
    ll cnt;

    data(ll i,ll j)
    {
        this->i=i;
        this->j=j;
        cnt=0;
    }
};


string findChar(ll i,ll j,ll px,ll py)
{
    if(py-j==-1)
        return "R";
    else if(py-j==1)
        return "L";
    else if(px-i==-1)
        return "D";
    else
        return "U";
}


void bfs(ll i,ll j)
{
    queue<pii> q;
    q.push({i,j});
    map<pii,pii> par;
    pii des={-1,-1};
    vector<vi> visited(n,vi(m,0));
    visited[i][j]=1;
    while(!q.empty())
    {
        pii node=q.front();
        // debug(mp(node.first,node.second))
        // debug(node.j)
        q.pop();

        for(ll k=0;k<4;k++)
        {
            ll nx=node.first+dx[k];
            ll ny=node.second+dy[k];
            // if(node.first==3 && node.second==6)
            // {
            //     debug(mp(nx,ny));
            //     debug(vs[nx][ny]);
            // }
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;

            if(visited[nx][ny]==1 || vs[nx][ny]=='#')
                continue;

            if(vs[nx][ny]=='.')
            {
                par[{nx,ny}]={node.first,node.second};
                visited[nx][ny]=1;
                q.push({nx,ny});   
            }
            else if(vs[nx][ny]=='B')
            {
                par[{nx,ny}]={node.first,node.second};
                des={nx,ny};
                break;
            }
        }
        if(des.first!=-1)    
            break;
    }

    if(des.first==-1)
    {
        cout<<"NO"<<endl;
        return;
    }
    string res;
    while(true)
    {
        pii pr=par[des];
        res+=findChar(des.first,des.second,pr.first,pr.second);
        // debug(res);
        des=pr;
        if(vs[pr.first][pr.second]=='A')
            break;
    }

    reverse(all(res));
    cout<<"YES"<<endl;
    cout<<res.size()<<endl;
    cout<<res<<endl;


}

void solve()
{
    cin>>n>>m;
    ll i,j;
    vs.resize(n);
    fo(i,n)
    {
        cin>>vs[i];    
    }

    fo(i,n)
    {
        fo(j,m)
            if(vs[i][j]=='A')
                bfs(i,j);
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