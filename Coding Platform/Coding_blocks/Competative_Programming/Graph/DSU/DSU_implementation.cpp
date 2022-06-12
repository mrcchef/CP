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

// DSU stands for Disjoint sets and union
// Time Complexity without any optimisation
// 1) Find -> O(n)
// 2) Union -> O(n)

// --> Here we have created a list of edges i.e for an graph, list l will have all the edges
// --> Parent array stores the parent of a vertex and intially parents of all the vertexes are intialised to -1 i.e 
//          that particular vertex is parent of itself
// --> Find_set funtion returns the super parent of the set i.e the vertex which is parent of itself 
// --> Union_set function perform union operation b/w two disjoint set and on successful union operation 
//          It returns true but, if there both the elements are already a member of same set, then operation would not 
//          take place and there it returns false .


class Graph{
    ll V;
    list<pair<ll,ll>> l;
    public:
        Graph(ll V)
        {
            this->V=V;
        }

        void add_edge(ll x,ll y)
        {
            l.pb({x,y});
        }

        ll find_set(ll i,ll parent[])
        {
            if(parent[i]==-1)
                return i;
            return find_set(parent[i],parent);
        }

        bool union_set(ll i,ll j,ll parent[])
        {
            ll s1=find_set(i,parent);
            ll s2=find_set(j,parent);

            if(s1!=s2)
            {
                parent[s1]=s2;
                return true;
            }
            else
            {
                return false;
            }
        }

        bool cycle_detection()
        {
            ll *parent=new ll[V];
            for(ll i=0;i<V;i++)
                parent[i]=-1;

            for(auto edge:l)
            {
                ll i=edge.first;
                ll j=edge.second;

                if(union_set(i,j,parent)==false)
                    return true;
            }
            return false;
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

        if(g.cycle_detection())
            cout<<"Cycle is present";
        else 
            cout<<"Cycle is not present";
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