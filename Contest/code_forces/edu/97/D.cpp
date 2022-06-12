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

class graph
{
    ll V;
    list<ll> *l;
    public:
        graph(ll V)
        {
            this->V=V;
            l=new list<ll>[V+1];
        }

        void add_edge(ll x,ll y)
        {
            l[x].pb(y);
            l[y].pb(x);
            // cout<<x<<" "<<y<<endl;
        }

        ll dfs_helper(ll src,ll visited[],ll cnt)
        {
            visited[src]=1;
            // cout<<src<<"-->";
            for(auto nbr:l[src])
            {
                if(visited[nbr]==0)
                {
                    return dfs_helper(nbr,visited,cnt+1);
                }
            }

            return cnt+1;
        }

        ll DFS()
        {
            ll visited[V+1]={0};

            ll ans=0;
            visited[1]=1;
            for(auto node:l[1])
            {
                if(visited[node]==0)
                {
                    ans=max(ans,dfs_helper(node,visited,0));
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
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vi v;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        // ll vi/sited[n+1]={0};
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        graph g(n);
        queue<ll> Q;
        Q.push(1);
        i=1;
        while(!Q.empty())
        {
            ll node=Q.front();
            Q.pop();
            for(i;i<n;i++)
            {
                if(i+1<n)
                {
                    if(v[i]<v[i+1])
                    {
                        g.add_edge(node,v[i]);
                        Q.push(v[i]);
                    }
                    else
                    {
                        g.add_edge(node,v[i]);
                        Q.push(v[i]);
                        break;
                    }
                }
                else
                {
                    g.add_edge(node,v[i]);
                    Q.push(v[i]);
                }
            }
            i++;
        }
        ll ans=g.DFS();
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