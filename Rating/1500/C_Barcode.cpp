#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
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
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}


ll dp[1005][2];

void solve()
{
    ll n,m,x,y,i,j;
    cin>>n>>m>>x>>y;
    vector<string> vs(n);
    ll cntd[m+1]={0},cnth[m]={0};
    fo(i,n)
    {
        cin>>vs[i];
        fo(j,m)
        {
            if(vs[i][j]=='.')
                cntd[j+1]++;
        }
    }

    ll pref[m+1]={0};

    Fo(i,1,m)
    {
        pref[i]=pref[i-1]+cntd[i];
        // cout<<pref[i]<<" ";
    }
    // cout<<endl;

    fo(i,m+1)
    {
        dp[i][0]=dp[i][1]=INT_MAX;
    }

    dp[0][0]=dp[0][1]=0;

    Fo(i,1,m)
    {
        Fo(j,x,y)
        {
            if(i<j)
                continue;
            ll reqd=pref[i]-pref[i-j];
            ll reqh=j*n-reqd;
            // trace4(i,j,reqd,reqh);
            dp[i][0]=min(dp[i][0],dp[i-j][1]+reqd);
            dp[i][1]=min(dp[i][1],dp[i-j][0]+reqh);  
        }
        // trace2(dp[i][0],dp[i][1]);
    }

    ll ans=min(dp[m][0],dp[m][1]);
    cout<<ans<<endl;
    
}

int main()
{
    fastio
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();   
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