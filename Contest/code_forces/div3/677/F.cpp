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

// Dp is all about taking that element or skip that element. That's all!!!


ll n,m,k;
ll dp[71][71][71][36];
ll arr[71][71];

ll solve(ll i,ll j,ll rem,ll req)
{
    if(i==n-1 && (j==m || req==0))
    {
        return rem==0?0:INT_MIN;
    }

    if(j==m || req==0)
    {
        return dp[i][j][rem][req]=solve(i+1,0,rem,m/2);
    }

    if(dp[i][j][rem][req]!=-1)
        return dp[i][j][rem][req];

    ll ans=INT_MIN,MOD=arr[i][j]%k;
    if(MOD>rem)
    {
        ans=max(ans,arr[i][j]+solve(i,j+1,k-(MOD-rem),req-1));
    }
    else
        ans=max(ans,arr[i][j]+solve(i,j+1,rem-MOD,req-1));
    
    ans=max(ans,solve(i,j+1,rem,req));
    
    return dp[i][j][rem][req]=ans;
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
        cin>>n>>m>>k;
        ll i,j;
        fo(i,n)
        {
            fo(j,m)
                cin>>arr[i][j];
        }

        memset(dp,-1,sizeof(dp));
        ll ans=solve(0,0,0,m/2);

        cout<<max(0*1LL,ans)<<endl;


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