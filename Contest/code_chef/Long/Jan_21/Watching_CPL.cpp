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

ll dp[4001][4001];

bool check(ll sm,ll tsm,vi &ele,ll n,ll k)
{
    if(sm>=k)
    {
        if(tsm-sm>=k)
            return true;
    }
    if(n<0)
        return false;
    if(dp[n][sm]!=-1)
    {
        return dp[n][sm];
    }
    
    bool c1,c2;
    c1=check(sm+ele[n],tsm,ele,n-1,k);
    c2=check(sm,tsm,ele,n-1,k);
    
    return dp[sm][n]=c1|c2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,i,j;
        cin>>n>>k;
        vi v(n);
        fo(i,n)
            cin>>v[i];
        sort(v.begin(),v.end(),greater<ll>());
        ll sm=0,ans=-1;
        vi ele;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
            sm+=v[i];
            ele.pb(v[i]);
            if(sm>=2*k)
            {
                if(check(0,sm,ele,ele.size()-1,k))
                {
                    ans=ele.size();
                    break;
                }
            }
        }
           
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