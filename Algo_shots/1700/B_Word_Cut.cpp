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

ll dp[1001][100001];
string dps[1001][10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        ll k;
        cin>>k;
        ll n=s1.size();
        // ll dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        // string dps[n+1][k+1];
        for(ll i=0;i<=n;i++)
            dps[i][0]=s1;
        for(ll i=0;i<=k;i++)
            dps[0][i]=s1;
        
        for(ll i=1;i<n;i++)
        {
            for(ll j=1;j<=k;j++)
            {
                string temp=dps[i][j-1];
                // cout<<temp.substr(0,i)<<" "<<temp.substr(i);
                string ntemp=temp.substr(i)+temp.substr(0,i);
                
                if(ntemp==s2)
                {
                    dp[i][j]=dp[i][j-1]+1;
                }
                // else
                // {
                //     dp[i][j]=dp[i][j-1];
                // }
                dp[i][j]%=mod;
                dps[i][j]=ntemp;
                // cout<<dp[i][j]<<endl;
            }
        }
        ll sm=0;
        for(ll i=1;i<=n;i++)
        {
         sm+=dp[i][k];
         sm%=mod;
        }   

        // for(ll i=0;i<=n;i++)
        // {
        //     for(ll j=0;j<=k;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        // for(ll i=0;i<=n;i++)
        // {
        //     for(ll j=0;j<=k;j++)
        //         cout<<dps[i][j]<<" ";
        //     cout<<endl;
        // }
        cout<<sm<<endl;
            
        
        

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