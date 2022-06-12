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

bool compare(pii &p1,pii &p2)
{
    if(p1.second==p2.second)
        return p1.first>p2.first;
    return p1.second<p2.second;
}

bool comp1(pii &p1,pii &p2)
{

}

pii searchVal(pii val,vector<pii> &vp)
{
    pii res;
    ll digit=-1;
    for(auto p:vp)
    {
        if(p.second<=val.second && p.first>=val.first)
        {   
            if(digit<p.first)
            {
                digit=p.first;
                res.first=p.first;
                res.second=p.second;
            }
        }
    }

    return res;
}

void solve()
{
    ll n,i,v;
    cin>>v;
    
    vector<pii> vp;

    ll mn=INT_MAX;
    mii m;

    fo(i,9)
    {
        ll x;
        cin>>x;
        mn=min(mn,x);
        vp.pb({i+1,x});
        m[i+1]=x;
    }

    sort(vp.begin(),vp.end(),compare);

    // for(auto val:vp)
    // {
    //     cout<<val.first<<" "<<val.second<<endl;
    // }

    pii p=vp[0];

    ll cnt[10]={0};

    ll digit=p.first;
    if(v<p.second)
    {
        cout<<-1;
        return;
    }

    ll c=v/p.second;
    v-=c*p.second;

    cnt[digit]=c;

    for(i=1;i<=c;i++)
    {
        ll aval=v+m[digit];
        cnt[digit]--;
        p=searchVal({digit,aval},vp);

        aval-=p.second;
        cnt[p.first]++;
        v=aval;
    }

    for(i=9;i>=1;i--)
    {
        while(cnt[i])
        {
            cout<<i;
            cnt[i]--;
        }
    }
    cout<<endl;




    
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