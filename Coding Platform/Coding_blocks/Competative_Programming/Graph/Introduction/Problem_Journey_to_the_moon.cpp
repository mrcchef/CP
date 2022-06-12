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
            l[y].pb(x);
        }

        void dfs_helper(T src,map<T,bool> &visited,ll &len)
        {
            len++;
            visited[src]=true;
            for(auto node:l[src])
            {
                if(!visited[node])
                {
                    dfs_helper(node,visited,len);
                }
            }
        }

        vi DFS()
        {
            map<T,bool> visited;

            for(auto p:l)
            {
                visited[p.first]=false;
            }

            vi v;
            
            for(auto p:l)
            {
                ll node=p.first;
                if(!visited[node])
                {
                    ll len=0;
                    dfs_helper(node,visited,len);
                    v.pb(len);
                }
            }
            return v;
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
        ll n,i,e,cnt=0;
        cin>>n>>e;
        vi v;
        ll arr[n]={0};

        fo(i,e)
        {
            ll x,y;
            cin>>x>>y;
            if(arr[x]==0)
                cnt++;
            if(arr[y]==0)
                cnt++;
            arr[x]=arr[y]=1;
            g.add_edge(x,y);
        }
        v=g.DFS();
        cnt=n-cnt;
        ll res1=1,res2=0;
        if(v.size()==1)
            res1=0;
        for(auto val:v)
        {
            res1*=val;
            res2+=val*cnt;
        }
        ll ans=res1+res2+(cnt*(cnt-1))/2;
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