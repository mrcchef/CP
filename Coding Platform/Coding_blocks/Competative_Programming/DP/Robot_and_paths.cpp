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
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m,p,i,j;
        cin>>n>>m>>p;
        ll arr[n][m];
        memset(arr,0,sizeof(arr));
        ll dp[n][m];
        for(i=0;i<p;i++)
        {
           ll x,y;
           cin>>x>>y;
           arr[x-1][y-1]=-1;
        }
        if(arr[0][0]==-1 || arr[n-1][m-1]==-1)
        {
            cout<<0<<endl;
            return 0;
        }
        fo(i,n)
        {
            fo(j,m)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                }
                else if(i==0)
                {
                    if(arr[i][j]==-1)
                    {
                        dp[i][j]=0;
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                }
                else if(j==0)
                {
                    if(arr[i][j]==-1)
                    {
                        dp[i][j]=0;
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else
                {
                    if(arr[i][j]==-1)
                    {
                        dp[i][j]=0;
                    }
                    else
                    {
                        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                    }
                }
            }
        }
        cout<<dp[n-1][m-1]<<endl;

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