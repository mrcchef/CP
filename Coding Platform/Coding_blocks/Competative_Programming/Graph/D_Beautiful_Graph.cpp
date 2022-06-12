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
const ll mod = 998244353;

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
    ll root,even,odd,possible,ans;
    public:
        Graph(ll V)
        {
            this->V=V;
            l=new list<ll>[V+1];
            root=0;
            ans=1;
        }

        void add_edge(ll x,ll y)
        {
            l[x].pb(y);
            l[y].pb(x);
        }

        void dfs_helper(ll cur,ll visited[],ll pairity)
        {
            visited[cur]=pairity;
            if(pairity==1)
            {
                even++;
                // visited[cur]=1;
            }
            else
            {
                odd++;
            }
            

            for(auto nbr:l[cur])
            {
                // deb(visited[nbr]);
                if(visited[nbr]==1 || visited[nbr]==-1)
                {
                    if(pairity==visited[nbr])
                    {
                        // cout<<"Here"<<endl;
                        possible=0;
                        return;
                    }
                    continue;
                }
                dfs_helper(nbr,visited,pairity*-1);
            }
        }

        ll dfs()
        {
            ll visited[V+1];
            for(ll i=1;i<=V;i++)
                visited[i]=0;
            
            for(ll i=1;i<=V;i++)
            {
                if(visited[i]!=0)
                    continue;
                even=0,odd=0,possible=1;
                dfs_helper(i,visited,1);
                if(possible==0)
                    ans=0;
                // deb(possible);
                // cout<<i<<endl;
                // deb(even);
                // deb(odd);
                ans=(ans*(fxp(2,even,mod)+fxp(2,odd,mod)))%mod;
                // deb(ans);
                // ans%=mod;   
            }
            return ans;
        }

};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,i;
        cin>>n>>m;
        Graph g(n);
        fo(i,m)
        {
            ll x,y;
            cin>>x>>y;
            g.add_edge(x,y);
        }

        ll ans=g.dfs();
        // if(ans==1)
        //     ans=0;
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