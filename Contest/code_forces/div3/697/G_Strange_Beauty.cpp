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

const ll N=200005;

int main()
{
    fastio
    vi div[N];
    div[1].pb(1);
    for(ll i=2;i<N;i++)
        {
            // ll val=i;
            div[i].pb(i);
            div[i].pb(1);
            for(ll j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    div[i].pb(j);
                    if(i/j!=j)
                        div[i].pb(i/j);
                }
            }
        }
    // mii mdiv;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v(n);
        // mii m;
        fo(i,n)
        {
            cin>>v[i];
            // m[v[i]]++;
        }
        
        sort(v.begin(),v.end());

        ll dp[N]={0};

        ll ans=0;

        fo(i,n)
        {
            ll val=v[i];
            ll cnt=0;
            for(ll j=0;j<div[val].size();j++)
            {
                // if(m[div[val][j]]==0) // b/c of map, we are getting TLE 
                //     continue;
                cnt=max(cnt,dp[div[val][j]]+1);
            }
            dp[val]=max(cnt,dp[val]);
            // cout<<dp[val]<<" "<<val<<endl;
            ans=max(ans,dp[val]);
        }
        // deb(ans);

        cout<<n-ans<<endl;

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