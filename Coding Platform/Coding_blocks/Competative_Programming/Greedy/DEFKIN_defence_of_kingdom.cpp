#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,tower;
        cin>>n>>m>>tower;
        vi r,c;
        for(ll i=0;i<tower;i++)
        {
            ll x,y;
            cin>>x>>y;
            r.pb(x);
            c.pb(y);
        }
        r.pb(0);
        c.pb(0);
        r.pb(n+1);
        c.pb(m+1);
        ll max_r=-1,max_c=-1,ans;
        sort(r.begin(),r.end());
        sort(c.begin(),c.end());
        for(ll i=1;i<r.size();i++)
        {
            max_r=max(max_r,r[i]-r[i-1]-1);
        }
        for(ll i=1;i<c.size();i++)
        {
            max_c=max(max_c,c[i]-c[i-1]-1);
        }
        // deb(max_r);
        // deb(max_c);
        ans=max_r*max_c;

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