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

const ll N=(1<<17)+5;

ll seg[4*N+1],arr[N];


void build(ll node,ll l,ll r,ll parity)
{
    if(l==r)
    {
        seg[node]=arr[l];
        return;
    }

    ll mid=(l+r)/2;

    build(2*node,l,mid,parity^1);
    build(2*node+1,mid+1,r,parity^1);

    if(parity)
    {
        seg[node]=seg[2*node] | seg[2*node+1];
    }
    else
    {
        seg[node]=seg[2*node] ^ seg[2*node+1];
    }
}

void update(ll node,ll l,ll r,ll parity,ll val,ll in)
{
    if(l==r)
    {
        seg[node]=val;
        return;
    }

    ll mid=(l+r)/2;

    if(in<=mid)
        update(2*node,l,mid,parity^1,val,in);
    else
        update(2*node+1,mid+1,r,parity^1,val,in);

    if(parity)
    {
        seg[node]=seg[2*node] | seg[2*node+1];
    }
    else
    {
        seg[node]=seg[2*node] ^ seg[2*node+1];
    }
}

void solve()
{
    ll n,m,i;
    cin>>n>>m;
    ll sz=1<<n;
    fo(i,sz)
        cin>>arr[i];

    build(1,0,sz-1,n&1);
    // fo(i,sz)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    fo(i,m)
    {
        ll in,val;
        cin>>in>>val;
        update(1,0,sz-1,n&1,val,in-1);
        cout<<seg[1]<<endl;
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