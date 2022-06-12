#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll int
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
        ll n,m,i;
        cin>>n>>m;
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        if(n>m)
        {
            cout<<0<<endl;
            return 0;
        }
        sort(v.begin(),v.end());
        ll ans=1;
        vi prev,curr;
        ll flag=0;
        for(i=1;i<n;i++)
        {
            curr.clear();
            ll diff=v[i]-v[i-1];
            if(diff==0)
            {
                flag=1;
                break;
            }
            ans=(1LL*ans*diff)%m;
            curr.pb(diff);
            for(auto x:prev)
            {
                ans=(1LL*ans*(x+diff))%m;
                curr.pb(x+diff);
            }
            prev=curr;
        }
        if(flag==1)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }
        

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