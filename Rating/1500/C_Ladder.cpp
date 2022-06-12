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
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

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
    ll n,m,i;
    cin>>n>>m;
    vi v(n+1);
    fo(i,n)
        cin>>v[i+1];
    
    ll lastinc[n+1],lastdec[n+1];
    lastinc[n]=n;
    lastdec[n]=n;


    for(i=n-1;i>=1;i--)
    {
        if(v[i]<=v[i+1])
        {
            lastinc[i]=lastinc[i+1];
        }
        else
            lastinc[i]=i;
        if(v[i]>=v[i+1])
        {
            lastdec[i]=lastdec[i+1];
        }
        else
            lastdec[i]=i;
    }

    // for(int i=0;i<=n;i++)
    //     cout<<lastinc[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<=n;i++)
    //     cout<<lastdec[i]<<" ";
    // cout<<endl;

    fo(i,m)
    {
        ll x,y;
        cin>>x>>y;
        ll inc=lastinc[x];
        ll dec=lastdec[inc];
        if(dec>=y)
        {
            cout<<"Yes";
        }
        else   
            cout<<"No";
        cout<<endl;
    }
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