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

const ll N=2e5+5;

bool visited[N],cycle[N],isCycle;
vi parent(N),ele_cycle;
vi v[N];
ll res;

void cycle_detect(ll node,ll par)
{
    visited[node]=true;
    for(auto child:v[node])
    {
        if(child==par)
            continue;
        
        if(!visited[child])
        {
            parent[child]=node;
            cycle_detect(child,node);
            if(isCycle)
                return;
        }   
        else
        {
            ll cur=node;
            while(cur!=child)
            {
                if(cur==0)
                    break;
                ele_cycle.pb(cur);
                cycle[cur]=true;
                cur=parent[cur];
            }
            ele_cycle.pb(child);
            cycle[child]=true;
            isCycle=true;
            return;
        }
    }
}

void dfs(ll node)
{
    res++;
    visited[node]=true;
    for(auto child:v[node])
        if(!visited[child])
            dfs(child);
}

void init(ll n)
{
    isCycle=false;
    for(ll i=0;i<=n;i++)
    {
        visited[i]=false;
        cycle[i]=false;
        v[i].clear();
    }
    ele_cycle.clear();
}

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        init(n);
        fo(i,n)
        {
            ll x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }

        cycle_detect(1,0);

        ll ans=n*(n-1);

        for(i=0;i<=n;i++)
        {
            visited[i]=false;
            if(cycle[i])
            {
                visited[i]=true;
            }
        }

        for(auto ele:ele_cycle)
        {
            res=1;
            for(auto child:v[ele])
            {
                if(cycle[child]==false)
                {
                    dfs(child);
                }
            }
            ans+=res*(n-res);
        }
        cout<<ans/2<<endl;




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