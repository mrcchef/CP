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

const ll N=30001;

ll n,d,i;
ll dp[N][505];
mii gem;

ll solve(int i,int j)
{
    ll jj=j-d+250;
    if(i>=N)
        return 0;
    if(dp[i][jj]!=-1)
        return dp[i][jj];
    
    ll ans=INT_MIN;
    if(j==1)
    {
        ans=gem[i]+max(solve(i+j,j),solve(i+j+1,j+1));
    }
    else
    {
        ans=gem[i]+max(solve(i+j-1,j-1),max(solve(i+j,j),solve(i+j+1,j+1)));
    }
    dp[i][jj]=ans;
    return ans;
}

int main()
{
    fastio
    mem(dp,-1);
    cin>>n>>d;
    vi v(n);
    fo(i,n)
    {
        cin>>v[i];
        gem[v[i]]++;
    }

    cout<<solve(d,d)<<endl;

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