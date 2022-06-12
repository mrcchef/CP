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
    ll *s,*a;
    ll root;
    ll ans;
    public:
    Graph(ll V)
    {
        this->V=V;
        l=new list<ll>[V];
        s=new ll[V];
        a=new ll[V];
        root=0;
        ans=0;
    }

    void add_edge(ll x,ll y)
    {
        l[x].pb(y);
        l[y].pb(x);
    }

    void add_val(ll x,ll val)
    {
        s[x]=val;
    }

    void dfs_helper(ll src,bool *visited,ll par)
    {
        visited[src]=true;

        if(s[src]==-1)
        {
            ll mn=INT_MAX;
            for(auto nbr:l[src])
            {
                if(nbr!=par)
                    mn=min(mn,s[nbr]);
            }

            if(mn==INT_MAX)
            {
                mn=s[par];
            }
 
            s[src]=mn;
        }
        
        if(par!=-1)
            a[src]=s[src]-s[par];
        else
        {
            a[src]=s[src];
        }

        for(auto nbr:l[src])
        {
            if(visited[nbr])
                continue;
            dfs_helper(nbr,visited,src);     
        }

        ans+=a[src];

    }

    void dfs()
    {
        bool visited[V]={false};

        dfs_helper(root,visited,-1);

        ll flag=0;

        for(ll i=0;i<V;i++)
        {
            if(a[i]<0)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            cout<<-1;
        }
        else
        {
            cout<<ans;
        }
        cout<<endl;
        
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
        vi p(n),s(n);
        fo(i,n-1)
        {
            cin>>p[i];
            g.add_edge(i+1,p[i]-1);
        }
        fo(i,n)
        {
            cin>>s[i];
            g.add_val(i,s[i]);
        }

        // fo(i,)

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