#include <bits/stdc++.h>
using namespace std;
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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

class Graph
{
    list<ll> *l;
    ll V;
    ll *s,*a,*temp;
    ll root;
    ll ans;
    ll sm,add;
    public:
    Graph(ll V)
    {
        this->V=V;
        l=new list<ll>[V];
        s=new ll[V];
        a=new ll[V];
        temp=new ll[V];
        root=0;
        ans=0;
        sm=0;
        add=0;
    }

    void add_edge(ll x,ll y)
    {
        l[x].pb(y);
        l[y].pb(x);
    }

    void add_val(ll x,ll val)
    {
        a[x]=val;
        add+=val;
    }

    void dfs_helper(ll src,bool *visited,ll len)
    {
        visited[src]=true;

        sm+=len*a[src];

        s[src]=a[src];

        for(auto nbr:l[src])
        {
            if(visited[nbr])
                continue;
            dfs_helper(nbr,visited,len+1);
            s[src]+=s[nbr];     
        }  

    }

    void dfs()
    {
        bool visited[V]={false};

        dfs_helper(root,visited,0);
        
    }

    void dfs_helper2(ll src,bool *visited,ll par)
    {
        visited[src]=true;
        if(par==-1)
            ans=temp[0];
        else
        {
            temp[src]=temp[par]-2*s[src]+add;
            ans=max(ans,temp[par]-2*s[src]+add);
        }
    

        for(auto nbr:l[src])
        {
            if(visited[nbr])
                continue;
            dfs_helper2(nbr,visited,src);
        }
    }

    void solve()
    {
        bool visited[V]={false};
        
        temp[0]=sm;

        dfs_helper2(root,visited,-1);

        cout<<ans<<endl;

    }

};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v(n);
        Graph g(n);
        fo(i,n)
        {
            cin>>v[i];
            g.add_val(i,v[i]);
        }
        fo(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            g.add_edge(x-1,y-1);
        }

        g.dfs();
        g.solve();
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