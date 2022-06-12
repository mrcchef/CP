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
    ll n,k,i;
    cin>>n>>k;
    vi v(n+1);
    fo(i,n)
        cin>>v[i+1];

    vi sm(n+1);
    ll tsm=0;
    fo(i,k)
        tsm+=v[i+1];
    
    sm[0]=0;
    sm[1]=tsm;
    // cout<<tsm<<" "; 
    for(i=2;i+k-1<=n;i++)
    {
        tsm+=(v[i+k-1]-v[i-1]);
        // cout<<tsm<<" ";
        sm[i]=tsm;
    }
    cout<<endl;

    vi prefmx(n+1);
    vector<pii> suffmx(n+5,{0,0});

    // prefmx[0]=0;
    // for(i=1;i+k<=n;i++)
    // {
    //     prefmx[i]=max(prefmx[i-1],sm[i]);
    // }

    suffmx[n-k+2].first=0;
    suffmx[n-k+2].second=n-k+2;
    for(i=n-k+1;i>=1;i--)
    {
        ll mx=suffmx[i+1].first;
        ll in=suffmx[i+1].second;
        if(mx<sm[i])
        {
            mx=sm[i];
            in=i;
        }
        else if(mx==sm[i])
            in=min(i,in);
        
        suffmx[i].first=mx;
        suffmx[i].second=in;
    }
    // for(i=1;i+k-1<=n;i++)
    //     cout<<suffmx[i].first<<" "<<suffmx[i].second<<endl;
    // cout<<endl;

    ll ans=INT_MIN;
    ll ansi,ansj;

    for(i=1;i+k<=n;i++)
    {
       ll lf=suffmx[i+k].first;
       ll in=suffmx[i+k].second;
    //    deb(sm[i]);
    //    deb(lf);
       if(ans<sm[i]+lf)
       {
        //    deb(ans);
           ans=sm[i]+lf;
        //    deb(ans);
           ansi=i;
           ansj=in;
       }
    }

    cout<<ansi<<" "<<ansj<<endl;
    // cout<<ans<<endl;

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