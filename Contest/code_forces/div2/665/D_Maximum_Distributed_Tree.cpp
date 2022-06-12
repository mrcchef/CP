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

vector<ll> g[100010];
bool visited[100010]={false};
vi wie;

ll dfs(ll node,ll p,ll n)
{
    ll ans=1;
    for(auto nbr:g[node])
    {
        if(p!=nbr)
        {
            ll nd=dfs(nbr,node,n);
            wie.pb(nd*(n-nd));
            ans+=nd; 
        }
    }
    // wie[node]=ans*(n-ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        fo(i,n)
        {
            g[i].clear();
            visited[i]=false;
            wie.clear();
        }
        fo(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            x--,y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        ll m;
        cin>>m;
        vi prime(m);
        fo(i,m)
            cin>>prime[i];
        
        sort(prime.begin(),prime.end(),greater<ll>());

        dfs(0,-1,n);

        if(m>n-1)
        {
            ll extra=m-n+2;
            ll val=1;
            ll j;
            vi temp;
            // deb(extra);
            for(j=0;j<extra;j++)
            {
                val=(val*prime[j])%mod;
            }
            temp.pb(val);
            
            for(j;j<m;j++)
                temp.pb(prime[j]);
            prime=temp;
            // deb(prime.size());
        }

        sort(wie.begin(),wie.end(),greater<ll>());
        ll j=0,ans=0;
        i=0;
        while(i<prime.size())
        {
            ans+=(prime[i++]*wie[j++])%mod;
            ans%=mod;
            
        }
        while(j<wie.size())
        {
            ans+=wie[j++];
            ans%=mod;
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