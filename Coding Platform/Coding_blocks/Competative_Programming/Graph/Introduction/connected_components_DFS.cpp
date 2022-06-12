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

template<typename T>

class Graph{
    map<T,list<T>> l;
    public:
        void add_edge(T x,T y)
        {
            l[x].pb(y);
            l[y].pb(x);
        }

        void dfs_helper(T src,map<T,bool> &visited)
        {
            cout<<src<<" ";
            visited[src]=true;
            for(auto val:l[src])
            {
                if(!visited[val])
                {
                    dfs_helper(val,visited);
                }
            }
        }

        void DFS()
        {
            map<T,bool> visited;

            for(auto p:l)
            {
                visited[p.first]=false;
            }

            ll cnt=0;
            for(auto p:l)
            {
                T node=p.first;
                if(!visited[node])
                {
                    cnt++;
                    cout<<"Compnent "<<cnt<<"-->";
                    dfs_helper(node,visited);
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
        Graph<ll> g;
        g.add_edge(1,2);
        g.add_edge(2,3);
        g.add_edge(3,4);
        g.add_edge(1,4);
        g.add_edge(1,5);

        g.add_edge(6,7);
        g.add_edge(7,8);

        g.add_edge(9,9);

        g.DFS();


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