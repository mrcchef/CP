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
// euler 3 is the most important one, other also do the work
class Graph{
    ll V;
    list<ll> *l;
    ll root;
    ll *time_in,*time_out;
    ll time;
    public:
        Graph(ll V)
        {
            this->V=V;
            l=new list<ll>[V+1];
            time_in=new ll[V+1];
            time_out=new ll[V+1];
            root=1;
            time=0;// euler 3
            // time=1// euler 1 and 2
        }

        void add_edge(ll x,ll y)
        {
            l[x].pb(y);
            l[y].pb(x);
        }

        void euler_tour1(ll cur,bool visited[]) // time stuff needs rectification
        {
            visited[cur]=true;
            cout<<cur<<" ";
            time_in[cur]=time++;
            for(auto nbr:l[cur])
            {
                if(visited[nbr])
                    continue;
                euler_tour1(nbr,visited);
                time_out[cur]=time++;
                cout<<cur<<" ";
            }
        }

        void euler_tour2(ll cur,bool visited[])
        {
            visited[cur]=true;
            cout<<cur<<" ";
            time_in[cur]=time++;
            for(auto nbr:l[cur])
            {
                if(visited[nbr])
                    continue;
                euler_tour2(nbr,visited);
            }
            cout<<cur<<" ";
            time_out[cur]=time++;
        }

        void euler_tour3(ll cur,bool visited[])
        {
            visited[cur]=true;
            cout<<cur<<" ";
            time_in[cur]=++time;
            for(auto nbr:l[cur])
            {
                if(visited[nbr])
                    continue;
                euler_tour3(nbr,visited);
                // cout<<cur<<" ";
            }
            time_out[cur]=time;
        }

        void dfs()
        {
            bool visited1[V]={false};
            bool visited2[V]={false};
            bool visited3[V]={false};

            euler_tour1(root,visited1);
            cout<<endl;
            // euler_tour2(root,visited2);
            // cout<<endl;
            
            // euler_tour3(root,visited3);
            // cout<<endl;
            for(ll i=1;i<=V;i++)
                cout<<time_in[i]<<" "<<time_out[i]<<endl;
        }

        bool is_ancestor(ll x,ll y)
        {
            if(time_in[x]<time_in[y] && time_out[x]>time_out[y])
                return true;
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
        ll n,i,q;
        cin>>n;
        Graph g(n);
        fo(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            g.add_edge(x,y);
        }
        g.dfs();
        cin>>q;
        fo(i,q)
        {
            ll x,y;
            cin>>x>>y;
            if(g.is_ancestor(x,y)) // x is the ansector of y
            {
                cout<<"YES";
            }
            else
            {
                cout<<"NO";
            }
            cout<<endl;
            
        }
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