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
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void solve()
{
    ll n,m,i,j;
    cin>>n>>m;
    vi a(n+2),b(m+2);
    mii ma,mb;
    vi inter;
    fo(i,n)
    {
        cin>>a[i+1];
        ma[a[i+1]]=i+1;
    }
    fo(i,m)
    {
        cin>>b[i+1];
        mb[b[i+1]]=i+1;
    }
    a[n+1]=b[m+1]=0;
    for(auto it:ma)
    {
        if(mb[it.first]>0)
        {
            inter.pb(it.first);
        }
    }
    ma[0]=n+1;
    mb[0]=m+1;

    inter.pb(0);

    vi prefa(n+2,0),prefb(m+2,0);

    fo(i,n)
    {
        prefa[i+1]=prefa[i]+a[i+1];
    }
    prefa[n+1]=prefa[n];
    fo(i,m)
    {
        prefb[i+1]=prefb[i]+b[i+1];
    }
    prefb[m+1]=prefb[m];

    vi dp(inter.size(),0);

    for(i=0;i<inter.size();i++)
    {
        if(i==0)
        {
            dp[i]=max(prefa[ma[inter[i]]],prefb[mb[inter[i]]]);
        }
        else
        {
            dp[i]=dp[i-1]+max(prefa[ma[inter[i]]]-prefa[ma[inter[i-1]]],prefb[mb[inter[i]]]-prefb[mb[inter[i-1]]]);
        }
    }

    for(i=0;i<inter.size();i++)
        cout<<dp[i]<<" ";
    cout<<endl;

    for(i=0;i<inter.size();i++)
        cout<<inter[i]<<" ";
    cout<<endl;

    cout<<dp[inter.size()-1]<<endl;
}

int main()
{
    fastio
    int t;
    cin>>t;
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