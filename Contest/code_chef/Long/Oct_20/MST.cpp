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

// class DSU
// {
//     ll V;
//     ll *parent,*rank;
//     public:
//         DSU(ll v)
//         {
//             V=v;
//             parent=new ll[V];
//             rank=new ll[V];

//             for(ll i=0;i<V;i++)
//             {
//                 parent[i]=-1;
//                 rank[i]=1;
//             }
//         }

//         ll find(ll i)
//         {
//             if(parent[i]==-1)
//                 return i;
            
//             return parent[i]=find(parent[i]);
//         }

//         bool unite(ll x,ll y)
//         {
//             ll s1=find(x);
//             ll s2=find(y);

//             if(s1!=s2)
//             {
//                 if(rank[s1]<rank[s2])
//                 {
//                     parent[s1]=s2;
//                 }
//                 else
//                 {
//                     parent[s2]=s1;
//                 }
//                 return true;
//             }
//             return false;
//         }

// };

// class Graph
// {
//     ll V;
//     vector<vector<ll>> l;
//     public:
//         Graph(ll V)
//         {
//             this->V=V;
//         }
//         // presentation in edge list l is -> weight , e1, e2.
//         // this is b/c in future we need to sort the edge list according to the weight and we can easily sort it in this representation.
//         // as sort function sort the list w.r.t the value in first index 
//         void add_edge(ll x,ll y,ll w)
//         {
//             l.pb({w,x,y});
//         }

//         ll krushkal()
//         {
//             sort(l.begin(),l.end());

//             DSU s(V);

//             ll ans=0;
//             for(auto edge:l)
//             {
//                 ll x,y,w;
//                 x=edge[1];
//                 y=edge[2];
//                 w=edge[0];
//         // and if the cycle is not present then we can simply add that weight
//                 if(s.unite(x,y))
//                     ans+=w;

//             }
//             return ans;
//         }
// };

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
            // we have used priority queue such that we can get the next minimuma available edge in log(N) time
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
            bool *visited=new bool[V]{false};
            ll ans=0,cnt=0;
            
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
                cnt++;

                if(cnt==V-1)
                    break;
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
        ll n,d,i,j;
        cin>>n>>d;
        ll a[n][d];
        fo(i,n)
        {
            fo(j,d)
            {
                cin>>a[i][j];
            }
        }
        set<ll> s;
        for(i=0;i+1<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                ll w=0;
                for(ll k=0;k<d;k++)
                    w+=abs(a[i][k]-a[j][k]);
                s.insert(-w);
            }
        }
        ll sm=0,cnt=0;
        auto it=s.begin();
        while(cnt<n-1)
        {
            sm-=*it;
            cnt++;
            it++;
        }
        cout<<sm<<endl;

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