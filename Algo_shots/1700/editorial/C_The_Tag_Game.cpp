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

class Graph{
    ll V;
    list<ll> *l;
    // vector<vi> *l;
    ll root,other;
    public:
        Graph(ll V,ll node)
        {
            this->V=V;
            l=new list<ll>[V];
            root=0;
            other=node-1;
        }

        void add_edge(ll x,ll y)
        {
            l[x].pb(y);
            l[y].pb(x);
        }

        void dfs_helper(ll cur,bool visited[],ll arr[],ll len)
        {
            visited[cur]=true;

            arr[cur]=len;

            for(auto nbr:l[cur])
            {
                if(visited[nbr])
                    continue;
                dfs_helper(nbr,visited,arr,len+1);
            }
        }

        void dfs(ll arr[],ll st)
        {
            bool visited[V]={false};
            dfs_helper(st,visited,arr,0);
        }

        void solve()
        {
            ll arr1[V],arr2[V];
            dfs(arr1,root);
            dfs(arr2,other);
            ll i;
            fo(i,V)
                cout<<arr1[i]<<" ";
            cout<<endl;
            fo(i,V)
                cout<<arr2[i]<<" ";
            cout<<endl;

            ll ans=0;
            fo(i,V)
            {
                if(arr1[i]>arr2[i])
                {
                    ans=max(ans,2*arr1[i]);
                }
            }
            cout<<ans<<endl;
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
        ll n,i,node;
        cin>>n>>node;
        Graph g(n,node);

        fo(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            g.add_edge(x-1,y-1);
        }
        // cout<<"solve"<<endl;
        g.solve();


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