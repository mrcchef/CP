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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll sum_n(ll n)
{
    return ((n*(n+1))/2)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll ans=0;
        ll n=s.size();
        ll val=1;
        ll digit[n];
        ll power[n];
        digit[0]=1;
        power[0]=1;
        for(ll i=1;i<n;i++)
        {
            val=val*10;
            val%=mod;
            power[i]=val;
            ll temp=(val*(i+1));
            temp%=mod;
            digit[i]=temp;
        }
        // for(auto x:power)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x:digit)
        //     cout<<x<<" ";
        // cout<<endl;
        ll sm[n+1]={0};
        for(ll i=1;i<=n;i++)
        {
            sm[i]=sm[i-1]+digit[i-1];
            sm[i]%=mod;
        }
        // for(auto x:sm)
        //     cout<<x<<" ";
        // cout<<endl;
        for(ll i=0;i<n;i++)
        {
            ans+=((sum_n(i)*power[n-i-1])%mod+(sm[n-(i+1)])%mod)*(s[i]-'0');
            ans%=mod;
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