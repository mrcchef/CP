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
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

const ll N=1e6+1;
const ll K=1e6+1;

vector<vector<ll>> g(N);

ll parent[N];
ll node_rank[N];

ll find_par(ll node)
{
    if(parent[node]==-1)
        return node;
    
    return parent[node]=find_par(parent[node]);
}

bool check_unite(ll node1,ll node2)
{
    ll p1=find_par(node1);
    ll p2=find_par(node2);
    return p1==p2;
}
bool unite(ll node1,ll node2)
{
    ll p1=find_par(node1);
    ll p2=find_par(node2);
    
    if(p1!=p2)
    {
        if(node_rank[p1]<node_rank[p2])
        {
            parent[node1]=node2;
            node_rank[p2]+=node_rank[p1];
        }
        else
        {
            parent[node2]=node1;
            node_rank[p1]+=node_rank[p2];
        }
        return true;
    }
    else
    {
        return false;
    }
}


void init()
{

    for(ll i=0;i<N;i++)
    {
        g[i].clear();
        node_rank[i]=1;
        parent[i]=-1;
    }
}

void solve()
{
    ll n,k,i;
    cin>>n>>k;
    vector<pii> notEqual;
    fo(i,k)
    {
        ll x,y;
        string s;
        cin>>x>>s>>y;

        if(s=="=")
        {
            unite(x,y);
        }
        else
        {
            notEqual.pb({x,y});
        }
    }
    ll flag=0;
    for(auto node:notEqual)
    {
        // vi src=n/ode;
            if(check_unite(node.first,node.second))
            {
                // cout<<i<<" "<<nbr<<endl;
                flag=1;
                break;
            }
    }

    if(!flag)
    {
        cout<<"YES";
    }
    else
        cout<<"NO";
    cout<<endl;
}

int main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        init();
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