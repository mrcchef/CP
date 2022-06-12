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
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

bool check(vi &v,ll n,ll x)
{
    ll i,j=0;
    ll checkx=0;
    for(i=0;i<n;i++)
    {
        ll diff=v[i]-v[j];
        if(diff<x)
            continue;
        else if(diff==x)
        {
            checkx=1;
            break;
        }
        else
        {
            while(v[i]-v[j]>x)
            {
                j++;
            }
        }
    }
    if(v[i-1]-v[j]==x)
        checkx=1;
    return checkx;
}

void solve()
{
    ll n,l,x,y;
    cin>>n>>l>>x>>y;
    ll i,j;
    vi v(n);
    mii hm;
    fo(i,n)
    {
        cin>>v[i];
        hm[v[i]]=1;
    }
    j=0;
    ll checkx=check(v,n,x),checky=check(v,n,y);
    
    if(checkx and checky)
    {
        cout<<0<<endl;
        return;
    } 
    else if(checkx)
    {
        cout<<1<<endl;
        cout<<y<<endl;
    }
    else if(checky)
    {
        cout<<1<<endl;
        cout<<x<<endl;
    }
    else
    {
        i=0,j=0;
        ll flag=0;
        ll ans;
        for(i;i<n;i++)
        { 
            ll ele=v[i]+x;
            if(ele<=l)
                if((hm[ele-y] && ele-y>0) || hm[ele+y] ) 
                {
                    flag=1;
                    ans=ele;
                // break;
                }
            ll ele1=v[i]-x;
            if(ele1>0 && ele1<=l)
            {
                if((hm[ele1-y] && ele1-y>0) || hm[ele1+y])
                {
                    flag=1;
                    ans=ele1;
                    // break;
                }
            }
        }
        
        if(flag)
        {
            cout<<1<<endl;
            cout<<ans<<endl;
        }
        else
        {
            cout<<2<<endl;
            cout<<x<<" "<<y<<endl;
        }
    }


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