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
    ll root;
    double ans;
    public:
    Graph(ll V)
    {
        this->V=V;
        l=new list<ll>[V];
        root=0;
        ans=0;
    }

    void add_edge(ll x,ll y)
    {
        l[x].pb(y);
        l[y].pb(x);
    }

    void dfs_helper(ll src,bool *visited,double prob,double len)
    {
        visited[src]=true;

        double cnt=1;
        double tm=0;

        for(auto nbr:l[src])
            if(!visited[nbr])
                tm++;
        
        cnt/=tm;


        // deb(cnt);

        for(auto nbr:l[src])
        {
            if(visited[nbr])
                continue;
            dfs_helper(nbr,visited,prob*cnt,len+1);
        }
        
        if(l[src].size()==1)
        {
            ans+=prob*len;
        }
    }

    void dfs()
    {
        bool visited[V]={false};
        double p=1;
        ll len=l[root].size();

        dfs_helper(root,visited,p,0);

        cout<<setprecision(12)<<ans<<endl;
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
        Graph g(n);
        fo(i,n-1)
        {
            ll x,y;
            cin>>x>>y;

            g.add_edge(x-1,y-1);
            
        }

        g.dfs();

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