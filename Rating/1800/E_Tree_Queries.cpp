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

const ll N=2*1e5+5;

vector<vi> g(N);
ll parent[N];
ll dep[N];
ll in[N];
ll out[N];
ll te=1;

void dfs(ll cur,ll par,ll len)
{
    dep[cur]=len;
    in[cur]=te++;
    parent[cur]=par;

    for(auto node:g[cur])
    {
        if(node!=par)
        {
            dfs(node,cur,len+1);
        }
    }

    out[cur]=te++;
}

void solve()
{
    ll n,e,i;
    cin>>n>>e;
    fo(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1,-1,1);

    fo(i,e)
    {
        ll m;
        cin>>m;
        vi v(m);
        ll j;
        ll depest=INT_MIN,dnode;
        fo(j,m)
        {
            cin>>v[j];
            ll par=parent[v[j]];
            if(par!=-1 && dep[par]>depest)
            {
                depest=dep[par];
                dnode=par;
            }
        }

        // for(j=1;j<=n;j++)
        // {
        //     deb(j);
        //     cout<<in[j]<<" "<<out[j]<<endl;
        // }

        ll flag=1;

        fo(j,m)
        {
            ll par=parent[v[j]];
            if(par==-1)
                continue;
            if(!(in[par]<=in[dnode] && out[par]>=out[dnode]))
            {
                // deb(par);
                flag=0;
                break;
            }
        }

        if(flag)
        {
            cout<<"YES";
        }
        else
            cout<<"NO";
        cout<<endl;
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