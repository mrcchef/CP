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
        ll r,g,b,i;
        cin>>r>>g>>b;
        vi R(r+1),G(g+1),B(b+1);
        fo(i,r)
            cin>>R[i+1];
        fo(i,g)
            cin>>G[i+1];
        fo(i,b)
            cin>>B[i+1];
        ll j,k;
        R[0]=INT_MAX;
        G[0]=INT_MAX;
        B[0]=INT_MAX;
        sort(R.begin(),R.end(),greater<ll>());
        sort(G.begin(),G.end(),greater<ll>());
        sort(B.begin(),B.end(),greater<ll>());
        for(i=0;i<=r;i++)
        {
            for(j=0;j<=g;j++)
            {
                for(k=0;k<=b;k++)
                {
                    if((i==0 && j==0 && k==0) || (i==0 && j==0) || (i==0 && k==0)|| (k==0 && j==0))
                    {
                        dp[i][j][k]=0;
                    }
                    else if(i==0)
                    {
                        dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+G[j]*B[k]);
                        dp[i][j][k]=max(dp[i][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                    }
                    else if(j==0)
                    {
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+R[i]*B[k]);
                        dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k],dp[i][j][k-1]));
                    }else if(k==0)
                    {
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+G[j]*R[i]);
                        dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k],dp[i][j-1][k]));
                    }
                    else
                    {
                        dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1])));
                        // dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]);
                        dp[i][j][k]=max(dp[i][j][k],max(dp[i-1][j-1][k]+G[j]*R[i],max(dp[i-1][j][k-1]+R[i]*B[k],dp[i][j-1][k-1]+G[j]*B[k])));
                    }
                }
            }
        }
        // for(i=0;i<=r;i++)
        // {
        //     for(j=0;j<=g;j++)
        //     {
        //         for(k=0;k<=b;k++)
        //         {
        //             cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
        //         }
        //     }
        // }
        cout<<dp[r][g][b]<<endl;
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