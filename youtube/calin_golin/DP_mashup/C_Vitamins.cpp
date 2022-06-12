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
        ll n,i;
        cin>>n;
        ll dp[8];
        fo(i,8)
            dp[i]=INT_MAX;
        fo(i,n)
        {
            ll x;
            string v;
            cin>>x>>v;
            ll j,val=0;

            fo(j,v.size())
            {
                if(v[j]=='A')
                {
                    val+=1<<2;
                }
                else if(v[j]=='B')
                {
                    val+=1<<1;
                }
                else
                {
                    val+=1;
                }
            }

            dp[val]=min(dp[val],x);
            // deb(dp[val]);
        }
        dp[0]=0;
        ll ans=INT_MAX;

        ans=min(ans,dp[1]+dp[6]);
        ans=min(ans,dp[2]+dp[5]);
        ans=min(ans,dp[3]+dp[4]);
        ans=min(ans,dp[3]+dp[6]);
        ans=min(ans,dp[5]+dp[6]);
        ans=min(ans,dp[3]+dp[5]);
        ans=min(ans,dp[7]);
        ans=min(ans,dp[1]+dp[2]+dp[4]);
    

        // fo(i,4)
        
        if(ans==INT_MAX)
            ans=-1;
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