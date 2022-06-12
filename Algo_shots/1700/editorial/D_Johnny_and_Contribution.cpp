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
// Did not get this question
class Graph{
    ll V;
    list<ll> *l;
    ll root;
    bool flag=false;
    vi res;
    public:
        Graph(ll V)
        {
            this->V=V;
            l=new list<ll>[V];
            root=0;
        }

        void add_edge(ll x,ll y)
        {
            l[x].pb(y);
            l[y].pb(x);
        }

        void dfs_helper(ll cur,bool visited[],vi v)
        {
            visited[cur]=true;
            res.pb(cur);
            ll mn=INT_MAX;
            ll node;
            for(auto nbr:l[cur])
            {
                if(visited[nbr])
                    continue;
                if(v[cur]==v[nbr])
                {
                    flag=true;
                    return; 
                }
                if(mn>v[nbr])
                {
                    node=nbr;
                    mn=v[nbr];
                }
            }
                dfs_helper(node,visited,v);
        }

        void dfs(vi v)
        {
            bool visited[V]={false};

            for(ll i=0;i<V;i++)
            {
                if(visited[i])
                    continue;
                dfs_helper(i,visited,v);
            }

            if(flag)
            {
                cout<<-1<<endl;
            }
            else
            {
            for(auto x:res)
                cout<<x+1<<" ";
            cout<<endl;
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
        ll n,m,i;
        cin>>n>>m;
        Graph g(n);
        fo(i,m)
        {
            ll x,y;
            cin>>x>>y;
            g.add_edge(x-1,y-1);
        }

        vi v(n);
        fo(i,n) 
            cin>>v[i];
        
       g.dfs(v);

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