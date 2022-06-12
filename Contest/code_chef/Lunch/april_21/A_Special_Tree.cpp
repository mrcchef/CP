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
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":"<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
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



void dfs(ll node,ll par,ll dis[],ll len,vector<vi> &g,ll inTime[],ll outTime[],ll &tm)
{
    dis[node]=len;
    inTime[node]=tm;
    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;
        tm++;
        dfs(nbr,node,dis,len+1,g,inTime,outTime,tm);
    }
    tm++;
    outTime[node]=tm;
}
ll faltu;

void dfs2(ll node,ll par,ll dis,ll dest,vector<vi> &g)
{
    if(node==dest)
    {
        faltu=dis+1;
    }
    // ll val=;
    for(auto nbr:g[node])
    {
        if(nbr==par)
            continue;
        // tm++;
        // dfs(nbr,node,dis,len+1,g,inTime,outTime,tm);
        dfs2(nbr,node,dis+1,dest,g);
    }
    // return val;
}

void solve()
{
    ll n,k,a;
    cin>>n>>k>>a;
    ll i;
    
    vector<vi> g(n+1);

    vi spes(k);
    fo(i,k)
        cin>>spes[i];
    
    fo(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    ll dis[n+1]={0};

    ll inTime[n+1]={0};
    ll outTime[n+1]={0};
    ll tm=1;

    dfs(a,0,dis,0,g,inTime,outTime,tm);

    // Fo(i,1,n)
    //     cout<<dis[i]<<" ";
    // cout<<endl;

    // Fo(i,1,n)
    //     cout<<inTime[i]<<" ";
    // cout<<endl;

    // Fo(i,1,n)
    //     cout<<outTime[i]<<" ";
    // cout<<endl;

    map<pii,ll> hm;

    

    vi res;
    vi node;

    Fo(i,1,n)
    {
        ll j;
        ll ans=INT_MIN;
        ll u;
        fo(j,k)
        {
            // dfs2(i,0,0,spes[j],g);
            // ll len=faltu-1;
            ll len=0;
            if((inTime[spes[j]]<inTime[i] && outTime[spes[j]]>outTime[i]) || (inTime[spes[j]]>inTime[i] && outTime[spes[j]]<outTime[i]))
            {
                len=abs(dis[i]-dis[spes[j]]);
                // trace4("sub",i,spes[j],len);
            }
            else if(i==spes[j])
            {
                len=0;
            }
            else
            {
                len=dis[i]+dis[spes[j]];
            }

                // trace4("add",i,spes[j],len);
            // ans=max(ans,dis[i]-len);
            if(ans<dis[spes[j]]-len)
            {
                ans=dis[spes[j]]-len;
                u=spes[j];
                // trace5(i,u,dis[i],len,ans);
            }
        }

        res.pb(ans);
        node.pb(u);
        // cout<<ans<<" ";
    }

    for(auto val:res)
        cout<<val<<" ";
    cout<<endl;

    for(auto val:node)
        cout<<val<<" ";
    cout<<endl;
    


}

int main()
{
    fastio
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