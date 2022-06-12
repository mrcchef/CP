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

class Graph
{
    map<T,list<T>> l;
    public:
        void add_edge(T x,T y)
        {
            l[x].pb(y);
        }

        ll BFS(T src,T dest)
        {
            map<T,ll> dist;
            map<T,ll> parent;
            queue<T> Q;

            for(auto p:l)
            {
                dist[p.first]=INT_MAX;
            }

            Q.push(src);
            dist[src]=0;
            parent[src]=src;

            while(!Q.empty())
            {
                T node=Q.front();
                Q.pop();
                for(auto val:l[node])
                {
                    if(dist[val]==INT_MAX)
                    {
                        Q.push(val);
                        dist[val]=dist[node]+1;
                        parent[val]=node;
                    }
                }
            }

            //Path for the journey
            T temp=dest;
            while(parent[temp]!=temp)
            {
                cout<<temp<<"<--";
                temp=parent[temp];
            }
            cout<<temp<<endl;
            return dist[dest];
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
        ll board[50]={0};
        board[2]=13;
        board[5]=2;
        board[9]=18;
        board[18]=11;
        board[17]=-13;
        board[20]=-14;
        board[24]=-8;
        board[25]=10;
        board[32]=-2;
        board[34]=-22;

        Graph<ll> g;
        for(ll i=0;i<36;i++)
        {
            for(ll j=1;j<=6;j++)
            {
                ll pos=i+j+board[i+j];
                if(pos>36)
                    continue;
                g.add_edge(i,pos);
            }
        }
        g.add_edge(36,36);
        cout<<g.BFS(0,36);

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