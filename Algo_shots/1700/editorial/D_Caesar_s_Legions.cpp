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

ll dp[101][101][11][11];
const ll N=1e8;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m,i,j,k1,k2,k,l;
        cin>>n>>m>>k1>>k2;
        for(i=0;i<=k1;i++)
            dp[i][0][i][0]=1;
        for(i=0;i<=k2;i++)
            dp[0][i][0][i]=1;    
        Fo(i,1,n)
        {
            Fo(j,1,m)
            {
                Fo(k,1,k1)
                {
                    Fo(l,1,k2)
                    {
                        dp[i][j][k][l]=dp[i-1][j][k-1][l]+dp[i][j-1][k][l-1];
                        dp[i][j][k][l]%=N;
                        cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                        cout<<dp[i][j][k][l]<<endl;
                    }
                }
                Fo(l,1,k1)
                {
                    Fo(k,1,k2)
                    {
                        dp[i][j][l][k]=dp[i-1][j][l][k-1]+dp[i][j-1][l-1][k];
                        dp[i][j][l][k]%=N;
                        cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                        cout<<dp[i][j][k][l]<<endl;
                    }
                }
            }
        }
        cout<<dp[n][m][k1][k2]<<endl;
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