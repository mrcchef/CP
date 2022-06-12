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
        ll n,k,p,i;
        cin>>n>>k>>p;
        vi a(n+1),b(k+1);
        fo(i,n)
            cin>>a[i+1];
        fo(i,k)
            cin>>b[i+1];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        ll dp[n+1][k+1];


        for(i=0;i<=n;i++)
        {
            for(ll j=0;j<=k;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                else
                    dp[i][j]=1e17;
            }
        }

        // dp[0][0]=0;

        for(i=1;i<=n;i++)
        {
            for(ll j=1;j<=k;j++)
            {
                dp[i][j]=dp[i][j-1];
                dp[i][j]=min(dp[i][j],max(dp[i-1][j-1],abs(a[i]-b[j])+abs(b[j]-p)));
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }

        cout<<dp[n][k]<<endl;
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