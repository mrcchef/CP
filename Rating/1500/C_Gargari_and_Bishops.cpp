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
    ll n,i,j;
    cin>>n;
    ll dp1[2*n+1]={0};
    ll dp2[2*n+1]={0};
    // mem(dp,0);
    ll arr[n+1][n+1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            ll x;
            cin>>x;
            arr[i][j]=x;
            dp1[i+j]+=x;
            dp2[n+i-j]+=x;
        }
    }

    ll x1,x2,y1,y2;
    ll res1=INT_MIN,res2=INT_MIN;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            ll sc=dp1[i+j]+dp2[i-j+n]-arr[i][j];
            if((i+j)&1)
            {
                if(res1<sc)
                {
                    x1=i;
                    y1=j;
                    res1=sc;
                }
            }
            else
            {
                if(res2<sc)
                {
                    x2=i;
                    y2=j;
                    res2=sc;
                }
            }
        }
    }
    cout<<res1+res2<<endl;
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

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