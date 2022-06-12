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

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n+1);
    fo(i,n)
        cin>>v[i+1];
    ll dp[n+1][2];

    dp[0][0]=dp[0][1]=0;
    for(i=1;i<=n;i++)
    {
        dp[i][0]=INT_MAX;
        if(i==1)
        {
            dp[i][0]=(v[i]==1);
            dp[i][1]=0;
        }
        else if(i==2)
        {
            dp[i][0]=(v[i]==1)+(v[i-1]==1);
        }
        else if(i==3)
        {
            dp[i][0]=min(dp[i-2][0]+(v[i]==1),dp[i][0]);
        }
        else if(i==4)
        {
            dp[i][0]=min(dp[i-2][0]+(v[i]==1),dp[i-3][0]+(v[i]==1));
            dp[i][0]=min(dp[i][0],dp[i-3][0]+(v[i]==1)+(v[i-1]==1));
        }
        else
        {
            dp[i][0]=min(dp[i-2][0]+(v[i]==1),dp[i-3][0]+(v[i]==1));
            dp[i][0]=min(dp[i][0],dp[i-3][0]+(v[i]==1)+(v[i-1]==1));
            dp[i][0]=min(dp[i][0],dp[i-4][0]+(v[i]==1)+(v[i-1]==1));
        }
    }
    ll ans;
    if(n>=3)
    {
        ans=min(dp[n][0],min(dp[n-1][0],dp[n-2][0]));
    }
    else if(n==2)
    {
        ans=min(dp[n][0],dp[n-1][0]);
    }
    else
    {
        ans=dp[n][0];
    }
    cout<<ans<<endl;
    
}

int main()
{
    fastio
    int t;
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