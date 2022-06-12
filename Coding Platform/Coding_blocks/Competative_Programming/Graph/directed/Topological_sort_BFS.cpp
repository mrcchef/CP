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

// Zero based indexing 
// Here we are finding topological sort using BFS
// Audio is Available

class Graph
{
    list<ll> *l;
    ll V;
    ll *Indegree;
    public:
        Graph(ll V)
        {
            this->V=V;
            l=new list<ll>[V];
            Indegree=new ll[V]{0};
        }

        void add_edge(ll x,ll y)
        {
            l[x].pb(y);
            Indegree[y]++;
        }
        // Indegree of all the vertexes 
        // void print_In()
        // {
        //     for(auto i=0;i<V;i++)
        //         cout<<Indegree[i]<<" ";
        //     cout<<endl;
        // }

        void BFS()
        {
            map<ll,bool> visited;
            queue<ll> Q;

            for(ll i=0;i<V;i++)
            {
                if(Indegree[i]==0)
                {
                    Q.push(i);
                    visited[i]=true;
                }
            }

            while(!Q.empty())
            {
                ll node=Q.front();
                Q.pop();
                cout<<node<<"-->";
                for(auto nbr:l[node])
                {
                    if(!visited[nbr])
                    {
                        visited[nbr]=false;
                        Indegree[nbr]--;
                        if(Indegree[nbr]==0)
                        {
                            Q.push(nbr);
                        }
                    }
                    
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
        ll v,e,x,y,i;
        cin>>v>>e;
        Graph g(v);
        fo(i,e)
        {
            cin>>x>>y;
            g.add_edge(x,y);
        }
        // g.print_In();
        g.BFS();
        
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