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
    ll n,k,i,j,l;
    cin>>n>>k;
    string s;
    cin>>s;
    s="#"+s;

    ll dp[n+1][k+1];
    // string dps[n+1][k+1];
    mem(dp,0);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            ll mn=INT_MAX;
            // ll ch;
            for(l=1;l<=k;l++)
            {
                if(j==l)
                    continue;
                // if(mn>dp[i-1][l])
                // {
                //     mn=dp[i-1][l];
                //     ch=l;
                // }
                mn=min(dp[i-1][l],mn);
            }
            if(s[i]-65==j-1)
            {
                dp[i][j]=mn;
            }
            else
                dp[i][j]=mn+1;
            // char c='A'+j-1;      
            // dps[i][j]=dps[i-1][ch]+c;
        }
    }
    ll ans=INT_MAX;
    string anss;
    for(i=1;i<=k;i++)
    {
        if(ans>dp[n][i])
        {
            ans=dp[n][i];
            // anss=dps[n][i];
        }
        // ans=min(ans,dp[n][i]);
        // cout<<dps[n][i]<<endl;
    }
    i=n;
    ll prev=-1;
    while(i>=1)
    {
        ll mn=INT_MAX;
        ll in;

        for(j=1;j<=k;j++)
        {
            if(i<n && j==prev)
                continue;
            if(mn>dp[i][j])
            {
                mn=dp[i][j];
                in=j;
            }
        }
        char c='A'+in-1;
        anss+=c;
        i--;
        prev=in;
    }
    cout<<ans<<endl;
    reverse(anss.begin(),anss.end());
    cout<<anss<<endl;
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