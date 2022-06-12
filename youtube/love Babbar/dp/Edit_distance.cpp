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

// https://www.youtube.com/watch?v=We3YDTzNXEk&feature=emb_logo

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
        string s,t;
        cin>>s>>t;
        ll sz1=s.size(),sz2=t.size();
        s='*'+s;
        t='*'+t;
        deb(s);
        deb(t);
        ll dp[sz1+1][sz2+1];
        memset(dp,0,sizeof(dp));

        for(ll i=0;i<=sz1;i++)
            dp[i][0]=i;

        for(ll i=0;i<=sz2;i++)
            dp[0][i]=i;
        
        for(ll i=1;i<=sz1;i++)
        {
            for(ll j=1;j<=sz2;j++)
            {
                if(s[i]==t[j])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }

        for(ll i=0;i<=sz1;i++)
        {
            for(ll j=0;j<=sz2;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        

        

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