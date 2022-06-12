#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll unsigned int
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

// ll dx[]={-1,0,1,0};
// ll dy[]={0,-1,0,1};

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

    ll n=1e4+5LL;

    vi res(n+1);
    ll pos=1;

    res[1]=1;

    ll nxt_i2,nxt_i3,nxt_i5;

    nxt_i2=2;
    nxt_i3=3;
    nxt_i5=5;


    ll i2,i3,i5;
    i2=i3=i5=1;

    // mii m;

    // m[1]=1;

    for(ll i=2;i<=n;i++)
    {
        
        ll mn=min(nxt_i2,min(nxt_i3,nxt_i5));
        
        // if(m[mn]==1)
        //     continue;
        res[i]=mn;
        
        if(mn==nxt_i2)
        {
            i2++;
            nxt_i2=res[i2]*2;
        }
        if(mn==nxt_i3)
        {
            i3++;
            nxt_i3=res[i3]*3;
        }
        if(mn==nxt_i5)
        {
            i5++;
            nxt_i5=res[i5]*5;
        }
    }

    // for(ll i=1;i<=11;i++)
    //     cout<<res[i]<<" ";
    //     cout<<endl;

    int t;
    cin>>t;
    while(t--)
    {
        ll cal;
        cin>>cal;
        cout<<res[cal]<<endl;
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