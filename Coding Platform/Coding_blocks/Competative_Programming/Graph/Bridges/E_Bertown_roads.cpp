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
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

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

ll visited[N];
ll in_time[N],low[N];
ll timer;
ll flag;
vector<pii> res;
map<pii,ll> m;

void dfs(ll node,ll par)
{
    // cout<<node<<" ";
    visited[node]=1;
    timer++;
    in_time[node]=low[node]=timer;

    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;
        
        if(visited[nbr])
        {
            low[node]=min(low[node],in_time[nbr]);
            if(m[{node,nbr}] || m[{nbr,node}])
                continue;
            m[{node,nbr}]=1;
            res.pb({node,nbr});
        }
        else
        {
            dfs(nbr,node);

            if(in_time[node]<low[nbr])
            {
                // cout<<"Bridge"<<endl;
                // cout<<node<<" "<<nbr<<endl;
                flag=1;
                return;
            }

            low[node]=min(low[node],low[nbr]);

            res.pb({node,nbr});
            m[{node,nbr}]=1;
        }

    }

}

void solve()
{
    ll n,m,x,y,i;
    cin>>n>>m;
    fo(i,m)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }   

    dfs(1,-1);

    if(flag)
    {
        cout<<0<<endl;
    }
    else
    {
        for(auto edge:res)
        {
            cout<<edge.first<<" "<<edge.second<<endl;
        }
    }
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