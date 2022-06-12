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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,k,i;
        cin>>n>>k;
        vi a(n+1),t(n+1);

        fo(i,n)
        {
            cin>>a[i+1];
        }
        fo(i,n)
        {
            cin>>t[i+1];
        }

        vi sma(n+1),smt(n+1);

        sma[0]=smt[0]=0;

        Fo(i,1,n)
        {
            sma[i]=sma[i-1]+a[i];
            smt[i]=smt[i-1];
            if(t[i]==1)
                smt[i]+=a[i];
            // deb(smt[i]);
        }

        // fo(i,n+1)
        // {
        //     cout<<sma[i]<<" ";
        // }
        // cout<<endl;
        // // smt[n+1]=smt[n];
        // fo(i,n+2)
        // {
        //     cout<<smt[i]<<" ";
        // }
        // cout<<endl;


        ll ans=0;

        for(i=1;i+k-1<=n;i++)
        {
            ans=max(ans,smt[i-1]+sma[i+k-1]-sma[i-1]+smt[n]-smt[i+k-1]);
            // deb(ans);
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