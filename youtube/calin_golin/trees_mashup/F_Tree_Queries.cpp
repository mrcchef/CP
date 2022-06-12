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
    ll *dep,*st,*ed,*p;
    ll root,time;
    public:
    Graph(ll V)
    {
        this->V=V;
        l=new list<ll>[V];
        dep=new ll[V];
        st=new ll[V];
        ed=new ll[V];
        p=new ll[V];
        root=0;
        time=-1;
    }

    void add_edge(ll x,ll y)
    {
        l[x].pb(y);
        l[y].pb(x);
    }


    void dfs_helper(ll src,bool *visited,ll len,ll par)
    {
        visited[src]=true;

        dep[src]=len;

        p[src]=par;

        st[src]=++time;

        for(auto nbr:l[src])
        {
            if(visited[nbr])
                continue;
            dfs_helper(nbr,visited,len+1,src);   
        }  

        ed[src]=time;

    }

    void dfs()
    {
        bool visited[V]={false};

        dfs_helper(root,visited,0,-1);
        
    }

    void solve(ll k,ll *val)
    {
        ll lowest=val[0];

        // for(ll j=0;j<k;j++)
        //     cout<<val[j]<<" ";
        // cout<<endl;

        for(ll j=1;j<k;j++)
            if(dep[val[j]]>dep[lowest])
                lowest=val[j];

        ll flag=0;
        
        // cout<<lowest<<endl;

        for(ll j=0;j<k;j++)
        {
            ll ele=val[j];
            if(val[j]!=0)
            {
                ele=p[val[j]];
            }

            if(!(st[ele]<=st[lowest] && ed[ele]>=st[lowest]))
            {
                flag=1;
                break;
            }
            
        }

        if(flag==0)
            cout<<"YES";
        else
        {
            cout<<"NO";
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
        ll n,i,q;
        cin>>n>>q;
        Graph g(n);
        fo(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            g.add_edge(x-1,y-1);
        }

        g.dfs();

        fo(i,q)
        {
            ll k,j;
            cin>>k;
            ll val[k];
            fo(j,k)
            {
                cin>>val[j];
                val[j]--;
            }

            
        // for(ll j=0;j<k;j++)
        //     cout<<val[j]<<" ";
        // cout<<endl;
            
            g.solve(k,val);
        }


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