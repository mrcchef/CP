#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll n,w;
ll dp[105][100005];

ll solve(vector<pair<ll,ll>> vp,ll N,ll W)
{
    if(N==0)
        return dp[N][W]=0;
    
    if(dp[N][W]!=-1)
        return dp[N][W];
    ll val1=-1,val2=-1;
    val1=solve(vp,N-1,W);
    if(W-vp[N].first>=0)
    {
        val2=solve(vp,N-1,W-vp[N].first)+vp[N].second;
    }

    return dp[N][W]=max(val1,val2);
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
        ll i;
        cin>>n>>w;
        vector<pair<ll,ll>> vp;
        vp.pb({0,0});
        fo(i,n)
        {
            ll x,y;
            cin>>x>>y;
            vp.pb({x,y});
        }
        memset(dp,-1,sizeof(dp));
        ll ans=solve(vp,n,w);
        // for(i=0;i<=n;i++)
        // {
        //     for(ll j=0;j<=w;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
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