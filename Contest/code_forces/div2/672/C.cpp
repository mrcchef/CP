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
        ll n,q,i;
        cin>>n>>q;
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        if(n==1)
        {
            cout<<v[0]<<endl;
            continue;
        }
        ll flag=0,ans=0;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                if(v[i]>v[i+1])
                {
                    ans+=v[i];
                    flag=1;
                }
            }
            else if(i==n-1)
            {
                if(flag==0)
                {
                    ans+=v[i];
                }
            }
            else
            {
                if(flag==0 && (v[i]>v[i-1] && v[i]>v[i+1]))
                {
                    ans+=v[i];
                    flag=1;
                }
                if(flag==1 && (v[i]<v[i-1] && v[i]<v[i+1]))
                {
                    ans-=v[i];
                    flag=0;
                }
            }
            
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