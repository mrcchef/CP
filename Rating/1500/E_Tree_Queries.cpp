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

vector<vi> G(N);
ll visited[N];
ll depth[N];
ll parent[N];

void add_edge(ll i,ll j)
{
    G[i].pb(j);
    G[j].pb(i);
}

void cal_depth(ll cur,ll dep,ll par)
{
    depth[cur]=dep;
    for(auto node:G[cur])
    {
        if(node!=par)
        {
            parent[node]=cur;
            cal_depth(node,dep+1,cur);
        }
    }
}

vi stk;


void dfs(ll cur,ll dest,ll par)
{
    stk.push_back(cur);
    if(cur==dest)
    {

        return;
    }

    for(auto node:G[cur])
    {
        if(node!=par)
        {
            dfs(node,dest,cur);
        }
    }
    stk.pop_back();
}

void solve()
{
    ll n,i,q;
    cin>>n>>q;
    fo(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        add_edge(x,y);
    }

    cal_depth(1,1,0);

    fo(i,q)
    {
        ll m;
        cin>>m;
        vi ele(m);
        ll j;
        ll mxd=0,mxe;
        mii mape;
        stk.clear();
        fo(j,m)
        {
            cin>>ele[j];
            mape[ele[j]]=1;
            if(mxd<depth[ele[j]])
            {
                mxe=ele[j];
                mxd=depth[ele[j]];
            }
        }
        ll cnt=0;
        dfs(1,mxd,0);
        for(auto node:stk)
        {
            deb(node);
            if(mape[node]==1)
            {
                mape[node]=0;
                cnt++;
            }
            for(auto val:G[node])
            {
                if(mape[val]==1)
                {
                    mape[val]=0;
                    cnt++;
                }
            }
        }
        deb(cnt);
        if(cnt==m)
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