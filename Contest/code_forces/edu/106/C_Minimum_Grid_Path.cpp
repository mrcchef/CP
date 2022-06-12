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
    ll n,i;
    cin>>n;
    vi v(n+1);
    fo(i,n)
        cin>>v[i+1];

    ll cost=n*v[2]+n*v[1];
    ll mnh,mnv,smh,smv;
    smh=mnh=v[1];
    smv=mnv=v[2];
    ll cnh=1;
    ll cnv=1;
    mii mh;
    mii mv;
    // mh[v[1]]=1;
    // mv[v[2]]=1;

    for(i=3;i<=n;i++)
    {
        ll tcost;
        if(i&1)
        {
            mnh=min(mnh,v[i]);
            smh+=v[i];
            cnh++;
            // deb(smh);
            // deb(mnh);
            // deb(n-cnh+1);
        }
        else
        {
            mnv=min(mnv,v[i]);
            smv+=v[i];
            cnv++;
            tcost=smv-mnv+mnv*(n-cnv+1);
        }
        tcost=smh-mnh+mnh*(n-cnh+1)+smv-mnv+mnv*(n-cnv+1);
        // deb(tcost);
        cost=min(cost,tcost);
    }
    cout<<cost<<endl;
    
}

int main()
{
    fastio
    int t;
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