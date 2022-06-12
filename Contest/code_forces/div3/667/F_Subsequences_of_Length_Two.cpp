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

ll dp[205][205][205];

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
        string s1,s2;
        cin>>s1>>s2;
        s1="*"+s1;
        s2="*"+s2;
        // ll dp[n+1][k+1][3],total[n+1][k+1];
        // memset(dp,0,sizeof(dp));
        for(i=0;i<=n;i++)
        {
            for(ll j=0;j<=k;j++)
            {
                for(ll k=0;k<=n;k++)
                    dp[i][j][k]=INT_MIN;
            }
        }
        dp[1][1][1]=dp[0][0][0]=0;
        
        // memset(total,0,sizeof(total));
        for(i=1;i<=n;i++)
        {
            for(ll j=1;j<=k;j++) // no of changes
            {
                for(ll na=0;na<=n;na++) // no. of first charater of s2
                {
                    // If we are not chaning the last character
                    if(s1[i]==s2[1])
                    {
                        if(na>0)
                            dp[i][j][na]=max(dp[i-1][j][na-1],dp[i][j][na]);
                    }
                    else if(s1[i]==s2[2])
                    {
                        dp[i][j][na]=max(dp[i][j][na],dp[i-1][j][na]+na);
                    }
                    else
                    {
                        dp[i][j][na]=max(dp[i][j][na],dp[i-1][j][na]);
                    }

                    // If we change to first character
                    if(na>0)
                        dp[i][j][na]=max(dp[i][j][na],dp[i-1][j-1][na-1]);

                    // Id we change to second character 

                    dp[i][j][na]=max(dp[i][j][na],dp[i-1][j-1][na]+na);
                    
                }
            }
        }

        // for(i=0;i<s1.size();i++)
        // {
        //     for(ll j=0;j<n;j++)
        //     {
        //         for(ll k=0;k<=s1.size();k++)
        //         {
        //             cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
        //         }
        //     }
        // }


        ll ans=0;

        for(i=0;i<=k;i++)
        {
            for(ll j=0;j<=n;j++)
            {
                ans=max(ans,dp[n][i][j]);
            }
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