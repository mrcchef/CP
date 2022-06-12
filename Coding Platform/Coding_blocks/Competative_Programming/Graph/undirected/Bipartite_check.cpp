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

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

// Bipartitie Graph simply means that if we can divide the entire graph in 2 subset such that no set contains nbr's of it
// eg-> 1->2->3->4->1 it is a undirected graph.
// subset 1 -> (1,3) and subset 2 -> (2,4) here nbr's are in diffrenet set's
// we can also visualise this problem as coloring the entire graph with 2 colors such that 2 nbr should not have the same color

// to check it 
// 1) If cycle does not exist in the graph then it's a Bipartite graph
// 2) If there exist cycle 
        // a) if it is of even length then it's a Bipartite Graph
        // b) if it is of odd length then it's not a bipartite graph
// Instead of length we have used the concept of colors that if src and it's nbr has same color then it's not a bipartite graph


class Graph{
    list<ll> *l;
    ll V;
    public:
        Graph(ll V)
        {
            this->V=V;
            l=new list<ll>[V+1]; 
        }

        void add_edge(ll x,ll y)
        {
            l[x].pb(y);
            l[y].pb(x);
        }

        bool Bipartite_helper(ll src,ll visited[],ll parent,ll color)
        {
            visited[src]=color;
            
            for(auto nbr:l[src])
            {
                if(visited[nbr]==0)
                {
                    bool check=Bipartite_helper(nbr,visited,src,3-color);   // if color is 1 then 3-1=2 and vice versa
                    if(!check)
                    {
                        return false;
                    }
                }
                else if(parent!=nbr && visited[nbr]==color)  // color here == visited[src]
                {
                    return false;
                }
            }

            return true;

        }

        bool Bipartite_check(ll src)
        {
            ll visited[V+1]={0}; // 0 --> not visited, 1 --> visited with color 1 , 2 --> visited with color 2

            return Bipartite_helper(src,visited,-1,1);
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
        Graph g(v);
        fo(i,e)
        {
            cin>>x>>y;
            g.add_edge(x,y);
        }      
        
        bool check=g.Bipartite_check(y);
        
        if(check)
        {
            cout<<"Graph is Bipartite";
        }
        else
            cout<<"Graph is not a Bipartite";
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