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
    ll n,m,i;
    cin>>n;
    vi v1(n);
    vi v;
    fo(i,n)
    {
        cin>>v1[i];
        v.pb(v1[i]);

    }
    cin>>m;
    vi v2(m);
    fo(i,m)
    {
        cin>>v2[i];
        v.pb(v2[i]);
    }
    // v.pb(0);
    // v.pb(INT_MAX);
    sort(v.begin(),v.end());
    v.resize(distance(v.begin(),unique(v.begin(),v.begin()+v.size())));

    ll a=3*n,b=3*m,diff=a-b;

    fo(i,v.size())
    {
        ll d=v[i];
        ll ta1=upper_bound(v1.begin(),v1.end(),d)-v1.begin();
        ll ta2=upper_bound(v2.begin(),v2.end(),d)-v2.begin();
        ll tb1=n-ta1;
        ll tb2=m-ta2;
        ll sc1=2*(ta1)+3*tb1;
        ll sc2=2*(ta2)+3*tb2;
        // deb(sc1-sc2);
        if(sc1-sc2>diff)
        {
            diff=sc1-sc2;
            a=sc1;
            b=sc2;
        }
        else if(sc1-sc2==diff)
        {
            if(a<sc1)
            {
                a=sc1;
                b=sc2;
            }
        }
    }

    cout<<a<<":"<<b<<endl;


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