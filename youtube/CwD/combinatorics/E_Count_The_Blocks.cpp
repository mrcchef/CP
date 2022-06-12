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
const ll mod = 998244353;
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

const ll N=2*1e5+5;

ll pow10[N];

void init()
{
    ll i=0;
    pow10[0]=1;
    for(i=1;i<N;i++)
    {
        pow10[i]=(pow10[i-1]*10)%mod;
    }
}

void solve()
{
    ll n,i;
    cin>>n;
    ll ans[n+1];
    ans[n]=10;
    for(i=1;i<n;i++)
    {
        ll case1=0,case2=0;
        case1=(9*2*pow10[n-i])%mod;
        if(n-i-1>0)
            case2=(9*9*(n-i-1)*pow10[n-i-1])%mod;
        // deb(case1);
        // deb(case2);
        ans[i]=(case1+case2)%mod;
    }

    for(i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    fastio
    int t=1;
    init();
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