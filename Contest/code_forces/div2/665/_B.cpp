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
        ll ans=0;
        vi v,v1;
        while(y1!=0)
        {
            v.pb(1);
            y1--;
        }
        while(z1!=0)
        {
            v.pb(2);
            z1--;
        }
        while(x1!=0)
        {
            v.pb(0);
            x1--;
        }
        while(x2!=0)
        {
            v1.pb(0);
            x2--;
        }
        while(y2!=0)
        {
            v1.pb(1);
            y2--;
        }
        
        while(z2!=0)
        {
            v1.pb(2);
            z2--;
        }
        // for(auto x:v)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x:v1)
        //     cout<<x<<" ";
        // cout<<endl;
        for(ll i=0;i<v.size();i++)
        {
            if(v[i]>v1[i])
                ans+=v[i]*v1[i];
            else if(v[i]<v1[i])
                ans-=v[i]*v1[i];
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