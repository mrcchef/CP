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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc=1;
    // cin>>t;
    while(tc--)
    {
        ll v1,v2;
        cin>>v1>>v2;
        ll t,k;
        cin>>t>>k;

        ll dp[t+1][2005];

        for(ll i=0;i<=t;i++)
            for(ll j=0;j<2005;j++)
                dp[i][j]=INT_MIN;

        // memset(dp,-1,sizeof(dp));

        dp[1][v1]=v1;

        for(ll i=2;i<=t;i++)
        {

            // cout<<i<<endl;
            for(ll j=0;j<=2004;j++)
            {
                
                ll st=max(j-k,0LL);
                ll ed=min(j+k,2005LL);

                for(ll val=st;val<=ed;val++)
                {
                    // if(j+val>=0)
                    // {
                        // cout<<val<<" ";
                        dp[i][j]=max(dp[i][j],dp[i-1][val]+j);
                    // cout<<dp[i][j]<<" ";
                    
                }
                // cout<<endl;
            // cout<<i<<" "<<dp[i][j]<<endl;
            }
            // deb(dp[i][v2]);
        }
        // cout<<dp[1][5]<<" "<<dp[2][7]<<" "<<dp[3][8]<<" "<<dp[4][6]<<endl;

        cout<<dp[t][v2]<<endl;
        
        // cout<<ans<<endl;


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