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
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,i,j;
        cin>>n>>m;
        vector<string> vs(n);
        fo(i,n) 
        {
            cin>>vs[i];
        }

        ll dp[n][m];
        memset(dp,0,sizeof(dp));
        ll ans=0;
        for(i=n-1;i>=0;i--)
        {
            string s=vs[i];
            for(j=0;j<m;j++)
            {
                if(s[j]=='.')
                    dp[i][j]=0;
                else 
                {
                    if(i==n-1|| j==0 || j==m-1)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        // cout<<dp[i+1][j-1]<<" "<<dp[i+1][j]<<" "<<dp[i+1][j+1]<<endl;
                        ll mn=min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
                        // deb(mn);
                        dp[i][j]=mn+1;
                    }
                    
                }
                ans+=dp[i][j];
            }
        }
        // fo(i,n)
        // {
        //     fo(j,m)
        //         cout<<dp[i][j]<<" ";
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