#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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

// This is a kosaraju algorithm for calculating Strongly connected component
// step 1-> cal an ordering of DFS in a vector
// step 2-> create a reverse directed graph
// step 3-> Perform DFS according to the ordering calculation in step 1 and each DFS call will gives us a SCC
//          DFS call is from right to left 

// Audio is available

class Graph
{
    list<ll> *l,*rl;
    ll V;
    vi order;
    public:
        Graph(ll V)
        {
            this->V=V;
            l=new list<ll>[V];
            rl=new list<ll>[V];
        }

        void add_edge(ll x,ll y)
        {
            l[x].pb(y);
            rl[y].pb(x);
        } 

        void dfs_helper(ll src,vi &visited)
        {
            visited[src]=1;
            
            for(auto nbr:l[src])
            {
                if(visited[src]==0)
                    dfs_helper(nbr,visited);
            }

            order.pb(src);
        }

        void DFS()
        {
            vi visited(V,0);
            
            for(ll i=0;i<V;i++)
            {
                if(visited[i]==0)
                {
                    dfs_helper(i,visited);
                }
            }
        }

        void rdfs_helper(ll src,vi &visited)
        {
            visited[src]=1;
            cout<<src<<"-->";
            
            for(auto nbr:rl[src])
            {
                if(visited[nbr]==0)
                {
                    rdfs_helper(nbr,visited);
                }
            }
        }

        void rDFS()
        {
            vi visited(V,0);
            ll cnt=0;
            for(ll i=0;i<V;i++)
            {
                if(visited[i]==0)
                {
                    cout<<"SCC "<<++cnt<<": ";
                    rdfs_helper(i,visited);
                    cout<<endl;
                }
            }
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
        ll v,e,i,x,y;
        cin>>v>>e;
        Graph g(v);
        fo(i,e)
        {
            cin>>x>>y;
            g.add_edge(x,y);
        }

        g.DFS();
        g.rDFS();


        
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