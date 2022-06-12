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
const ll mod = 998244353;
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

const ll C=1e3+5;

ll parent[C];
ll height[C];

struct node{
    ll st;
    ll ed;
    ll club;
};

bool compare(node &n1,node &n2)
{
    return n1.ed<n2.ed;
}

void init()
{
    for(ll i=0;i<C;i++)
    {
        parent[i]=i;
        height[i]=1;
    }
}

ll find_parent(ll node)
{
    if(node==parent[node])
        return node;
    
    return parent[node]=find_parent(parent[node]);
}

void union_set(ll club1,ll club2)
{
    ll p1=find_parent(club1);
    ll p2=find_parent(club2);

    if(height[p1]<height[p2])
    {
        parent[p2]=p1;
        height[p1]+=height[p2];
    }
    else
    {
        parent[p1]=p2;
        height[p2]+=height[p1];
    }
}

void solve()
{
    ll c,n,m;
    cin>>c>>n>>m;

    vector<node> vn;

    ll i;
    fo(i,c)
    {
        ll sz;
        cin>>sz;
        for(ll j=0;j<sz/2;j++)
        {
            node data;
            cin>>data.st>>data.ed;
            data.club=i+1;
            vn.pb(data);           
        }
    }

    sort(vn.begin(),vn.end(),compare);

    ll prev_club;
    ll prev_st=0;
    ll prev_ed=0;
    ll rest=0;

    fo(i,vn.size())
    {
        if(prev_ed>=vn[i].st)
        {
            union_set(prev_club,vn[i].club);

            prev_ed=max(prev_ed,vn[i].ed);
        }   
        else
        {
            rest+=vn[i].st-prev_ed+1;
            
            prev_club=vn[i].club;
            prev_st=vn[i].st;
            prev_ed=vn[i].ed;
        }
    }

    rest+=n-prev_ed;

    set<ll> s;
    for(i=1;i<=c;i++)
        s.insert(parent[i]);

    ll expo=s.size()+rest;
    trace2(s.size(),rest);

    ll ans=fxp(m,expo,mod);

    cout<<ans<<endl;
 
}

int main()
{
    fastio
    int t=1;
    cin>>t;
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