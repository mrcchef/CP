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

// Assuming there is a signle dis-joint graph
// If there were more dis-joint graph then we can iterate all the nodes and call DFS to the dis-joint graph which is not visited

//  1->2->3->4->1 here in this undirected graph, when we reach at 4 and try to visit it's nbr's then we encouter 1 which is 
//  visited and not a parent of 4.

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

        // Condition for cycle detection 
        // If at any node we encounter that their nbr's except it's parent is visited then, there is a cycle;

        bool cycle_helper(ll src,map<ll,bool> &visited,ll parent)
        {
            visited[src]=true;
            for(auto nbr:l[src])
            {
                if(!visited[nbr])       // if not visited them we move to next node and try to detect cycle
                {
                    ll check=cycle_helper(nbr,visited,src);  // true if, cycle is detected from the nbr
                    if(check)
                        return true; 
                }
                else if(nbr!=parent)   // if nbr is visited and not equal to parent then thier must be some other node which is already 
                {                      // visited and now we can again visit than nbr through the node 
                    return true;       // i.e cycle is their
                }
            }
            return false;
        }

        bool cycle_detection(ll src)
        {
            map<ll,bool> visited;
            visited[src]=true;

            return cycle_helper(src,visited,-1);
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
        ll v,e,i;
        ll x,y;
        cin>>v>>e;
        Graph g(v);
        fo(i,e)
        {
            cin>>x>>y;
            g.add_edge(x,y);
        }

        bool ans=g.cycle_detection(y);
        if(ans)
            cout<<"Yes, Cycle is present";
        else 
            cout<<"No, Cycle is not present";

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