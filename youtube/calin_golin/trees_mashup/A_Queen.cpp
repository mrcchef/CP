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
    ll *c,*p;
    ll V;
    ll root;
    set<ll> res;
    public:
    Graph(ll V)
    {
        this->V=V;
        l=new list<ll>[V];
        c=new ll[V];
        p=new ll[V];
    }

    void add_edge(ll x,ll y,ll val)
    {
        if(y==-2)
        {
            root=x;
            c[x]=0;
        }
        else
        {
            l[y].pb(x);
            p[x]=y;
            c[x]=val;
        }
    }

    void dfs_helper(ll src,bool *visited)
    {
        visited[src]=true;
        // cout<<src<<" ";

        if(c[src]==1)
        {
            ll flag=0;
            for(auto nbr:l[src])
            {
                if(c[nbr]==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                // for(auto nbr:l[src])
                //     l[p[src]].pb(nbr);
                res.insert(src);
            }
        }

        for(auto nbr:l[src])
        {
            if(visited[nbr])
                continue;
            dfs_helper(nbr,visited);
        }
    }

    void dfs()
    {
        bool visited[V]={false};
        ll i;
        // fo(i,V)
        //     cout<<visited[i]<<" ";

        // deb(root);
        dfs_helper(root,visited);
    }

    void output()
    {
        if(res.size()==0)
            cout<<-1<<endl;
        else
        for(auto it:res)
        {
            cout<<it+1<<" ";
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
        vi v(n),c(n);
        Graph g(n);
        fo(i,n)
        {
            cin>>v[i]>>c[i];
            g.add_edge(i,v[i]-1,c[i]);
        }
        g.dfs();

        g.output();


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