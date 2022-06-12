#include <bits/stdc++.h>
using namespace std;
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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

vi g[200005];
ll height[200005];
ll sub[200005];
// set<pair<ll,ll>> sp; // children and node

void dfs(ll cur,ll par,ll hei)
{
    height[cur]=hei;
    // sp.insert({g[cur].size()-1,cur});
    for(auto node:g[cur])
    {
        if(node!=par)
        {
            dfs(node,cur,hei+1);
        }
    }
}

ll subtree(ll cur,ll par)
{
    ll val=0;
    for(auto node:g[cur])
    {
        if(node!=par)
            val+=subtree(node,cur);
    }
    sub[cur]=val;
    return val+1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,k,i;
        cin>>n>>k;
        fo(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }

        dfs(1,-1,0);
        subtree(1,-1);
        vi vec;
        Fo(i,1,n)
        {
            ll val=height[i]-sub[i];
            // cout<<height[i]<<" "<<sub[i]<<" "<<val<<endl;
            vec.pb(val);
        }
        sort(vec.begin(),vec.end(),greater<ll>());
        ll ans=0;
        fo(i,k)
        {
            ans+=vec[i];
        }
        cout<<ans<<endl;
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