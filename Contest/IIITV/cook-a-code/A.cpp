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
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":"<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
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


ll timer[2005];
ll pars[2005];

void fillval(ll x,ll y)
{
    for(ll i=x;i<=y;i++)
        timer[i]++;
}

ll calVal(vector<pii> &vp,ll x)
{
    ll cnt=0;
    for(auto val:vp)
    {
        ll tm=pars[val.second+x]-pars[val.first+x-1];
        cnt+=tm;
    }
    return cnt;
}

void solve()
{
     
    ll p,q,l,r;
    cin>>p>>q>>l>>r;
    ll i;
    vector<pii> vp1(p),vp2(q);

    fo(i,p)
    {
        cin>>vp1[i].first>>vp1[i].second;
    }
    fo(i,q)
    {
        cin>>vp2[i].first>>vp2[i].second;
    }

    sort(vp1.begin(),vp1.end());
    sort(vp2.begin(),vp2.end());

    for(i=0;i<2005;i++)
        timer[i]=0,pars[i]=0;
    
    for(auto val:vp1)
    {
        fillval(val.first,val.second);
    }
    // for(i=0;i<150;i++)
    //     cout<<timer[i]<<" ";
    // cout<<endl;
    pars[0]=timer[0];
    for(i=1;i<2005;i++)
    {
        pars[i]=pars[i-1]+timer[i];
        // cout<<pars[i]<<" ";
    }
    cout<<endl;

    ll ans=INT_MIN;
    ll res;
    for(i=l;i<=r;i++)
    {
        ll tval=calVal(vp2,i);
        // deb2(tval,i);
        if(ans<tval)
        {
            ans=tval;
            // deb1(i);
            res=i;
        }
        // ans=max(ans,calVal(vp2,i));
    }

    cout<<res<<endl;
}

int main()
{
    fastio
    int t=1;
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