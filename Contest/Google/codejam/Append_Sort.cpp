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
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":"<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
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

int t=1;
int tc=1;

ll pow10[10];

ll isSubNum(ll num1,ll num2)
{
    list<ll> l1,l2;

    while(num2)
    {
        ll rem2=num2%10;
        num2=num2/10;
        l2.push_front(rem2);
    }

    while(num1)
    {
        ll rem1=num1%10;
        num1=num1/10;
        l1.push_front(rem1);
    }
    ll sz=min(l1.size(),l2.size());

    ll digi1,digi2;

    ll retVal=-2;
    ll check=0;

    for(ll i=0;i<sz;i++)
    {
        digi1=l1.front();
        digi2=l2.front();
        l1.pop_front();
        l2.pop_front();
        trace2(digi1,digi2);
        if(digi1>digi2)
            check=1;

        if(check==0 && digi1<digi2)
            retVal=-1;

        trace1(retVal);

        if(digi1!=digi2)
            return retVal;
    }

    if(digi1==digi2==9)
        return retVal;
    
    return digi1;
}

void solve()
{
    ll n,i;
    cin>>n;
    vi v(n);
    fo(i,n)
    {
        cin>>v[i];
    }
    ll len=log10(v[0])+1;
    vi dv(n);
    dv[0]=v[0];

    ll ans=0;

    Fo(i,1,n-1)
    {
        if(dv[i-1]<v[i])
        {
            dv[i]=v[i];
            continue;
        }

        ll tlen=log10(v[i])+1;

        ll val=isSubNum(dv[i-1],v[i]);

        ll tnum=v[i];
        
        ll diff=len-tlen;

        if(val==-1)
        {
            ans+=diff;
            tnum*=pow10[diff];
        }
        else if(val>0)
        {
            tnum*=10;
            tnum+=val;
        
            ans+=diff;
            tnum*=pow10[diff-1];
        }
        else
        {
            ans+=diff+1;
            tnum*=pow10[diff+1];
        }

        trace6(i,dv[i-1],v[i],val,tnum,ans);

        dv[i]=tnum;
    }

    cout<<"Case #"<<tc<<": "<<ans<<endl;
}

int main()
{
    fastio
    pow10[0]=1;
    for(int i=1;i<10;i++)
        pow10[i]=pow10[i-1]*10;

    cin>>t;
    while(tc<=t)
    {
        solve();
        tc++;
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