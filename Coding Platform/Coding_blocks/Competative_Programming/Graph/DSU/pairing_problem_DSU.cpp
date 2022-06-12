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

// Optimisation 1 --> path compression optimisation 

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
            return parent[i]=find_set(parent[i],parent);
        }

        bool union_set(ll i,ll j,ll parent[],ll rank[])
        {
            ll s1=find_set(i,parent);
            ll s2=find_set(j,parent);

            if(s1!=s2)
            { 
                if(rank[i]<rank[j])
                {
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
                else
                {
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
                return true;
            }
            else
            {
                return false;
            }
        }

        ll solve()
        {
            ll ans=0;
            ll *parent=new ll[V];
            ll *rank=new ll[V];
            for(ll i=0;i<V;i++)
            {
                parent[i]=-1;
                rank[i]=1;
            }

            for(auto p:l)
            {
                ll v1=p.first;
                ll v2=p.second;

                union_set(v1,v2,parent,rank);
            }

            for(ll i=0;i<V;i++)
            {
                ll sp=find_set(i,parent);
                ans+=V-rank[sp];
            }

            // for(ll i=0;i<V;i++)
            //     cout<<parent[i]<<" ";
            // cout<<endl;

            // for(ll i=0;i<V;i++)
            //     cout<<rank[i]<<" ";
            // cout<<endl;

            delete [] parent;
            delete [] rank;
            return ans/2;
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
        cout<<ans<<endl;


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