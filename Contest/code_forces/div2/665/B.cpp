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
        ll x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1;
        cin>>x2>>y2>>z2;
        ll ans=0,o=INT_MAX;
        if(z1>0)
        {
            ll tmp=min(z1,y2);
            ans=2*tmp;
            z1=min(z1-tmp,o);
            y2=min(y2-tmp,o);
            if(z1>0)
            {
                ll tmp1=min(z1,z2);
                z1=min(z1-tmp1,o);
                z2=min(z2-tmp1,o);
                if(z1>0)
                {
                    ll tmp2=min(z1,x2);
                    z1=min(z1-tmp2,o);
                    x2=min(x2-tmp2,o);
                }
            }
        }
         if(y1>0)
        {
            ll tmp=min(y1,x2);
            y1=min(y1-tmp,o);
            x2=min(x2-tmp,o);
            if(y1>0)
            {
                ll tmp1=min(y1,y2);
                y1=min(y1-tmp1,o);
                y2=min(y2-tmp1,o);
            }
        }
        if(x1>0)
        {
            ll tmp=min(x1,z2);
            x1=min(x1-tmp,o);
            z2=min(z2-tmp,o);
            if(x1>0)
            {
                ll tmp1=min(x1,y2);
                x1=min(x1-tmp1,o);
                y2=min(y2-tmp1,o);
                if(x1>0)
                {
                    ll tmp2=min(x1,x2);
                    x1=min(x1-tmp2,o);
                    x2=min(x2-tmp2,o);
                }
            }
        }
        // deb(x1);
        // deb(x2);
        // deb(y1);
        // deb(y2);
        // deb(z1);
        // deb(z2);
        if(y1>0)
        {
            ll tmp=min(y1,z2);
            y1=min(y1-tmp,o);
            z2=min(z2-tmp,o);
            ans-=2*tmp;
        }
        // deb(x1);
        // deb(x2);
        // deb(y1);
        // deb(y2);
        // deb(z1);
        // deb(z2);
        
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