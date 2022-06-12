#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

const ll N=1e5+5;

vector<vi> g(N);
vector<vi> cg(N);
ll visited[N];
ll color[N];
ll card[N];
map<pii,ll> hm;

void dfs(ll node)
{
    visited[node]=1;

    for(auto nbr:g[node])
    {
        if(!visited[nbr])
        {
            if(color[nbr]!=color[node])
            {
                if(hm[{color[nbr],color[node]}]==0)
                {
                    cg[color[nbr]].pb(color[node]);
                    cg[color[node]].pb(color[nbr]);
                    hm[{color[nbr],color[node]}]=1;
                }
            }
            dfs(nbr);
        }
    }
}


void solve()
{
    ll n,m,i;
    cin>>n>>m;   
    fo(i,n)
        cin>>color[i+1];
    
    fo(i,m)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    Fo(i,1,n)
    {
        if(!visited[i])
            dfs(i);
    }

    ll crd=INT_MIN;
    ll col;

    for(i=1;i<=n;i++)
    {
        ll tcrd=cg[color[i]].size();

        // trace3(i,card[i],color[i]);
        if(crd<tcrd)
        {
            crd=tcrd;
            col=color[i];
        }
        else if(crd==tcrd)
        {
            col=min(col,color[i]);
        }
    }

    cout<<col<<endl;

}

int main()
{
    fastio
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