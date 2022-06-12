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

// Concept is pretty simple
// we just uses BFS and calculated is there any cycle which involves src node itself
// if it exist then we simply cal. the minimum length among the multiple cycles 
// if it doest not exist then no change in the ans
// this process we will repeat for all the nodes

// Note -> If we start from a src node and src node is there in the cycle then we get the correct ans for the minimum cycle in that BFS
//         That's why we have called BFS for all nodes such that we can get min. cycle length among them


class Graph{
    ll V;
    list<ll> *l;
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

        ll solve()
        {
            ll ans=INT_MAX;
            for(ll src=1;src<=V;src++)
            {
                BFS(src,ans);
            }
            return ans;
        }

        void BFS(ll src,ll &ans)
        {
            vi dist(V+1,INT_MAX);
            queue<ll> Q;
            Q.push(src);
            dist[src]=0;

            while(!Q.empty())
            {
                ll node=Q.front();
                Q.pop();
                for(auto nbr:l[node])
                {
                    if(dist[nbr]==INT_MAX)
                    {
                        dist[nbr]=dist[node]+1;
                        Q.push(nbr);
                    }
                    else if(dist[nbr]>=dist[node])  // As we know that the distance of parent node from src node is less that 
                    {                               // the distance of child node from src node
                        ans=min(ans,dist[nbr]+dist[node]+1); // this condition is just to check the parent (nbr) of node 
                    }                               // i.e. nbr should not be the parent of node
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
        ll v,e,i;
        cin>>v>>e;
        Graph g(v);
        fo(i,e)
        {
            ll x,y;
            cin>>x>>y;
            g.add_edge(x,y);
        }
        ll ans=g.solve();
        if(ans==INT_MAX)
            cout<<"Cycle not present"<<endl;
        else
            cout<<"Minimum length of cycle: "<<ans<<endl;
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