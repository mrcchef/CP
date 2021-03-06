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

// zero based indexing

class Graph
{
    ll V;
    list<pair<ll,ll>> *l;
    public:
        Graph(ll V)
        {
            this->V=V;
            l=new list<pair<ll,ll>>[V];
        }

        void add_edge(ll x,ll y,ll w)
        {
            l[x].pb({y,w});
            l[y].pb({x,w});
        }

        ll prims()
        {
            // we have used priority queue such that we can get the next minimum available edge in log(N) time
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
            bool *visited=new bool[V]{false};
            ll ans=0;
            
            pq.push({0,0});

            while(!pq.empty())
            {
                pii node=pq.top();
                pq.pop();

                ll v=node.second;
                ll w=node.first;

                if(visited[v]) // if node is visited then continue;
                {
                    continue;
                }

                ans+=w;  // if the node is not visited then simply add this to our ans and mark it visited
                visited[v]=true;

                for(auto nbr:l[v])// now we are adding the the nbr's of the node b/c now all the nbr's node is also available.
                {
                    if(visited[nbr.first]==false)
                    {
                        pq.push({nbr.second,nbr.first});
                    }
                }

            }
            
            return ans;
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
        cin>>v>>e;
        Graph g(v);
        fo(i,e)
        {
            ll x,y,w;
            cin>>x>>y>>w;
            g.add_edge(x,y,w);
        }

        cout<<g.prims();

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