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

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, 
// vertex u comes before v in the ordering. 
// Topological Sorting for a graph is not possible if the graph is not a DAG.

// DAG -> Directed graph with no directed cycle
// i.e. there is no way to start from a vertex v and following the consecutively directed edges and loop back to vertex v.

// Audio is there for explanation
//          1        here  1 -> 2, 1 -> 3 
//        /   \
//       2     3     then 2 -> 4, 3 -> 4
//        \   /
//          4

// Topological sort ->  starting from 1
// 1->3->2->4

template<typename T>

class Graph{
    map<T,list<T>> l;
    list<T> Topo;
    public:
        void add_edge(T x,T y)
        {
            l[x].pb(y);
            // l[y].pb(x);
        }

        void dfs_helper(T src,map<T,bool> &visited)
        {
            // cout<<src<<"->";
            visited[src]=true;
            for(auto val:l[src])
            {
                if(!visited[val])
                    dfs_helper(val,visited);
            }

            Topo.push_front(src); // Here we are inserting the src node in our list before returing from the src 
        }

        void DFS()
        {
            map<T,bool> visited;

            for(auto p:l)
            {
                visited[p.first]=false;
            }

            for(auto p:l)
            {
                T node=p.first;
                if(!visited[node])
                    dfs_helper(node,visited);
            }
           
        }

        void print()
        {
            for(auto it:Topo)
                cout<<it<<"-->";
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
        ll v,e,x,y,i;
        cin>>v>>e;
        Graph<ll> g;
        fo(i,e)
        {
            cin>>x>>y;
            g.add_edge(x,y);
        }
        g.DFS();
        g.print();
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